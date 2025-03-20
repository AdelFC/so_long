/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:43:00 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/20 15:59:55 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ftprintf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_img
{
    void    *img;
    int     width;
    int     height;
}   t_img;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    int     count_collectibles;
    int     count_collected;
    int     count_move;
    t_img   player;
    t_img   wall;
    t_img   floor;
    t_img   exit;
    t_img   collectible;
}   t_data;

/* so_long.c */
int     main(int argc, char **argv);

/* xpm_manager.c */
void    load_textures(t_data *data);
void    destroy_textures(t_data *data);

/* ber_manager.c */
int     check_ber_extension(char *filename);
char    **read_map_file(char *filename);

/* map_checker.c */
int     is_valid_map(t_data *data);
int     check_map_walls(t_data *data);
int     check_map_elements(t_data *data);
int     is_map_playable(t_data *data);
int     flood_fill(char **map, int x, int y, int *collectibles_left);

/* map_parser.c */
char    **parse_map(char *filename, int *width, int *height);
void    free_map(char **map);
int     get_map_height(char **map);
int     get_map_width(char **map);

/* keys_assignation.c */
int     handle_keypress(int keycode, t_data *data);
void    move_player(t_data *data, int dx, int dy);

/* hooks.c */
int     close_game(t_data *data);
int     render_game(t_data *data);

/* data.c */
void    start_game(t_data *data);
void    update_game_state(t_data *data);
void    check_win_condition(t_data *data);

/* exit.c */
void    free_game(t_data *data);
void    free_textures(t_data *data);
void    free_mlx(t_data *data);

/* utils */
void    ft_print_error(int code);

#endif
