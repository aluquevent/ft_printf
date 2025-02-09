/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:19:59 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 17:20:04 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*
*		Allocates with malloc() and returns an array of string obtained
*		by splitting 's' using the character 'c'.
*
*/

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_numchar(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	return (count);
}

static char	**ft_free_matrix(const char *matrix, size_t len)
{
	while (len--)
		free((void *)&matrix[len]);
	free((void *)matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	words;
	size_t	sl;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (!matrix)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		sl = ft_numchar((const char *)s, c);
		matrix[i] = (char *)malloc(sizeof(char) * sl + 1);
		if (!matrix[i])
			return (ft_free_matrix((const char *)matrix, words));
		ft_strlcpy(matrix[i], s, sl + 1);
		s = ft_strchr(s, (int)c);
	}
	matrix[i] = 0;
	return (matrix);
}
