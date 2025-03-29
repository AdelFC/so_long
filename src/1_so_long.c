/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/29 01:09:17 by afodil-c         ###   ########.fr       */
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

	// Parsing et vérification de la map
	if (parse_map(argv[1], &data) == ERROR)
		return (ERROR);

	// Initialisation de MLX et création de la fenêtre
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_print_error("Error: Failed to initialize MLX\n");
		free_map(data.map);
		return (ERROR);
	}

	data.win = mlx_new_window(data.mlx,
		data.map_width * 64, data.map_length * 64, "so_long");

	if (!data.win)
	{
		ft_print_error("Error: Failed to create window\n");
		free_map(data.map);
		return (ERROR);
	}

	// Chargement des textures et affichage de la map
	load_textures(&data);
	render_game(&data);

	// Hook pour fermer la fenêtre (croix)
	mlx_hook(data.win, 17, 0, close_game, &data);

	// Boucle MLX
	mlx_loop(data.mlx);

	return (SUCCESS);
}
