/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ber_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:18:17 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/20 16:47:04 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_ber_extension(char *filename)
{
    int len;
    if (!filename || *filename == '\0')
    {
        ft_print_error("Error: Filename is null or empty");
        return (-1);
    }
    len = ft_strlen(filename);
    if (len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
    {
        ft_print_error("Error: Invalid file extension. Expected '.ber'");
        return (-1);
    }
    return (0);
}

char    **read_map_file(char *filename)
{
    int     fd;
    char    *line;
    char    **map;
    int     i;
    int     maxlines;

    maxlines = 999;
    if (check_ber_extension(filename) != 0)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_print_error("Error: Failed to open the file");
        return (NULL);
    }
    map = ft_calloc(maxlines + 1, sizeof(char *));
    if (!map)
    {
        ft_print_error("Error: Memory allocation failed");
        close(fd);
        return (NULL);
    }
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (i >= maxlines)
        {
            ft_print_error("Error: Map exceeds maximum allowed lines");
            free(line);
            break;
        }
        map[i++] = line;
    }
    close(fd);
    return (map);
}

