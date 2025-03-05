/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:15:52 by aluque-v          #+#    #+#             */
/*   Updated: 2025/03/03 13:19:26 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_unsigned(unsigned int n)
{
	char	*str;
	size_t	len;
	int		result;

	str = ft_uitoa(n);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	result = write(1, str, len);
	free(str);
	return (result);
}
