/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:20:29 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/03 14:38:55 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_data *data)
{
	if (check_all_xpm() == ERROR)
	{
		free_map(data->map);
		exit(EXIT_FAILURE);
	}
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_print_error("Error: MLX init failed\n");
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, data->map_width * 64, data->map_length
			* 64, "so_long");
	if (!data->win)
	{
		free_mlx(data);
		exit(EXIT_FAILURE);
	}
	if (load_textures(data) == ERROR)
	{
		free_game(data);
		exit(EXIT_FAILURE);
	}
	render_game(data);
	mlx_loop_hook(data->mlx, &render_game, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, 17, 0, &close_game, data);
	mlx_loop(data->mlx);
}

void	update_game_state(t_data *data)
{
	data->count_move++;
	ft_printf("Moves: %d\n", data->count_move);
	render_game(data);
}
