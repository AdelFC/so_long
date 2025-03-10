/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:29:36 by afodil-c          #+#    #+#             */
/*   Updated: 2025/01/14 19:24:26 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*psrc;
	char	*pdst;

	if (!dst && !src)
		return (0);
	psrc = (char *)src;
	pdst = (char *)dst;
	if (pdst > psrc)
		while (len-- > 0)
			pdst[len] = psrc[len];
	else
	{
		ft_memcpy(pdst, psrc, len);
	}
	return (dst);
}
