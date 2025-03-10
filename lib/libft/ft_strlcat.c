/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:29:49 by afodil-c          #+#    #+#             */
/*   Updated: 2024/12/02 10:55:48 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	s1;
	size_t	s2;

	s1 = ft_strlen(src);
	s2 = ft_strlen(dst);
	if (s2 >= siz)
	{
		s2 = siz;
		return (s1 + siz);
	}
	if (s1 < (siz - s2))
		ft_memcpy(dst + s2, src, s1 + 1);
	else
	{
		ft_memcpy(dst + s2, src, siz - s2 - 1);
		dst[siz - 1] = 0;
	}
	return (s1 + s2);
}
