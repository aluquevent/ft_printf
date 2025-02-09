/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:02:11 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/09 19:09:13 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int handle_integer(t_format *info, va_list args)
{
    char    *num_str;
    int     total_len;
    int     n;

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

// int handle_unsigned(t_format *info, va_list args);

int handle_pointer(t_format *info, va_list args);
int handle_hex(t_format *info, va_list args);

