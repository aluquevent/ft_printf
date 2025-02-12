/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:18:07 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:18:10 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*
*		The memchr() function scans the initial n bytes of the memory
*		area pointed to by s for the first instance of c.  Both c and the
*		bytes of the memory area pointed to by s are interpreted as
*		unsigned char.
*		
*		The memchr() and memrchr() functions return a pointer to the
*		matching byte or NULL if the character does not occur in the
*		given memory area.
*
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
