/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4c_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:55:33 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/03 20:59:44 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if ((i > 0 && map[i - 1][j] == 'F')
					|| (map[i + 1] && map[i + 1][j] == 'F')
					|| (j > 0 && map[i][j - 1] == 'F')
					|| (map[i][j + 1] && map[i][j + 1] == 'F'))
					return (SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (ERROR);
}

int	has_collectibles(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
