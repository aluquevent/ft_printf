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

// static int print_negative_sign(char *str, t_format *info)
// {
// 	if (str[0] != '-')
// 		return (0);
// 	if (!info->zero_pad || info->precision >= 0)
// 		return (write(1, "-", 1));
// 	return (0);
// }
int print_formatted(char *str, t_format *info, int len, t_print_info *p_info)
{
    int total;
    char pad_char;

    total = 0;
    pad_char = get_pad_char(info);
    
    // Print left padding if not left-aligned and not zero-padded
    if (!info->left_align && pad_char == ' ')
        total += print_padding(' ', p_info->padding);
    
    // Handle negative sign
    if (str[0] == '-')
    {
        total += write(1, "-", 1);
        str++;
        len--;
    }
    
    // Print sign for positive numbers if requested
    if (p_info->sign_len)
        total += print_sign(info, p_info->sign_len);
    
    // Print zero padding from width if needed
    if (!info->left_align && pad_char == '0')
        total += print_padding('0', p_info->padding);
    
    // Print zero padding from precision
    total += print_padding('0', p_info->zero_pad);
    
    // Print the actual content
    if (len > 0)
        total += write(1, str, len);
    
    // Print right padding if left-aligned
    if (info->left_align)
        total += print_padding(' ', p_info->padding);
    
    return (total);
}



