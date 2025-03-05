/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:57:45 by aluque-v          #+#    #+#             */
/*   Updated: 2025/03/03 13:19:21 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	get_sign(t_format *info, char *str)
{
	if ((info->plus_sign || info->space_sign) && str[0] != '-'
		&& (info->specifier == 'd' || info->specifier == 'i'))
		return (1);
	return (0);
}

static size_t	get_precision_len(t_format *info, size_t len)
{
	if (info->specifier == 'c')
		return (1);
	if (info->specifier == 's')
	{
		if (info->precision == 0)
			return (0);
		if (info->precision >= 0 && info->precision < (int)len)
			return (info->precision);
		return (len);
	}
	return (len);
}

static int	get_zero_precision(t_format *info, char *str)
{
	size_t	num_len;

	if (info->specifier == 's' || info->specifier == 'c')
		return (0);
	num_len = ft_strlen(str);
	if (str[0] == '-')
		num_len--;
	if (info->precision > (int)num_len)
		return (info->precision - num_len);
	return (0);
}

static size_t	get_padding(t_format *info, int zeros, size_t len, int sign)
{
	size_t	total_len;

	total_len = len + zeros + sign;
	if (info->hex_prefix)
		total_len += 2;
	if (info->width > total_len)
		return (info->width - total_len);
	return (0);
}

int	apply_formatting(char *str, t_format *info)
{
	t_p		p_info;
	size_t	len;

	len = ft_strlen(str);
	p_info.sign_len = get_sign(info, str);
	len = get_precision_len(info, len);
	p_info.zero_pad = get_zero_precision(info, str);
	p_info.padding = get_padding(info, p_info.zero_pad, len, p_info.sign_len);
	return (print_formatted(str, info, len, &p_info));
}
