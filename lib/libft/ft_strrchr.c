/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:31:46 by afodil-c          #+#    #+#             */
/*   Updated: 2024/12/02 11:05:11 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	un_c;
	char			*ptr;
	int				i;

	un_c = (unsigned char)c;
	ptr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == un_c)
			ptr = (char *)(s + i);
		i++;
	}
	if (!un_c)
		ptr = (char *)(s + i);
	return (ptr);
}
