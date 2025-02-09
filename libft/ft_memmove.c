/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:18:45 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:18:47 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*
*		The memmove() function copies n bytes from memory area src to
*		memory area dest.  The memory areas may overlap: copying takes
*		place as though the bytes in src are first copied into a
*		temporary array that does not overlap src or dest, and the bytes
*		are then copied from the temporary array to dest.
*
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_src;
	char		*tmp_dst;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	tmp_src = (char *) src;
	tmp_dst = (char *) dst;
	i = -1;
	if (tmp_dst > tmp_src)
	{
		while (len-- > 0)
			tmp_dst[len] = tmp_src[len];
	}
	else
	{
		while (++i < len)
			tmp_dst[i] = tmp_src[i];
	}
	return (dst);
}
