#include "../ft_printf.h"

char	get_pad_char(t_format *info)
{
	if (info->zero_pad && info->precision == -1 && !info->left_align)
		return ('0');
	return (' ');
}

static int	get_sign(t_format *info, char *str)
{
	if ((info->plus_sign || info->space_sign) && str[0] != '-'
		&& info->specifier != 'c' && info->specifier != 's')
		return (1);
	return (0);
}

static int	get_precision_len(t_format *info, char *str, int len)
{
	if (info->specifier == 'c')
		return (1);
	if (info->precision == 0 && str[0] == '0' && info->specifier != 's')
		return (0);
	if (info->precision > len && info->specifier != 's')
		return (info->precision - len);
	if (info->precision >= 0 && info->specifier == 's')
	{
		if (info->precision < len)
			return (info->precision);
		return (len);
	}
	return (len);
}

static int	get_zero_precision(t_format *info, int len)
{
	if (info->precision > len && info->specifier != 's' && info->specifier != 'c')
		return (len);
	return (0);
}

static int	get_padding(t_format *info, int zero_pad, int len, int sign_len)
{
	int	total_len;

	total_len = len + zero_pad + sign_len;
	if (info->hex_prefix)
		total_len += 2;
	if (info->width > total_len)
		return (info->width - total_len);
	return (0);
}

int apply_formatting(char *str, t_format *info)
{
    t_print_info	p_info;
    int			len;

    len = ft_strlen(str);
    p_info.sign_len = get_sign(info, str);
    len = get_precision_len(info, str, len);
    p_info.zero_pad = get_zero_precision(info, len);
    p_info.padding = get_padding(info, p_info.zero_pad, len, p_info.sign_len);
    return (print_formatted(str, info, len, &p_info));
}
