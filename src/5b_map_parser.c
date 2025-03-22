/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5b_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:48:56 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/22 14:21:43 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_collectibles(char **map)
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
			if (map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	init_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				return (SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (ERROR);
}
