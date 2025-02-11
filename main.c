
//#include <stdio.h>
//
//int main(void)
//{
//#ifdef __STDC_VERSION__
//    printf("Usando estándar de C: %ld\n", __STDC_VERSION__);
//#else
//    printf("Usando C89/C90 (no hay __STDC_VERSION__)\n");
//#endif
//    return 0;
//}
#include <stdarg.h>
#include <stdio.h>
#include "./ft_printf.h"
// void functionn(char *str, ...)
// {
//     va_list arg;
//     char *strings;
//     int i;
//
//     i = 0;
//     va_start(arg, str);
//     while(str[i])
//     {
//         strings = va_arg(arg, char *);    
//         printf("str: %s",strings);
//         i++;
//     } 
//     va_end(arg);
// }

int main(void)
{
    int count;
    char *str = "3333";
	char	c = 0;
    count = printf("%c", c);
	printf("%d\n", count);	
    count = printf("%c", c);
	printf("%d\n", count);
	count = ft_printf("%c", c);	
	ft_printf("%d\n", count);	
 //    ft_printf("[%+08d]\n", 42);
 //    printf("[%+08d]\n", 42);
 //    
	// printf("\nTest2\n");
 //    ft_printf("[%+0.8d]\n", 42);
 //    printf("[%+0.8d]\n", 42);
 //    
	// printf("\nTest3\n");
 //    ft_printf("[%5.8d]\n", 42);
 //    printf("[%5.8d]\n", 42);
 //    
	// printf("\nTest4\n");
 //    ft_printf("[%-07.9d]\n", 42);
 //    printf("[%-07.9d]\n", 42);
 //    
	// printf("\nTest5\n");
 //    ft_printf("[%+08d]\n", 42);
 //    printf("[%+08d]\n", 42);
 //    
	// printf("\nTest6\n");
 //    ft_printf("[%+08d]\n", 42);
 //    printf("[%+08d]\n", 42);
 //    
	// printf("\nTest7\n");
 //    ft_printf("[%+08d]\n", 42);
 //    printf("[%+08d]\n", 42);
    return (0);
}
