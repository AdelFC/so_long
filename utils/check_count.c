/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:43:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/04/03 13:44:07 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_count_valid(int count, int expected)
{
	if (expected == 0)
	{
		if (count < 1)
			return (ERROR);
		return (SUCCESS);
	}
	if (count != expected)
		return (ERROR);
	return (SUCCESS);
}
