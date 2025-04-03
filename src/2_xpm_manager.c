/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_xpm_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:17:22 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/03 13:26:12 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_xpm(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	close(fd);
	return (SUCCESS);
}

int	check_all_xpm(void)
{
	if (check_xpm("assets/PLAYER.xpm") == ERROR)
		return (ft_print_error("Error: PLAYER.xpm\n"), ERROR);
	if (check_xpm("assets/BRICK1.xpm") == ERROR)
		return (ft_print_error("Error: BRICK1.xpm\n"), ERROR);
	if (check_xpm("assets/FLOOR.xpm") == ERROR)
		return (ft_print_error("Error: FLOOR.xpm\n"), ERROR);
	if (check_xpm("assets/COLLECTIBLES1.xpm") == ERROR)
		return (ft_print_error("Error: COLLECTIBLES.xpm\n"), ERROR);
	if (check_xpm("assets/EXIT.xpm") == ERROR)
		return (ft_print_error("Error: EXIT.xpm\n"), ERROR);
	return (SUCCESS);
}

int	load_textures(t_data *data)
{
	data->player.img = mlx_xpm_file_to_image(data->mlx, "assets/PLAYER.xpm",
			&data->player.width, &data->player.height);
	if (!data->player.img)
		return (destroy_textures(data), ERROR);
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "assets/BRICK2.xpm",
			&data->wall.width, &data->wall.height);
	if (!data->wall.img)
		return (destroy_textures(data), ERROR);
	data->floor.img = mlx_xpm_file_to_image(data->mlx, "assets/FLOOR.xpm",
			&data->floor.width, &data->floor.height);
	if (!data->floor.img)
		return (destroy_textures(data), ERROR);
	data->collectible.img = mlx_xpm_file_to_image(data->mlx,
			"assets/COLLECTIBLES2.xpm", &data->collectible.width,
			&data->collectible.height);
	if (!data->collectible.img)
		return (destroy_textures(data), ERROR);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "assets/EXIT.xpm",
			&data->exit.width, &data->exit.height);
	if (!data->exit.img)
		return (destroy_textures(data), ERROR);
	return (SUCCESS);
}

void	destroy_textures(t_data *data)
{
	if (!data || !data->mlx)
		return ;
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
