/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:12:34 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/23 17:12:43 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*
*	Locates the first occurrence in the string pointed to by <[find]> of
*	the sequence of limited to the <[n]> characters in the string
*	pointed to by <[str]>
*
*/

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*find)
		return ((char *)str);
	i = ft_strlen(find);
	while (ft_strncmp(&str[j], find, i) != 0)
	{
		if (!str[j] || j >= (len - i))
			return (NULL);
		++j;
	}
	if (i > len)
		return (NULL);
	return ((char *)(&str[j]));
}
