/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/22 02:24:44 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    char **map;
    int i;

    if (argc != 2)
    {
        ft_print_error("Usage: ./so_long <map_file.ber>");
        return (ERROR);
    }
    map = read_map_file(argv[1]);
    
    if (!map)
        return (ERROR);
    i = 0;
    while (map[i])
    {
        ft_putstr_fd(map[i], 1);
        i++;
    }
    ft_free_map(map);
    return (0);
}