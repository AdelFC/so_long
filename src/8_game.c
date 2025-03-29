/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:20:29 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/29 17:59:14 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_print_error("Error: MLX init failed\n");
	data->win = mlx_new_window(data->mlx, data->map_width * 64, data->map_length
			* 64, "so_long");
	if (!data->win)
		ft_print_error("Error: Failed to create window\n");
	load_textures(data);
	render_game(data);
	mlx_loop_hook(data->mlx, &render_game, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &handle_keypress, data);
	mlx_hook(data->win, 17, 0, &close_game, data);
	mlx_loop(data->mlx);
}

void	update_game_state(t_data *data)
{
	data->count_move++;
	ft_printf("Moves: %d\n", data->count_move);
	render_game(data);
}
