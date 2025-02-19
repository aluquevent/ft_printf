
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void){
    int res1;
    int res2;
    res1 = ft_printf("%d", -5000);
    printf("\n");
    res2 = printf("%d", -5000);
    printf("\nMy result: %d || Original: %d\n", res1, res2);
    // ft_printf("%+.9d", -42);
    return 0;
}
// void test_basic_conversions(void)
// {
//     int ret1, ret2;
//     char *str = "Hello World";
//     char c = 'X';
//     void *ptr = (void *)0x12345678;
//
//     printf("\n=== BASIC CONVERSIONS TESTS ===\n");
//
//     // Test %c
//     printf("\n--- Testing %%c ---\n");
//     ret1 = printf("Original: [%c]\n", c);
//     ret2 = ft_printf("Custom  : [%c]\n", c);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test %s
//     printf("\n--- Testing %%s ---\n");
//     ret1 = printf("Original: [%s]\n", str);
//     ret2 = ft_printf("Custom  : [%s]\n", str);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//     
//     // Test NULL string
//     ret1 = printf("Original NULL: [%s]\n", (char *)NULL);
//     ret2 = ft_printf("Custom NULL : [%s]\n", (char *)NULL);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test %p
//     printf("\n--- Testing %%p ---\n");
//     ret1 = printf("Original: [%p]\n", ptr);
//     ret2 = ft_printf("Custom  : [%p]\n", ptr);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//     
//     // Test NULL pointer
//     ret1 = printf("Original NULL: [%p]\n", NULL);
//     ret2 = ft_printf("Custom NULL : [%p]\n", NULL);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test %%
//     printf("\n--- Testing %% ---\n");
//     ret1 = printf("Original: [%%]\n");
//     ret2 = ft_printf("Custom  : [%%]\n");
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
// }
//
// void test_numbers(void)
// {
//     int ret1, ret2;
//     
//     printf("\n=== NUMBER CONVERSION TESTS ===\n");
//
//     // Test %d and %i
//     printf("\n--- Testing %%d and %%i ---\n");
//     int numbers[] = {0, -42, 42, INT_MAX, INT_MIN, 2147483647, -2147483648};
//     for (size_t i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
//     {
//         ret1 = printf("Original %%d: [%d]\n", numbers[i]);
//         ret2 = ft_printf("Custom   %%d: [%d]\n", numbers[i]);
//         printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//         
//         ret1 = printf("Original %%i: [%i]\n", numbers[i]);
//         ret2 = ft_printf("Custom   %%i: [%i]\n", numbers[i]);
//         printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//     }
//
//     // Test %u
//     printf("\n--- Testing %%u ---\n");
//     unsigned int unums[] = {0, 42, UINT_MAX, 4294967295};
//     for (size_t i = 0; i < sizeof(unums)/sizeof(unums[0]); i++)
//     {
//         ret1 = printf("Original: [%u]\n", unums[i]);
//         ret2 = ft_printf("Custom  : [%u]\n", unums[i]);
//         printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//     }
//
//     // Test %x and %X
//     printf("\n--- Testing %%x and %%X ---\n");
//     int hex_nums[] = {0, 42, 255, 4096, INT_MAX, INT_MIN};
//     for (size_t i = 0; i < sizeof(hex_nums)/sizeof(hex_nums[0]); i++)
//     {
//         ret1 = printf("Original %%x: [%x]\n", hex_nums[i]);
//         ret2 = ft_printf("Custom   %%x: [%x]\n", hex_nums[i]);
//         printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//         
//         ret1 = printf("Original %%X: [%X]\n", hex_nums[i]);
//         ret2 = ft_printf("Custom   %%X: [%X]\n", hex_nums[i]);
//         printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//     }
// }
//
// void test_bonus_flags(void)
// {
//     int ret1, ret2;
//     
//     printf("\n=== BONUS FLAGS TESTS ===\n");
//
//     // Test width
//     printf("\n--- Testing Width ---\n");
//     ret1 = printf("Original: [%10d]\n", 42);
//     ret2 = ft_printf("Custom  : [%10d]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test precision
//     printf("\n--- Testing Precision ---\n");
//     ret1 = printf("Original: [%.5d]\n", 42);
//     ret2 = ft_printf("Custom  : [%.5d]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test minus flag (left-align)
//     printf("\n--- Testing Minus Flag ---\n");
//     ret1 = printf("Original: [%-10d]\n", 42);
//     ret2 = ft_printf("Custom  : [%-10d]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test zero flag
//     printf("\n--- Testing Zero Flag ---\n");
//     ret1 = printf("Original: [%010d]\n", 42);
//     ret2 = ft_printf("Custom  : [%010d]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test space flag
//     printf("\n--- Testing Space Flag ---\n");
//     ret1 = printf("Original: [% d]\n", 42);
//     ret2 = ft_printf("Custom  : [% d]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test plus flag
//     printf("\n--- Testing Plus Flag ---\n");
//     ret1 = printf("Original: [%+d]\n", 42);
//     ret2 = ft_printf("Custom  : [%+d]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test hash flag
//     printf("\n--- Testing Hash Flag ---\n");
//     ret1 = printf("Original: [%#x]\n", 42);
//     ret2 = ft_printf("Custom  : [%#x]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Test combined flags
//     printf("\n--- Testing Combined Flags ---\n");
//     ret1 = printf("Original: [%+10.5d]\n", 42);
//     ret2 = ft_printf("Custom  : [%+10.5d]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//     
//     ret1 = printf("Original: [%-#10x]\n", 42);
//     ret2 = ft_printf("Custom  : [%-#10x]\n", 42);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
// }
//
// void test_edge_cases(void)
// {
//     int ret1, ret2;
//     
//     printf("\n=== EDGE CASES TESTS ===\n");
//
//     // Empty string
//     printf("\n--- Testing Empty String ---\n");
//     ret1 = printf("Original: [%s]\n", "");
//     ret2 = ft_printf("Custom  : [%s]\n", "");
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Multiple consecutive %
//     printf("\n--- Testing Multiple %% ---\n");
//     ret1 = printf("Original: [%%%%]\n");
//     ret2 = ft_printf("Custom  : [%%%%]\n");
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Mixed conversions
//     printf("\n--- Testing Mixed Conversions ---\n");
//     ret1 = printf("Original: [%d %s %x %c %%]\n", 42, "test", 255, 'Z');
//     ret2 = ft_printf("Custom  : [%d %s %x %c %%]\n", 42, "test", 255, 'Z');
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
//
//     // Zero precision with zero value
//     printf("\n--- Testing Zero Precision with Zero ---\n");
//     ret1 = printf("Original: [%.0d]\n", 0);
//     ret2 = ft_printf("Custom  : [%.0d]\n", 0);
//     printf("Return values - Original: %d, Custom: %d\n", ret1, ret2);
// }
//
// int main(void)
// {
//     printf("=== STARTING FT_PRINTF TESTS ===\n");
//     
//     test_basic_conversions();
//     test_numbers();
//     test_bonus_flags();
//     test_edge_cases();
//     
//     printf("\n=== TESTS COMPLETED ===\n");
//     return (0);
// }
