/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4b_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:10:18 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/02 11:37:52 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (SUCCESS);
	return (ERROR);
}

int	check_map_unwanted(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (ERROR);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valid_char(map[i][j]) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

char	**dup_map(t_data *data)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (data->map_length + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (data->map[i])
	{
		copy[i] = ft_strdup(data->map[i]);
		if (!copy[i])
		{
			while (i > 0)
			{
				free(copy[--i]);
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E')
		return ;
	map[y][x] = 'F';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

int	is_map_playable(t_data *data)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = dup_map(data);
	if (!map_copy)
		return (ERROR);
	flood_fill(map_copy, data->player_y, data->player_x);
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'C')
			{
				free_map(map_copy);
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	free_map(map_copy);
	return (SUCCESS);
}
