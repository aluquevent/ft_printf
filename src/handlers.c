/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:26:17 by aluque-v          #+#    #+#             */
/*   Updated: 2025/03/03 12:28:10 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_char(int arg)
{
	char	c;

	c = arg;
	return (write(1, &c, 1));
}

int	handle_string(char *str)
{
	size_t	len;
	int		result;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	result = write(1, str, len);
	return (result);
}

int	handle_decimal(int n)
{
	char	*str;
	size_t	len;
	int		result;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	result = write(1, str, len);
	free(str);
	return (result);
}

int	handle_pointer(void *ptr)
{
	unsigned long	num;
	char			*str;
	size_t			len;
	int				result;
	char			*tmp;

	num = (unsigned long)ptr;
	if (num == 0)
		return (write(1, "(nil)", 5));
	tmp = ft_itoa_base(num, "0123456789abcdef");
	if (!tmp)
		return (-1);
	str = ft_strjoin("0x", tmp);
	if (!str)
		return (-1);
	free(tmp);
	len = ft_strlen(str);
	result = write(1, str, len);
	free(str);
	return (result);
}

int	handle_hex(unsigned int n, bool upper)
{
	char	*str;
	size_t	len;
	int		result;

	if (upper)
		str = ft_itoa_base(n, "0123456789ABCDEF");
	else
		str = ft_itoa_base(n, "0123456789abcdef");
	if (!str)
		return (-1);
	len = ft_strlen(str);
	result = write(1, str, len);
	free(str);
	return (result);
}
