/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:19:18 by afodil-c          #+#    #+#             */
/*   Updated: 2024/12/04 11:19:18 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *value)
{
	write(1, &c, 1);
	(*value)++;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int *value)
{
	if (!str)
		return (ft_putstr("(null)", value));
	while (*str)
		ft_putchar(*str++, value);
}

void	ft_putnbr(int nb, int *value)
{
	if (nb == INT_MIN)
	{
		ft_putstr("-2147483648", value);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', value);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, value);
	ft_putchar((nb % 10) + '0', value);
}

void	ft_putnbr_unsigned(unsigned int nb, int *value)
{
	if (nb >= 10)
		ft_putnbr_unsigned(nb / 10, value);
	ft_putchar((nb % 10) + '0', value);
}
