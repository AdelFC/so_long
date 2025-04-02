/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5a_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:18:47 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/02 14:29:09 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(char *filename, t_data *data)
{
	char	**map;

	map = read_map_file(filename);
	if (map == NULL)
		return (ERROR);
	if (!map || !map[0] || map[0][0] != '1')
	{
		ft_print_error("Error: Map file is empty or incomplete.\n");
		free_map(map);
		return (ERROR);
	}
	data->map = map;
	data->map_length = get_map_length(map);
	data->map_width = get_map_width(map);
	data->count_collectibles = get_nb_collectibles(map);
	data->count_collected = 0;
	data->count_move = 0;
	if (init_player_position(data) == ERROR || is_valid_map(data) == ERROR
		|| is_map_big(map) == ERROR)
	{
		free_map(map);
		return (ERROR);
	}
	return (SUCCESS);
}

int	get_map_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_map_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	is_map_big(char **map)
{
	int	length;
	int	width;

	length = get_map_length(map);
	width = get_map_width(map);
	if (length > 100 || width > 100)
	{
		ft_print_error("Error: Map is too large. Maximum size is 100x100.\n");
		return (ERROR);
	}
	return (SUCCESS);
}
