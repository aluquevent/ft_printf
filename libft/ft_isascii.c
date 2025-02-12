/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:14:37 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:14:42 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
* 
*		Checks whether c is a 7-bit unsigned char value that fits
*		into the ASCII character set.
*
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
