#include "../ft_printf.h"

static int	print_sign(t_format *info, int sign_len)
{
	if (sign_len)
	{
		if (info->plus_sign)
			return (write(1, "+", 1));
		if (info->space_sign)
			return (write(1, " ", 1));
	}
	return (0);
}

static int	print_padding(char pad_char, int padding)
{
	int i;

	i = 0;
	while (i < padding)
		i += write(1, &pad_char, 1);
	return (i);
}

static int print_negative_sign(char *str, t_format *info)
{
	if (str[0] != '-')
		return (0);
	if (!info->zero_pad || info->precision >= 0)
		return (write(1, "-", 1));
	return (0);
}

static int print_content(char *str, int len)
{
	if (str[0] == '-')
	{
		str++;
		len--;
	}
	if (len > 0)
		return (write(1, str, len));
	return (0);
}

int print_formatted(char *str, t_format *info, int len, t_print_info *p_info)
{
    int total;

    total = 0;
    if (!info->left_align && get_pad_char(info) == ' ')
        total += print_padding(' ', p_info->padding);
    total += print_negative_sign(str, info);
    if (p_info->sign_len)
        total += print_sign(info, p_info->sign_len);
    if (!info->left_align && get_pad_char(info) == '0')
        total += print_padding('0', p_info->padding);
    if (str[0] == '-' && info->zero_pad && info->precision == -1)
        total += write(1, "-", 1);
    total += print_padding('0', p_info->zero_pad);
    total += print_content(str, len);
    if (info->left_align)
        total += print_padding(' ', p_info->padding);
    return (total);
}
