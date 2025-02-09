/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:12 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/05 15:26:04 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
int handle_char(char const **fmt, int c)
{

    return (res);
}

int handle_integer(char const **fmt, int n);
int handle_unsigned(char const **fmt, unsigned int n);
int handle_char(char const **fmt, int c);
int handle_string(char const **fmt, char *str);
int handle_pointer(char const **fmt, void *ptr);
int handle_hex(char const **fmt, unsigned int n);

int check_format(char const **fmt, va_list args)
{
    t_format    info;

    (*fmt)++;
    ft_parse_format(fmt, &info, args);
    ft_parse_width();
    ft_parse_prec();
    if (info.specifier == 'd' || info.specifier == 'i')
        return (handle_integer(fmt, va_arg(args, int)));
    else if (info.specifier == 'u')
        return (handle_unsigned(fmt, va_arg(args, unsigned int)));
    else if (info.specifier == 'c')
        return (handle_char(fmt, va_arg(args, int)));
    else if (info.specifier == 's')
        return (handle_string(fmt, va_arg(args, char *)));
    else if (info.specifier == 'x' || info.specifier == 'X')
        return (handle_hex(fmt, va_arg(args, unsigned long)));
    else if (info.specifier == 'p')
        return (handle_pointer(fmt, va_arg(args, void *)));
    else if (info.specifier == '%')
        return (handle_char(fmt, '%'));
    else
        return (-1);
}

void    ft_parse_format(char const **fmt, t_format *info, va_list args)
{
    *info = (t_format){0, 0, 0, 0, 0, 0, -1, 0};
    if (**fmt == 'c' || **fmt == 's' || **fmt == 'p' || **fmt == 'd' ||
        **fmt == 'i' || **fmt == 'u' || **fmt == 'x' || **fmt == 'X' || **fmt == '%')
        info->specifier = **fmt;
    (*fmt)++;
}

int ft_printf(char const *fmt, ...)
{
    int     res;
    int     total;
    va_list args;

    total = 0;
    if (!fmt)
        return (-1);
    va_start(args, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
            res = check_format(&fmt, args);
        else
            res = write(1, fmt++, 1);
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
