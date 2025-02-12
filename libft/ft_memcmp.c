/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:18:22 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:18:25 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**

		The ft_memcmp() function compares the first n bytes (each
		interpreted as unsigned char) of the memory areas s1 and s2.
		
		The ft_memcmp() function returns an integer less than, equal to, or
		greater than zero if the first n bytes of s1 is found,
		respectively, to be less than, to match, or be greater than the
		first n bytes of s2.

**/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
