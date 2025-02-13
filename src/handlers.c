/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 handlers.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: aluque-v <aluque-v@student.42barcelona.co	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/09 19:02:11 by aluque-v		   #+#	  #+#			  */
/*	 Updated: 2025/02/09 19:09:13 by aluque-v		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../ft_printf.h"

int handle_integer(t_format *info, va_list args)
{
	char	*num_str;
	int		total_len;
	int		n;

	n = va_arg(args, int);
	if (info->precision == 0 && n == 0)
		return (apply_formatting("", info));
	num_str = ft_itoa(n);
	if (!num_str)
		return (0);
	total_len = apply_formatting(num_str, info);
	free(num_str);
	return (total_len);
}

int handle_unsigned(t_format *info, va_list args)
{
	char				*num_str;
	int					total_len;
	unsigned int		n;

	n = va_arg(args, unsigned int);
	if (info->precision == 0 && n == 0)
		return (apply_formatting("", info));
	num_str = ft_uitoa(n);
	if (!num_str)
		return (0);
	total_len = apply_formatting(num_str, info);
	free(num_str);
	return (total_len);
}

int handle_pointer(t_format *info, va_list args)
{
	char			*hex_str;
	int				total_len;
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(args, void *);
	total_len = 0;
	if (!ptr)
	{
		hex_str = ft_strdup("0x0");
		if (!hex_str)
	  		return (0);
	}
	else
	{
		total_len += write(1, "0x", 2);
		hex_str = ft_itoa_base(ptr, "0123456789abcdef");
		if (!hex_str)
			return (0);
	}
	total_len += apply_formatting(hex_str, info);
	free(hex_str);
	return (total_len);
}

static char	*get_hex_case(unsigned int num, t_format *info)
{
	if (num == 0 && info->precision == 0)
		return (ft_strdup(""));
	else if (info->specifier == 'x')
		return (ft_itoa_base((unsigned long)num, "0123456789abcdef"));
	return (ft_itoa_base((unsigned long)num, "0123456789ABCDEF"));
}

int handle_hex(t_format *info, va_list args)
{
	char			*hex_str;
	int				total_len;
	unsigned int	num;
	
	num = va_arg(args, unsigned int);
	total_len = 0;
	if (info->hex_prefix && num != 0)
	{
		if (info->specifier == 'x')
			total_len += write(1, "0x", 2);
		if (info->specifier == 'X')
			total_len += write(1, "0X", 2);
	}
	hex_str = get_hex_case(num, info);
	if (!hex_str)
		return (0);
	total_len += apply_formatting(hex_str, info);
	free(hex_str);
	return (total_len);
}

