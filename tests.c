#include "ft_printf.h"
#include <stdio.h>

int main(void) 
{
	int		count;
	char	*ptr = "Puntero : ";

	count = printf("Hola mundo! -- ");
	printf("%d\n", count);
	count = ft_printf("Hola mundo! -- ");
	printf("%d\n", count);	

	count = printf("Caracter : %c -- ", 'A');
	printf("%d\n", count);
	count = ft_printf("Caracter : %c -- ", 'A');
	printf("%d\n", count);		

	count = printf("Cadena : %s -- ", "");
	printf("%d\n", count);
	count = ft_printf("Cadena : %s -- ", "");
	printf("%d\n", count);	

	count = printf("Cadena : %s -- ", "42 MAlaga");
	printf("%d\n", count);
	count = ft_printf("Cadena : %s -- ", "42 MAlaga");
	printf("%d\n", count);	

	ptr = ptr - 0x100000000;
	count = printf("%p-", ptr);
	printf("%d\n", count);
	count = ft_printf("%p-", ptr);
	printf("%d\n", count);	


	// count = printf("Hola : %c %s%s %p x %d / %d %%\n", 'A', str1, str2, str1, 1654515, -4121275);
	// printf("%d\n", count);
	// count = ft_printf("Hola : %c %s%s %p x %d / %d %%\n", 'A', str1, str2, str1, 1654515, -4121275);
	// printf("%d\n", count);

    return 0;
}
