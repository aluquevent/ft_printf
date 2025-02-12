/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 formatters.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: aluque-v <aluque-v@student.42barcelona.co	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/09 19:04:11 by aluque-v		   #+#	  #+#			  */
/*	 Updated: 2025/02/09 19:18:44 by aluque-v		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	get_pad_char(t_format *info)
{
	if (info->zero_pad && info->precision == -1 && !info->left_align)
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
	int i;

	i = 0;
	while (i < padding)
		i += write(1, &pad_char, 1);
	return (i);
}

static int	get_sign(t_format *info, char *str)
{
	if ((info->plus_sign || info->space_sign) && str[0] != '-'
		&& info->specifier != 'c' && info->specifier != 's')
		return (1);
	return (0);
}

static int	get_precision_len(t_format *info, char *str, int len)
{
	if (info->specifier == 'c')
		return (1);
	if (info->precision == 0 && str[0] == '0' && info->specifier != 's')
		return (0);
	if (info->precision > len && info->specifier != 's')
		return (info->precision - len);
	if (info->precision < len && info->specifier == 's')
		return (info->precision);
	return (len);
}

static int	get_zero_precision(t_format *info, int len)
{
	if (info->precision > len && info->specifier != 's' && info->specifier != 'c')
		return (len);
	return (0);
}

static int	get_padding(t_format *info, int zero_pad, int len, int sign_len)
{
	if (info->width > len + zero_pad + sign_len)
		return (info->width - (len + zero_pad + sign_len));
	return (0);
}

// static char	*(char *prefix, char *str)
// {
// 	char	*new_str;
//
// 	new_str = ft_strjoin(prefix, str);
// 	if (!new_str)
// 		return (NULL);
// 	free(str);
// 	return (new_str);
// }

// static char *apply_hash(char *str, t_format *info)
// {
// 	if (info->hex_prefix && str[0] != 0 && info->specifier == 'x')
// 	{
// 		str = apply_prefix("0x", str);
// 		if (!str)
// 			return (0);	
// 	}
// 	else if (info->hex_prefix && str[0] !=0 && info->specifier == 'X')
// 	{
// 		str = apply_prefix("0X", str);
// 		if (!str)
// 			return (0);
// 	}
// 	return (str);
// }

int apply_formatting(char *str, t_format *info)
{
	int total;
	int len;
	int sign_len;
	int padding;
	int zero_pad;

	len = ft_strlen(str);
	sign_len = get_sign(info, str);
	len = get_precision_len(info, str, len);
	zero_pad = get_zero_precision(info, len);
	padding = get_padding(info, zero_pad, len, sign_len);
	total = 0;
	total += print_sign(info, sign_len);
	if (info->left_align == 0)
		total += print_padding(get_pad_char(info), padding);
	total += print_padding('0', zero_pad);
	if (len > 0)
		total += write(1, str, len);
	if (info->left_align == 1)
		total += print_padding(' ', padding);
	return (total);
}
