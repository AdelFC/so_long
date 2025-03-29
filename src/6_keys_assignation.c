/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_keys_assignation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:19:27 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/29 14:58:32 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(data, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(data, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(data, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(data, 1, 0);
	else if (keycode == KEY_ESC)
        close_game(data);
	return (0);
}

void	move_player(t_data *data, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + x;
	new_y = data->player_y + y;
	if (data->map[new_y][new_x] == '1')
		return ;
	if (data->map[new_y][new_x] == 'E' && data->count_collectibles > 0)
		return ;
	if (data->map[new_y][new_x] == 'C')
	{
		data->count_collectibles--;
		data->map[new_y][new_x] = '0';
	}
	data->map[data->player_y][data->player_x] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[new_y][new_x] = 'P';
    update_game_state(data);
}
