/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:45:26 by afodil-c          #+#    #+#             */
/*   Updated: 2024/12/05 08:12:25 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_base(unsigned long long nbr, char *base, int *value,
		char type)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base, value, type);
	ft_putchar(base[nbr % 16], value);
}

void	ft_printf_p(unsigned long long nbr, char *base, int *value, char type)
{
	if (nbr == 0)
	{
		ft_putstr("(nil)", value);
		return ;
	}
	ft_putstr("0x", value);
	ft_putnbr_base(nbr, base, value, type);
}
