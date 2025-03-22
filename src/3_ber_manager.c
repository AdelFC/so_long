/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ber_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:18:17 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/22 00:39:39 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_filename(char *filename)
{
    int len;
    if (!filename || *filename == '\0')
    {
        ft_print_error("Error: Filename is null or empty");
        return (ERROR);
    }
    len = ft_strlen(filename);
    if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
    {
        ft_print_error("Error: Invalid file extension. Expected '.ber'");
        return (ERROR);
    }
    return (SUCCESS);
}

char    **read_lines_from_fd(int fd)
{
    char    **map;
    char    *line;
    int     i;

    map = ft_calloc(MAX_LINES + 1, sizeof(char *));
    if (!map)
        return (NULL);
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (i >= MAX_LINES)
        {
            free(line);
            break ;
        }
        map[i++] = line;
    }
    return (map);
}

char    **read_map_file(char *filename)
{
    int     fd;
    char    **map;

    if (check_map_filename(filename) != 0)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_print_error("Error: Failed to open the file");
        return (NULL);
    }
    map = read_lines_from_fd(fd);
    close(fd);
    if (!map)
        ft_print_error("Error: Memory allocation failed");
    return (map);
}
