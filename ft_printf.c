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

#include "./includes/ft_printf.h"
void    parse_flags(char const **fmt, t_format *info)
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

void    parse_width(char const **fmt, t_format *info, va_list args)
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

void    parse_precision(char const **fmt, t_format *info, va_list args)
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

char    *apply_precision(char *num_str, int precision)
{
    int len;
    char    *new_str;
    int i;
    int j;

    len = ft_strlen(num_str);
    new_str = malloc(precision + 1);
    if (!new_str)
        return (NULL);
    i = 0;
    while (i < (precision - len))
        new_str[i++] = '0';
    j = 0;
    while (num_str[j] != '\0')
        new_str[i++] = num_str[j++];
    new_str[i] = '\0';
    free(num_str);
    return (new_str);
}

int print_padding(char pad_char, int padding)
{
    int i;

    i = 0;
    while (i < padding)
        i += write(1, &pad_char, 1);
    return (i);
}

int apply_formatting(char *str, t_format *info)
{
    int     total_len;
    int     len;
    int     padding;
    char    pad_char;

    len = ft_strlen(str);
    if (info->precision >= 0 && len > info->precision)
        len = info->precision;
    padding = 0;
    if (info->width > 0 && info->width > len)
        padding = info->width - len;
    total_len = 0;
    pad_char = ' ';
    if (info->zero_pad == 1 && info->precision == -1 && info->left_align == 0)
        pad_char = '0';
    if (info->left_align == 0)
        total_len += print_padding(pad_char, padding);
    total_len += write(1, str, len);
    if (info->left_align == 1)
        total_len += print_padding(' ', padding);
    return (total_len);
}

int handle_integer(t_format *info, int n)
{
    char    *num_str;
    int     len;
    int     total_len;

    num_str = ft_itoa(n);
    if (!num_str)
        return (0);
    len = ft_strlen(num_str);
    if (info->precision > len)
        num_str = apply_precision(num_str, info->precision);
    else if(info->precision == 0 && n == 0)
        num_str[0] = '\0';
    total_len = apply_formatting(num_str, info);
    free(num_str);
    return (total_len);
}

int handle_unsigned(t_format *info, unsigned int n);
int handle_char(t_format *info, int c);
int handle_string(t_format *info, char *str)
{
    int     len;
    int     total_len;
    int     padding;
    char    *new_str;

    if (!str)
        return (write(1, "(null)", 6));
    len = ft_strlen(str);
    if (info->precision >=0 && len > info->precision)
        len = info->precision;
    new_str = malloc(len + 1);
    
}
int handle_pointer(t_format *info, void *ptr);
int handle_hex(t_format *info, unsigned int n);

int check_format(char const **fmt, va_list args)
{
    t_format    info;

    info = (t_format){0, 0, 0, 0, 0, 0, -1, 0};
    (*fmt)++;
    parse_format(fmt, &info, args);
    if (info.specifier == 'd' || info.specifier == 'i')
        return (handle_integer(&info, va_arg(args, int)));
    else if (info.specifier == 'u')
        return (handle_unsigned(&info, va_arg(args, unsigned int)));
    else if (info.specifier == 'c')
        return (handle_char(&info, va_arg(args, int)));
    else if (info.specifier == 's')
        return (handle_string(&info, va_arg(args, char *)));
    else if (info.specifier == 'x' || info.specifier == 'X')
        return (handle_hex(&info, va_arg(args, unsigned long)));
    else if (info.specifier == 'p')
        return (handle_pointer(&info, va_arg(args, void *)));
    else if (info.specifier == '%')
        return (handle_char(&info, '%'));
    else
        return (-1);
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
