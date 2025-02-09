
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
    count = printf("%p", str);
    printf("\n%d", count);
    return (0);
}
