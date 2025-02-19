#include "../ft_printf.h"

char	get_pad_char(t_format *info)
{
	if (info->zero_pad && !info->left_align)
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

static int get_precision_len(t_format *info, char *str, int len)
{
    int num_len;

    num_len = len;
    if (info->specifier == 'c')
        return (1);
    if (info->specifier == 's')
    {
	if (info->precision == 0)
	    return (0);
        if (info->precision >= 0 && info->precision < len)
            return (info->precision);
        return (len);
    }
    if (str[0] == '-')
        num_len--;
    if (info->precision > num_len)
        return (info->precision);
    return (len);
}
static int get_zero_precision(t_format *info, char *str)
{
    int num_len;

    if (info->specifier == 's' || info->specifier == 'c')
	return (0);
    num_len = ft_strlen(str);
    if (str[0] == '-')
	num_len--;
    if (info->precision > num_len)
	return (info->precision - num_len);
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
#include <stdio.h>
int apply_formatting(char *str, t_format *info)
{
    t_print_info	p_info;
    int			len;

    len = ft_strlen(str);
    p_info.sign_len = get_sign(info, str);
    len = get_precision_len(info, str, len);
    p_info.zero_pad = get_zero_precision(info, str);
    p_info.padding = get_padding(info, p_info.zero_pad, len, p_info.sign_len);
    
    // printf("Zero_padding (info): %d\n", info->zero_pad);
    // printf("Zero_padding (print len): %d\n", p_info.zero_pad);
    // printf("Precision Promtp: %d\n", info->precision);
    // printf("Precision value: %d\n", len);
    // printf("(width): %d\n", info->width);
    // printf("Padding (width): %d\n", p_info.padding);
    // printf("Sign_len:%d\n", p_info.sign_len);
    // printf("String:%s\n", str);

    // return (1); 
    return (print_formatted(str, info, len, &p_info));
}
