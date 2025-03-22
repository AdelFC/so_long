/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:43:00 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/22 12:18:50 by afodil-c         ###   ########.fr       */
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

#define SUCCESS 0
#define ERROR 1
#define MAX_LINES 999

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
    int     map_length;
    int     map_width;
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
// void    load_textures(t_data *data);
// void    destroy_textures(t_data *data);

/* ber_manager.c */
int     check_map_filename(char *filename);
char    **read_lines_from_fd(int fd);
char    **read_map_file(char *filename);

// /* map_checker.c */
int     is_valid_map(t_data *data);
int     check_map_walls(char **map);
int     is_rectangle(char **map);
int     check_map_elements(char **map, char find, int expected_count);
int     is_map_playable(t_data *data);
char    **dup_map(t_data *data);
void     flood_fill(char **map, int y, int x);

/* map_parser.c */
int     parse_map(char *filename, t_data *data);
int     get_map_length(char **map);
int     get_map_width(char **map);
int     get_nb_collectibles(char **map);
void    free_map(char **map);
int     init_player_position(t_data *data);

// /* keys_assignation.c */
// int     handle_keypress(int keycode, t_data *data);
// void    move_player(t_data *data, int dx, int dy);

// /* hooks.c */
// int     close_game(t_data *data);
// int     render_game(t_data *data);

// /* data.c */
// void    start_game(t_data *data);
// void    update_game_state(t_data *data);
// void    check_win_condition(t_data *data);

// /* exit.c */
// void    free_game(t_data *data);
// void    free_textures(t_data *data);
// void    free_mlx(t_data *data);

/* utils */
void	ft_print_error(char *message);

#endif
