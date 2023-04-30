/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:30:55 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/30 08:30:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_leaks(void)
{
	system("leaks -q a.out");
}

int main(void) 
{
	int		count;
	char	*ptr = "Puntero";

	atexit(ft_leaks);
	count = printf("Hola mundo!--");
	printf("%d\n", count-2);
	count = ft_printf("Hola mundo!--");
	printf("%d\n", count-2);	

	count = printf("Caracter:%c--", 'M');
	printf("%d\n", count-2);
	count = ft_printf("Caracter:%c--", 'M');
	printf("%d\n", count-2);		

	count = printf("Cadena:%s--", "");
	printf("%d\n", count-2);
	count = ft_printf("Cadena:%s--", "");
	printf("%d\n", count-2);	

	count = printf("Cadena:%s--", "42 Málaga");
	printf("%d\n", count-2);
	count = ft_printf("Cadena:%s--", "42 Málaga");
	printf("%d\n", count-2);	

	count = printf("%s:%p--", ptr, ptr);
	printf("%d\n", count-2);
	count = ft_printf("%s:%p--", ptr, ptr);
	printf("%d\n", count-2);

	ptr = 0;
	count = printf("%s:%p--", ptr, ptr);
	printf("%d\n", count-2);
	count = ft_printf("%s:%p--", ptr, ptr);
	printf("%d\n", count-2);

	count = printf("Decimal:%d--", 1523589012);
	printf("%d\n", count-2);
	count = ft_printf("Decimal:%d--", 1523589012);
	printf("%d\n", count-2);

	count = printf("Decimal:%d--", -152358);
	printf("%d\n", count-2);
	count = ft_printf("Decimal:%d--", -152358);
	printf("%d\n", count-2);

	count = printf("Entero:%i--", 152358);
	printf("%d\n", count-2);
	count = ft_printf("Entero:%i--", 152358);
	printf("%d\n", count-2);

	count = printf("Entero:%i--", -152358);
	printf("%d\n", count-2);
	count = ft_printf("Entero:%i--", -152358);
	printf("%d\n", count-2);

	count = printf("Sin signo:%u--", -1);
	printf("%d\n", count-2);
	count = ft_printf("Sin signo:%u--", -1);
	printf("%d\n", count-2);

	count = printf("hexadecimal:%x--", 0);
	printf("%d\n", count-2);
	count = ft_printf("hexadecimal:%x--", 0);
	printf("%d\n", count-2);

	count = printf("HEXADECIMAL:%X--", -1);
	printf("%d\n", count-2);
	count = ft_printf("HEXADECIMAL:%X--", -1);
	printf("%d\n", count-2);

	count = printf("Porcentaje:%%--");
	printf("%d\n", count-2);
	count = ft_printf("Porcentaje:%%--");
	printf("%d\n", count-2);

    return 0;

	
}
