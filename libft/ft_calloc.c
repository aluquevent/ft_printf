/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:12:36 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:13:34 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*
*		The calloc() function shall allocate unused space for an array of
*		nmemb elements each of whose size in bytes is <size>.  The space
*		shall be initialized to all bits 0.
*
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*mem;

	total_size = nmemb * size;
	if (total_size > 0 && nmemb != total_size / size)
		return (NULL);
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, total_size);
	return (mem);
}
