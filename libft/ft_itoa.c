/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:15:30 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/23 13:38:34 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*
*		Allocates with malloc() and returns a string representing
*		the integer recieved as an argument. Negative numbers must be handled.
*
*/

size_t	ft_get_digits(unsigned int n)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_memalloc(size_t len, size_t sign)
{
	if (sign == 0)
		return ((char *)malloc(sizeof(char) * (len + 1)));
	else
		return ((char *)malloc(sizeof(char) * (len + 2)));
}

unsigned int	ft_abs_value(int n)
{
	if (n < 0)
		return ((unsigned int)-n);
	else
		return ((unsigned int)n);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			digits;
	size_t			sign;
	unsigned int	abs_n;

	sign = 0;
	if (n < 0)
		sign = 1;
	abs_n = ft_abs_value(n);
	digits = ft_get_digits(abs_n);
	result = ft_memalloc(digits, sign);
	if (!result)
		return (NULL);
	result[digits + sign] = '\0';
	while (digits > 0)
	{
		result[--digits + sign] = (abs_n % 10) + '0';
		abs_n /= 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
