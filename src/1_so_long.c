/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/28 18:05:37 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc != 2)
	{
		ft_print_error("Usage: ./so_long <map_file.ber>\n");
		return (ERROR);
	}
	if (parse_map(argv[1], &data) == ERROR)
		return (ERROR);
	i = 0;
	while (data.map[i])
	{
		ft_putstr_fd(data.map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	free_map(data.map);
	return (SUCCESS);
}
