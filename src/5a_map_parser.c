/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5a_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:18:47 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/22 01:01:31 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int parse_map(char *filename, t_data *data)
{
    char    **map;

    map = read_map_file(filename);
    if (!map)
        return (ERROR);
    if (!is_valid_map(map))
    {
        free_map(map);
        return (ERROR);
    }
    data->map = map;
    data->map_length = get_map_length(map);
    data->map_width = get_map_width(map);
    data->count_collectibles = get_nb_collectibles(map);
    data->count_collected = 0;
    data->count_move = 0;
    if (!init_player_position(data))
    {
        free_map(map);
        return (ERROR);
    }
    return (SUCCESS);
}

int get_map_length(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

int get_map_width(char **map)
{
    int i;

    i = 0;
    while (map[0][i])
        i++;
    return (i);
}

void    free_map(char **map)
{
    int i;

    i = 0;
    if (!map)
        return;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}
