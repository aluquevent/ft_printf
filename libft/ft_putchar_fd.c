/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:19:08 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:19:10 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*
*		Outputs the character 'c' to the given file descriptor.
*
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
