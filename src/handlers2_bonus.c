/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:55:54 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/20 22:56:32 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	handle_char(t_format *info, va_list args)
{
	char	str[2];

	str[0] = (char)va_arg(args, int);
	str[1] = '\0';
	return (apply_formatting(str, info));
}

int	handle_string(t_format *info, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (apply_formatting("(null)", info));
	if (info->precision == 0)
		return (apply_formatting("", info));
	return (apply_formatting(str, info));
}

int	handle_unsigned(t_format *info, va_list args)
{
	char				*num_str;
	int					total_len;
	unsigned int		n;

	n = va_arg(args, unsigned int);
	if (info->precision == 0 && n == 0)
		return (apply_formatting("", info));
	num_str = ft_uitoa(n);
	if (!num_str)
		return (-1);
	total_len = apply_formatting(num_str, info);
	free(num_str);
	return (total_len);
}
