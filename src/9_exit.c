/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:20:48 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/29 17:38:57 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_data *data)
{
	free_textures(data);
	free_map(data->map);
	free_mlx(data);
}

void	free_textures(t_data *data)
{
	if (data->player.img)
		mlx_destroy_image(data->mlx, data->player.img);
	if (data->wall.img)
		mlx_destroy_image(data->mlx, data->wall.img);
	if (data->floor.img)
		mlx_destroy_image(data->mlx, data->floor.img);
	if (data->collectible.img)
		mlx_destroy_image(data->mlx, data->collectible.img);
	if (data->exit.img)
		mlx_destroy_image(data->mlx, data->exit.img);
}

void	free_mlx(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
