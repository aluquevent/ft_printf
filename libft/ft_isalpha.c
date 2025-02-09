/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:14:06 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:14:09 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*		Checks for an alphabetic character; in the standard "C"
*		locale, it is equivalent to (isupper(c) || islower(c)).
*       In some locales, there may be additional characters for
*		which isalpha() is true—letters which are neither
*       uppercase nor lowercase.
*/

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
