/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:03:35 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/20 23:08:41 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static char	get_pad_char(t_format *info)
{
	if (info->precision >= 0)
		return (' ');
	if (info->zero_pad && !info->left_align && info->specifier != 's'
		&& info->specifier != 'c')
		return ('0');
	return (' ');
}

static int	print_sign(t_format *info, int sign_len)
{
	if (sign_len)
	{
		if (info->plus_sign)
			return (write(1, "+", 1));
		if (info->space_sign)
			return (write(1, " ", 1));
	}
	return (0);
}

static int	print_padding(char pad_char, int padding)
{
	int	i;

	i = 0;
	while (i < padding)
		i += write(1, &pad_char, 1);
	return (i);
}

int	print_formatted(char *str, t_format *info, size_t new_len, t_p *p_info)
{
	int		total;
	char	pad_char;

	total = 0;
	pad_char = get_pad_char(info);
	if (!info->left_align && pad_char == ' ')
		total += print_padding(' ', p_info->padding);
	if (str[0] == '-')
	{
		total += write(1, "-", 1);
		str++;
		new_len--;
	}
	if (p_info->sign_len)
		total += print_sign(info, p_info->sign_len);
	if (!info->left_align && pad_char == '0' && info->precision < 0)
		total += print_padding('0', p_info->padding);
	total += print_padding('0', p_info->zero_pad);
	if (new_len > 0)
		total += write(1, str, new_len);
	if (info->left_align)
		total += print_padding(' ', p_info->padding);
	return (total);
}
