/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_xpm_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:17:22 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/01 09:27:53 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_data *data)
{
	data->player.img = mlx_xpm_file_to_image(data->mlx, "assets/PLAYER.xpm",
			&data->player.width, &data->player.height);
	if (!data->player.img)
		ft_print_error("Erreur: PLAYER.xpm\n");
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "assets/BRICK1.xpm",
			&data->wall.width, &data->wall.height);
	if (!data->wall.img)
		ft_print_error("Erreur: BRICK.xpm\n");
	data->floor.img = mlx_xpm_file_to_image(data->mlx, "assets/FLOOR.xpm",
			&data->floor.width, &data->floor.height);
	if (!data->floor.img)
		ft_print_error("Erreur: FLOOR.xpm\n");
	data->collectible.img = mlx_xpm_file_to_image(data->mlx,
			"assets/COLLECTIBLES1.xpm", &data->collectible.width,
			&data->collectible.height);
	if (!data->collectible.img)
		ft_print_error("Erreur: COLLECTIBLES.xpm\n");
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "assets/EXIT.xpm",
			&data->exit.width, &data->exit.height);
	if (!data->exit.img)
		ft_print_error("Erreur: EXIT.xpm\n");
	if (!data->exit.img || !data->collectible.img || !data->floor.img
		|| !data->wall.img || !data->player.img)
	{
		destroy_textures(data);
		return (ERROR);
	}
	return (SUCCESS);
}

void	destroy_textures(t_data *data)
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
