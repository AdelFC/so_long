/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/03 14:12:05 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_print_error("Usage: ./so_long map.ber\n"), ERROR);
	if (parse_map(argv[1], &data) == ERROR)
		return (ERROR);
	start_game(&data);
	return (SUCCESS);
}
