/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:15:10 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:15:14 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*
*		Checks for any printable character including space.
*
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
