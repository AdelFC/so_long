/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:42:00 by afodil-c          #+#    #+#             */
/*   Updated: 2024/12/02 10:49:13 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] == c && s[i + 1] && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **psplit)
{
	int	word;

	word = 0;
	while (psplit[word])
	{
		free(psplit[word]);
		word++;
	}
	if (psplit)
		free(psplit);
}

static int	split_word(char **psplit, const char *s, char c, int word)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == c || s[end] == 0)
			start = end + 1;
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == 0))
		{
			psplit[word] = malloc(sizeof(char) * (end - start + 2));
			if (!(psplit[word]))
			{
				free_all(psplit);
				return (-1);
			}
			ft_strlcpy(psplit[word], s + start, end - start + 2);
			word++;
		}
		end++;
	}
	psplit[word] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**psplit;
	int		count;

	count = count_words(s, c);
	psplit = malloc(sizeof(char *) * (count + 1));
	if (!psplit)
		return (0);
	if (split_word(psplit, s, c, 0) == -1)
		return (0);
	return (psplit);
}
