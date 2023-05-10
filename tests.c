#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf(" : %d\n", ft_printf("%5%"));
	printf(" : %d\n", ft_printf("%-5%"));
	printf(" : %d\n", ft_printf("%-05%"));
	printf(" : %d\n", ft_printf("%-05%hola"));
    return (0);
}