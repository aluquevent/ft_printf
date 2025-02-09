/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:04:11 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/09 19:18:44 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int print_padding(char pad_char, int padding)
{
    int i;

    i = 0;
    while (i < padding)
        i += write(1, &pad_char, 1);
    return (i);
}

int apply_formatting(char *str, t_format *info)
{
    int     total;
    int     len;
    int     padding;
    int     zero_pad;
    char    pad_char;

    len = ft_strlen(str);
    if (info->precision == 0 && str[0] == '0' && info->specifier != 'c' && info->specifier != 's')
        len = 0;
    zero_pad = 0;
    if (info->precision > len && info->specifier != 's' && info->specifier != 'c')
        zero_pad = info->precision - len;
    padding = 0;
    if (info->width > len + zero_pad)
        padding = info->width - (len + zero_pad);
    total = 0;
    pad_char = ' ';
    if (info->zero_pad == 1 && info->precision == -1 && info->left_align == 0 && info->specifier != 's' && info->specifier != 'c')
        pad_char = '0';
    if (info->left_align == 0)
        total += print_padding(pad_char, padding);
    total += print_padding('0', zero_pad);
    if (len > 0)
        total += write(1, str, len);
    if (info->left_align == 1)
        total += print_padding(' ', padding);
    return (total);
}

