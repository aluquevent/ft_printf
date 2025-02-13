#include "libft.h"

char *ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = 1;
	num = n;
	while (num / 10)
	{
		len++;
		num /= 10;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
