/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:29:43 by afodil-c          #+#    #+#             */
/*   Updated: 2024/12/02 10:50:48 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	un_c;
	int				i;

	un_c = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == un_c)
			return ((char *)(s + i));
		i++;
	}
	if (!un_c)
		return ((char *)(s + i));
	return (0);
}
