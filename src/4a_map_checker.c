/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4a_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:18:26 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/22 14:52:41 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_map(t_data *data)
{
	if (!data || !data->map || !is_rectangle(data->map))
		return (ERROR);
	if (!check_map_essentials(data->map))
		return (ERROR);
	if (!check_map_walls(data->map))
	{
		ft_print_error("Error: map is not surrounded by walls\n");
		return (ERROR);
	}
	if (!is_map_playable(data))
	{
		ft_print_error("Error: map not playable, \
			all elements must be accessible\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	check_map_elements(char **map, char find, int expected_count)
{
	int	i;
	int	j;
	int	count;

	if (!map)
		return (ERROR);
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == find)
				count++;
			j++;
		}
		i++;
	}
	if (expected_count == 0 && count >= 1)
		return (SUCCESS);
	if (count != expected_count)
		return (ERROR);
	return (SUCCESS);
}

int	check_map_essentials(char **map)
{
	if (!check_map_elements(map, 'P', 1))
	{
		ft_print_error("Error: there must be exactly one player\n");
		return (ERROR);
	}
	if (!check_map_elements(map, 'E', 1))
	{
		ft_print_error("Error: there must be exactly one exit\n");
		return (ERROR);
	}
	if (!check_map_elements(map, 'C', 0))
	{
		ft_print_error("Error: there must be at least one collectible\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	is_rectangle(char **map)
{
	int		i;
	size_t	width;

	if (!map)
		return (ERROR);
	width = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
		{
			ft_print_error("Error: map is not rectangular\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map_walls(char **map)
{
	int	i;
	int	j;
	int	width;
	int	length;

	if (!map)
		return (ERROR);
	width = get_map_width(map);
	length = get_map_length(map);
	j = 0;
	while (j < width)
	{
		if (map[0][j] != '1' || map[length - 1][j] != '1')
			return (ERROR);
		j++;
	}
	i = 0;
	while (i < length)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (ERROR);
		i++;
	}
	return (0);
}
