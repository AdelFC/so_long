/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/22 15:45:26 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_print_error("Usage: ./so_long <map_file.ber>\n");
		return (ERROR);
	}
	ft_putstr_fd("Parsing the map...\n", 1);
	if (parse_map(argv[1], &data) == ERROR)
	{
		ft_print_error("Error: Failed to parse the map.\n");
		return (ERROR);
	}
	ft_putstr_fd("Map parsed successfully!\n", 1);

	ft_putstr_fd("Verifying the map...\n", 1);
	if (!is_valid_map(&data))
	{
		ft_print_error("Error: Map verification failed.\n");
		free_map(data.map);
		return (ERROR);
	}
	ft_putstr_fd("Map verification successful!\n", 1);

	ft_putstr_fd("Displaying the map:\n", 1);
	for (int i = 0; data.map[i]; i++)
	{
		ft_putstr_fd(data.map[i], 1);
		ft_putchar_fd('\n', 1);
	}

	free_map(data.map);
	return (SUCCESS);
}
