/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:26:25 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/09 19:10:22 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_format
{
	int		left_align; // flag -
	int		zero_pad;  // flag 0
	int		plus_sign;  // flag +
	int		space_sign; // flag ' '
	int		hex_prefix; // flag #
	int		width;		// flag {NUM} (* for argument value).
	int		precision; // flag . -1 default (* for argument value).
	char	specifier;
}	t_format;

int		ft_printf(const char *fmt, ...);
void	parse_format(const char **fmt, t_format *info, va_list args);
int		handle_integer(t_format *info, va_list args);
int		handle_unsigned(t_format *info, va_list args);
int		handle_char(t_format *info, va_list args);
int		handle_string(t_format *info, va_list args);
int		handle_pointer(t_format *info, va_list args);
int		handle_hex(t_format *info, va_list args);
int		apply_formatting(char *str, t_format *info);
#endif
