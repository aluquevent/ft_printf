/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_printf.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: aluque-v <aluque-v@student.42barcelona.co	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/02/05 15:05:12 by aluque-v		   #+#	  #+#			  */
/*	 Updated: 2025/02/09 19:11:29 by aluque-v		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	check_format(char const **fmt, va_list args)
{
	t_format	info;

	info = (t_format){0, 0, 0, 0, 0, 0, -1, 0};
	(*fmt)++;
	parse_format(fmt, &info, args);
	if (info.specifier == 'd' || info.specifier == 'i')
		return (handle_integer(&info, args));
	else if (info.specifier == 'u')
	   return (handle_unsigned(&info, args));
	else if (info.specifier == 'c')
	   return (handle_char(&info, args));
	else if (info.specifier == 's')
		return (handle_string(&info, args));
	else if (info.specifier == 'x' || info.specifier == 'X')
	   return (handle_hex(&info, args));
	else if (info.specifier == 'p')
	   return (handle_pointer(&info, args));
	else if (info.specifier == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(char const *fmt, ...)
{
	int		res;
	int		total;
	va_list	args;

	total = 0;
	if (!fmt)
		return (-1);
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			res = check_format(&fmt, args);
		else
			res = write(1, fmt++, 1);
		total += res;
	}
	va_end(args);
	return (total);
}
