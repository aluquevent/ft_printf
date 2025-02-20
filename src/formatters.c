#include "../ft_printf.h"

char	get_pad_char(t_format *info)
{
	if (info->precision >=0)
		return (' ');
	if (info->zero_pad && !info->left_align && info->specifier != 's' && info->specifier != 'c')
		return ('0');
	return (' ');
}

static int	get_sign(t_format *info, char *str)
{
	if ((info->plus_sign || info->space_sign) && str[0] != '-'
		&& (info->specifier == 'd' || info->specifier == 'i'))
		return (1);
	return (0);
}

static size_t get_precision_len(t_format *info, size_t len)
{
    if (info->specifier == 'c')
        return (1);
    if (info->specifier == 's')
    {
		if (info->precision == 0)
	    	return (0);
        if (info->precision >= 0 && info->precision < (int)len)
            return (info->precision);
        return (len);
    }
    return (len);
}
static int get_zero_precision(t_format *info, char *str)
{
    size_t num_len;

    if (info->specifier == 's' || info->specifier == 'c')
		return (0);
    num_len = ft_strlen(str);
    if (str[0] == '-')
		num_len--;
    if (info->precision > (int)num_len)
		return (info->precision - num_len);
	// if (info->width > num_len)
	// 	return (info->width - num_len);
    return (0);
}
static size_t	get_padding(t_format *info, int zero_pad, size_t len, int sign_len)
{
	size_t	total_len;

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
    size_t			new_len;

    new_len = ft_strlen(str);
    p_info.sign_len = get_sign(info, str);
    new_len = get_precision_len(info, new_len);
    p_info.zero_pad = get_zero_precision(info, str);
    p_info.padding = get_padding(info, p_info.zero_pad, new_len, p_info.sign_len);
    
    // printf("Zero_padding (info): %d\n", info->zero_pad);
    // printf("Zero_padding (print len): %d\n", p_info.zero_pad);
    // printf("Precision Promtp: %d\n", info->precision);
    // printf("Precision value: %d\n", len);
    // printf("(width): %d\n", info->width);
    // printf("Padding (width): %d\n", p_info.padding);
    // printf("Sign_len:%d\n", p_info.sign_len);
    // printf("String:%s\n", str);

    // return (1); 
    return (print_formatted(str, info, new_len, &p_info));
}
