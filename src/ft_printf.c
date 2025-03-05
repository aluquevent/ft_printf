/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:21:55 by aluque-v          #+#    #+#             */
/*   Updated: 2025/03/03 13:18:57 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static bool	is_valid(char c)
{
	const char	*set;

	set = "csidpuxX%";
	while (*set)
	{
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}

static bool	is_upper_hex(char c)
{
	if (c == 'X')
		return (true);
	return (false);
}

static int	handle_format(const char *fmt, va_list args)
{
	if (*fmt == 'c')
		return (handle_char(va_arg(args, int)));
	if (*fmt == 's')
		return (handle_string(va_arg(args, char *)));
	if (*fmt == 'i' || *fmt == 'd')
		return (handle_decimal(va_arg(args, int)));
	if (*fmt == 'p')
		return (handle_pointer(va_arg(args, void *)));
	if (*fmt == 'x' || *fmt == 'X')
	{
		return (handle_hex(va_arg(args, unsigned int), is_upper_hex(*fmt)));
	}
	if (*fmt == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	if (*fmt == '%')
		return (handle_char('%'));
	return (-1);
}

static int	parse_format(const char **fmt, va_list args)
{
	int	res;

	if (**fmt == '%')
	{
		(*fmt)++;
		if (is_valid(**fmt))
		{
			res = handle_format(*fmt, args);
			(*fmt)++;
		}
		else
			res = -1;
	}
	else
	{
		res = write(1, *fmt, 1);
		(*fmt)++;
	}
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	int		total;
	int		res;
	va_list	args;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	total = 0;
	while (*fmt)
	{
		res = parse_format(&fmt, args);
		if (res == -1)
		{
			va_end(args);
			return (-1);
		}
		total += res;
	}
	va_end(args);
	return (total);
}
