/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:19:56 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/02 13:43:58 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *data)
{
	free_game(data);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}

void	render_tile(t_data *data, int i, int j)
{
	void	*img;

	if (!data || !data->map || !data->map[i])
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->floor.img, j * TILE_SIZE, i
		* TILE_SIZE);
	img = NULL;
	if (data->map[i][j] == '1' && data->wall.img)
		img = data->wall.img;
	else if (data->map[i][j] == 'C' && data->collectible.img)
		img = data->collectible.img;
	else if (data->map[i][j] == 'E' && data->exit.img)
		img = data->exit.img;
	else if (data->map[i][j] == 'P' && data->player.img)
		img = data->player.img;
	if (img)
		mlx_put_image_to_window(data->mlx, data->win, img, j * TILE_SIZE, i * TILE_SIZE);
}

int	render_game(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			render_tile(data, i, j);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
