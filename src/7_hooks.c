/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:19:56 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/29 14:59:13 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *data)
{
	destroy_textures(data);
	free_map(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	return (SUCCESS);
}

int	render_game(t_data *data)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->floor.img)
				mlx_put_image_to_window(data->mlx, data->win,
					data->floor.img, j * 64, i * 64);

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
				mlx_put_image_to_window(data->mlx, data->win, img, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
