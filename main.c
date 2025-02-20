#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void){
    int res1, res2;

    ft_printf("\n=================[ BASIC CONVERSIONS ]=================\n");
    ft_printf("\n\n+++++++++++++++++[ DECIMALS: %%d ]++++++++++++++++\n\n");
    
	ft_printf("### Test case: ft_printf('[This is a number %%d]', 0)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %d]\n", 0);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %d]\n", 0);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[This is a number %%d]', -1)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %d]\n", -1);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %d]\n", -1);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[This is a number %%d]', 16)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %d]\n", 16);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %d]\n", 16);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[This is a number %%d]', INT_MIN)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %d]\n", INT_MIN);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %d]\n", INT_MIN);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[This is a number %%d]', INT_MAX)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %d]\n", INT_MAX);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %d]\n", INT_MAX);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ INTEGERS: %%i ]++++++++++++++++\n\n");

	ft_printf("### Test case: ft_printf('[This is a number %%i]', 0)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %i]\n", 0);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %i]\n", 0);
    ft_printf("▶ Return value:  mine = %i | printf = %i\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[This is a number %%i]', -1)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %i]\n", -1);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %i]\n", -1);
    ft_printf("▶ Return value:  mine = %i | printf = %i\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[This is a number %%i]', 16)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %i]\n", 16);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %i]\n", 16);
    ft_printf("▶ Return value:  mine = %i | printf = %i\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[This is a number %%i]', INT_MIN)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %i]\n", INT_MIN);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %i]\n", INT_MIN);
    ft_printf("▶ Return value:  mine = %i | printf = %i\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[This is a number %%i]', INT_MAX)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[This is a number %i]\n", INT_MAX);
    ft_printf("▶ Printf output: ");
    res2 = printf("[This is a number %i]\n", INT_MAX);
    ft_printf("▶ Return value:  mine = %i | printf = %i\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ CHARACTERS: %%c ]++++++++++++++++\n\n");
  
	ft_printf("### Test case: ft_printf('[%%c]', '0')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%c]\n", '0');
    ft_printf("▶ Printf output: ");
    res2 = printf("[%c]\n", '0');
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%c]', '0' - 256)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%c]\n", '0' - 256);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%c]\n", '0' - 256);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%c]', '0' + 256)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%c]\n", '0' + 256);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%c]\n", '0' + 256);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%c %%c %%c]', '0', 1, '0')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%c %c %c]\n", '0', 1, '0');
    ft_printf("▶ Printf output: ");
    res2 = printf("[%c %c %c]\n", '0', 1, '0');
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ STRINGS: %%s ]++++++++++++++++\n\n");
  
	ft_printf("### Test case: ft_printf('[%%s]', '-')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%s]\n", "-");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%s]\n", "-");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%s]', '')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%s]\n", "");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%s]\n", "");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
	
	char *s1 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	ft_printf("### Test case: ft_printf([%%s]', s1)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%s]\n", s1);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%s]\n", s1);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%s]', NULL)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%s]\n", NULL);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%s]\n", NULL);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ POINTERS: %%p ]++++++++++++++++\n\n");
  
	ft_printf("### Test case: ft_printf('[%%p]', (void*)-1)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%p]\n", (void *)-1);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%p]\n", (void*)-1);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
  
	ft_printf("### Test case: ft_printf('[%%p]', -1)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%p]\n", -1);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%p]\n", -1);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
  
	ft_printf("### Test case: ft_printf('[%%p]', 15)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%p]\n", 15);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%p]\n", 15);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
  
	ft_printf("### Test case: ft_printf('[%%p %%p]', INT_MIN, INT_MAX)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%p %p]\n", INT_MIN, INT_MAX);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%p %p]\n", INT_MIN, INT_MAX);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%p %%p]', LONG_MIN, LONG_MAX)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%p %p]\n", LONG_MIN, LONG_MAX);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%p %p]\n", LONG_MIN, LONG_MAX);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%p]', NULL)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%p]\n", NULL);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%p]\n", NULL);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ HEXADECIMALS: %%x %%X ]++++++++++++++++\n\n");
  
	ft_printf("### Test case: ft_printf('[%%x %%X]', 0, 0)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%x %X]\n", 0, 0);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%x %X]\n", 0, 0);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
  
	ft_printf("### Test case: ft_printf('[%%x %%X]', -1, -1)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%x %X]\n", -1, -1);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%x %X]\n", -1, -1);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
  
	ft_printf("### Test case: ft_printf('[%%x %%X]', 56688, 56688)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%x %X]\n", 56688, 56688);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%x %X]\n", 56688, 56688);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
  
	ft_printf("### Test case: ft_printf('[%%x %%X %%x %%X]', INT_MIN, INT_MIN, INT_MAX, INT_MAX)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%x %X %x %X]\n", INT_MIN, INT_MIN, INT_MAX, INT_MAX);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%x %X %x %X]\n", INT_MIN, INT_MIN, INT_MAX, INT_MAX);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%x %%X %%x %%X]', LONG_MIN, LONG_MIN, LONG_MAX, LONG_MAX)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%x %X %x %X]\n", LONG_MIN, LONG_MIN, LONG_MAX, LONG_MAX);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%x %X %x %X]\n", LONG_MIN, LONG_MIN, LONG_MAX, LONG_MAX);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%x %%X]', NULL, NULL)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%x %X]\n", NULL, NULL);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%x %X]\n", NULL, NULL);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ PERCENT: %% ]++++++++++++++++\n\n");
  
	ft_printf("### Test case: ft_printf('[%%%%]')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%%]\n");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%%]\n");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
  
	ft_printf("### Test case: ft_printf('[%%%% %%%%]')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%% %%]\n");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%% %%]\n");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
  
	ft_printf("### Test case: ft_printf('[%%%%%%%%%%%%]')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%%%%%%]\n");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%%%%%%]\n");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
 
	ft_printf("\n\n+++++++++++++++++[ MIX ]++++++++++++++++\n\n");
  
	ft_printf("### Test case: ft_printf('[%%s %%c %%d %%i %%x %%X %%p %%]', 'Hola', 'a', 42, 24, 255, 255, 15)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%s %c %d %i %x %X %p %%]\n", "Hola", 'a', 42, 24, 255, 255, 15);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%s %c %d %i %x %X %p %%]\n", "Hola", 'a', 42, 24, 255, 255, 15);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
 
    ft_printf("\n=================[ BONUS PART ]=================\n");
    ft_printf("\n\n+++++++++++++++++[ FLAG: - ]++++++++++++++++\n\n");
    
	char *s2 = "This is a left aligned string.";
	ft_printf("### Test case: ft_printf('[%%-50s]', s2)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%-50s]\n", s2);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%-50s]\n", s2);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%-50d]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%-50d]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%-50d]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case(ignoring '0' flag): ft_printf('[%%-050d]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%-050d]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%-050d]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ FLAG: 0 ]++++++++++++++++\n\n");
    
	char *s3 = "This is a 0 padded string.";
	ft_printf("### Test case(undefined behaviour with strings): ft_printf('[%%050s]', s3)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%050s]\n", s3);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%050s]\n", s3);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%050d]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%050d]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%050d]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ FLAG: width ]++++++++++++++++\n\n");
 
	char *s4 = "This is a padded string with 50 min len.";
	ft_printf("### Test case: ft_printf('[%%50s]', s4)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%50s]\n", s4);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%50s]\n", s4);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%050d]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%50d]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%50d]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ FLAG: + ]++++++++++++++++\n\n");

	char *s5 = "This a string that wants to be a number (?).";
	ft_printf("### Test case: ft_printf('[%%+s]', s5)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%+s]\n", s5);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%+s]\n", s5);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%+d]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%+d]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%+d]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%+d]', -42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%+d]\n", -42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%+d]\n", -42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ FLAG: ' ' ]++++++++++++++++\n\n");
    
	ft_printf("### Test case: ft_printf('[%% d]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[% d]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[% d]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%% d]', -42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[% d]\n", -42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[% d]\n", -42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%% x]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[% x]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[% x]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ FLAG: # ]++++++++++++++++\n\n");
    
	char *s6 = "This a string that wants to be a cool number (?).";
	ft_printf("### Test case: ft_printf('[%%#s]', s6)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%#s]\n", s6);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%#s]\n", s6);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%#x]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%#x]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%#X]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%#X]', -42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%+d]\n", -42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%+d]\n", -42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("\n\n+++++++++++++++++[ FLAG: . ]++++++++++++++++\n\n");
 
	ft_printf("### Test case: ft_printf('[%%.s]', 'Hi world!')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%.s]\n", "Hi world!");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%.s]\n", "Hi world!");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%.2s]', 'Hi world!')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%.2s]\n", "Hi world!");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%.2s]\n", "Hi world!");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%.2d]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%.2d]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%.2d]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case: ft_printf('[%%.50d]', -42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%.50d]\n", -42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%.50d]\n", -42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);


	ft_printf("\n\n+++++++++++++++++[ MIXED FLAGS ]++++++++++++++++\n\n");
	
	ft_printf("### Test case: ft_printf('[%%20.15d]', 42)\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%20.15d]\n", 42);
    ft_printf("▶ Printf output: ");
    res2 = printf("[%20.15d]\n", 42);
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

    ft_printf("\n\n=================[ ERROR CASES ]=================\n\n");


	ft_printf("### Test case(char after %% is not valid): ft_printf('%%9')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("\n▶ My output: ");
    res1 = ft_printf("%9");
    ft_printf("\n▶ Printf output: ");
    res2 = printf("%9");
    ft_printf("\n▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
	
	int stdout_copy = dup(STDOUT_FILENO);
	ft_printf("### Test case(fd 1 is closed and buffer behaviour is ignored): ft_printf('Hello')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("\n▶ My output: ");
	close(STDOUT_FILENO);
    res1 = ft_printf("\nHola");
	dup2(stdout_copy, STDOUT_FILENO);
    ft_printf("\n▶ Printf output:");
	close(STDOUT_FILENO);
    res2 = printf("\nHola");
	dup2(stdout_copy, STDOUT_FILENO);
	printf("\nReset\n");
    ft_printf("\n▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);
	
	ft_printf("### Test case(%% isolated): ft_printf('[%%]')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%]\n");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%]\n");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	ft_printf("### Test case(no arguments): ft_printf('[%%d]')\n");
    ft_printf("--------------------------------------------------\n");
    ft_printf("▶ My output: ");
    res1 = ft_printf("[%d]\n");
    ft_printf("▶ Printf output: ");
    res2 = printf("[%d]\n");
    ft_printf("▶ Return value:  mine = %d | printf = %d\n\n", res1, res2);

	return 0;
}
