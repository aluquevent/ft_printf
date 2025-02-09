/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:02:21 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/09 19:07:46 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void parse_flags(char const **fmt, t_format *info)
{
   while (**fmt == '-' || **fmt == '0' || **fmt == '+' ||
          **fmt == ' ' || **fmt == '#')
    {
        if (**fmt == '-')
            info->left_align = 1;
        else if (**fmt == '0')
            info->zero_pad = 1;
        else if (**fmt == '+')
            info->plus_sign = 1;
        else if (**fmt == ' ')
            info->space_sign = 1;
        else if (**fmt == '#')
            info->hex_preffix = 1;
        (*fmt)++;
    }
    if (info->left_align == 1)
        info->zero_pad = 0;
}

static void parse_width(char const **fmt, t_format *info, va_list args)
{
    int width;

    width = 0;
    if (**fmt == '*')
    {
        width = va_arg(args, int);
        if (width < 0)
        {
            info->left_align = 1;
            width = -width;
        }
        (*fmt)++;
    }
    while (**fmt >= '0' && **fmt <= '9')
    {
        width = (width * 10) + (**fmt - '0');
        (*fmt)++;
    }
    info->width = width;
}

static void parse_precision(char const **fmt, t_format *info, va_list args)
{
    int precision;

    if (**fmt != '.')
        return ;
    (*fmt)++;
    precision = 0;
    if (**fmt == '*')
    {
        precision = va_arg(args, int);
        if (precision < 0)
            precision = -1;
        (*fmt)++;
    }
    while (**fmt >= '0' && **fmt <= '9')
    {
        precision = (precision * 10) + (**fmt - '0');
        (*fmt)++;
    }
    info->precision = precision;
}

void    parse_format(char const **fmt, t_format *info, va_list args)
{
    parse_flags(fmt, info);
    parse_width(fmt, info, args);
    parse_precision(fmt, info, args);
    if (**fmt == 'c' || **fmt == 's' || **fmt == 'p' || **fmt == 'd' ||
        **fmt == 'i' || **fmt == 'u' || **fmt == 'x' || **fmt == 'X' || **fmt == '%')
    {
        info->specifier = **fmt;
        (*fmt)++;
    }
    else
        info->specifier = '\0';
}
