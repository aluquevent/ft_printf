#include "../includes/ft_printf.h"

// int handle_char(t_format *info, va_list args)
// {
//     char    *str;
//     return (apply_formatting(str, info));
// }
int handle_string(t_format *info, va_list args)
{
    char    *str;

    str = va_arg(args, char *);
    if (!str)
        return (write(1, "(null)", 6));
    return (apply_formatting(str, info));
}
