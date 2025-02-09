/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:20:23 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:20:25 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*
*		The strdup() function returns a pointer to a new string which is
*		a duplicate of the string s.  Memory for the new string is
*		obtained with malloc(3), and can be freed with free(3).
*
*/

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		i;

	if (!s1)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
