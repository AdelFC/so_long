/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:38:45 by afodil-c          #+#    #+#             */
/*   Updated: 2024/12/04 13:08:54 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_printf_args(char c, va_list args, int *value);
void	ft_putchar(char c, int *value);
void	ft_putstr(char *str, int *value);
void	ft_putnbr(int nb, int *value);
void	ft_putnbr_unsigned(unsigned int nb, int *value);
void	ft_putnbr_base(unsigned long long nbr, char *base, int *value,
			char type);
void	ft_printf_p(unsigned long long nbr, char *base, int *value,
			char type);
#endif
