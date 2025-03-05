/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:20:15 by aluque-v          #+#    #+#             */
/*   Updated: 2025/03/03 13:17:35 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include "./libft/libft.h"

int	handle_char(int c);
int	handle_string(char *str);
int	handle_decimal(int n);
int	handle_pointer(void *ptr);
int	handle_unsigned(unsigned int n);
int	handle_hex(unsigned int n, bool x);
int	ft_printf(const char *fmt, ...);

#endif
