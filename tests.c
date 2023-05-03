/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:38:11 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/04 00:19:39 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_leaks(void)
{
	system("leaks -q a.exe");
}

int main(void) 
{
	int		count;
	char	*ptr = "Puntero";

	atexit(ft_leaks);
	count = printf("Hola mundo!--");
	printf("%d\n", count-2);
	count = ft_printf("Hola mundo!--");
	ft_printf("%d\n", count-2);	

	count = printf("Caracter:%c--", 'M');
	printf("%d\n", count-2);
	count = ft_printf("Caracter:%c--", 'M');
	ft_printf("%d\n", count-2);		

	count = printf("Cadena:%s--", "");
	printf("%d\n", count-2);
	count = ft_printf("Cadena:%s--", "");
	ft_printf("%d\n", count-2);	

	count = printf("Cadena:%s--", "42 Malaga");
	printf("%d\n", count-2);
	count = ft_printf("Cadena:%s--", "42 Malaga");
	ft_printf("%d\n", count-2);	

	count = printf("%s:%p--", ptr, ptr);
	printf("%d\n", count-2);
	count = ft_printf("%s:%p--", ptr, ptr);
	ft_printf("%d\n", count-2);

	ptr = 0;
	count = printf("%s:%p--", ptr, ptr);
	printf("%d\n", count-2);
	count = ft_printf("%s:%p--", ptr, ptr);
	ft_printf("%d\n", count-2);

	count = printf("Decimal:%d--", 1523589012);
	printf("%d\n", count-2);
	count = ft_printf("Decimal:%d--", 1523589012);
	ft_printf("%d\n", count-2);

	count = printf("Decimal:%d--", -152358);
	printf("%d\n", count-2);
	count = ft_printf("Decimal:%d--", -152358);
	ft_printf("%d\n", count-2);

	count = printf("Entero:%i--", 152358);
	printf("%d\n", count-2);
	count = ft_printf("Entero:%i--", 152358);
	ft_printf("%d\n", count-2);

	count = printf("Entero:%i--", -152358);
	printf("%d\n", count-2);
	count = ft_printf("Entero:%i--", -152358);
	ft_printf("%d\n", count-2);

	count = printf("Sin signo:%u--", -1);
	printf("%d\n", count-2);
	count = ft_printf("Sin signo:%u--", -1);
	ft_printf("%d\n", count-2);

	count = printf("hexadecimal:%x--", 39856);
	printf("%d\n", count-2);
	count = ft_printf("hexadecimal:%x--", 39856);
	ft_printf("%d\n", count-2);

	count = printf("hexadecimal:%x--", 0);
	printf("%d\n", count-2);
	count = ft_printf("hexadecimal:%x--", 0);
	ft_printf("%d\n", count-2);

	count = printf("HEXADECIMAL:%X--", -521);
	printf("%d\n", count-2);
	count = ft_printf("HEXADECIMAL:%X--", -521);
	ft_printf("%d\n", count-2);

	count = printf("Porcentaje:%%--");
	printf("%d\n", count-2);
	count = ft_printf("Porcentaje:%%--");
	ft_printf("%d\n", count-2);

	ft_printf("\n*****  BONUS 2 *****\n\n");

	count = printf("hexadecimal:%#x--", 39856);
	printf("%d\n", count-2);
	count = ft_printf("hexadecimal:%#x--", 39856);
	ft_printf("%d\n", count-2);

	count = printf("hexadecimal:%#x--", 0);
	printf("%d\n", count-2);
	count = ft_printf("hexadecimal:%#x--", 0);
	ft_printf("%d\n", count-2);

	count = printf("HEXADECIMAL:%#X--", -521);
	printf("%d\n", count-2);
	count = ft_printf("HEXADECIMAL:%#X--", -521);
	ft_printf("%d\n", count-2);

	count = printf("Decimal:%+d--", 1523589012);
	printf("%d\n", count-2);
	count = ft_printf("Decimal:%+d--", 1523589012);
	ft_printf("%d\n", count-2);

	count = printf("Decimal:%+d--", -152358);
	printf("%d\n", count-2);
	count = ft_printf("Decimal:%+d--", -152358);
	ft_printf("%d\n", count-2);

	count = printf("Entero:% i--", 152358);
	printf("%d\n", count-2);
	count = ft_printf("Entero:% i--", 152358);
	ft_printf("%d\n", count-2);

	count = printf("Entero:% i--", -152358);
	printf("%d\n", count-2);
	count = ft_printf("Entero:% i--", -152358);
	ft_printf("%d\n", count-2);

	ft_printf("\n*****  BONUS 1 (c) *****\n\n");

	count = printf("Nada  : %c--", 'A');
	printf("%d\n", count-2);
	count = printf("Minus : %-7c--", 'A');
	printf("%d\n", count-2);
	count = printf("Minus : %-2c--", 'A');
	printf("%d\n", count-2);
	count = printf("Minus : %-c--", 'A');
	printf("%d\n", count-2);
//	count = printf("Zero  : %07c--", 'A');
//	printf("%d\n", count-2);
//	count = printf("Zero  : %02c--", 'A');	
//	printf("%d\n", count-2);
//	count = printf("Dot   : %.7c--", 'A');
//	printf("%d\n", count-2);
//	count = printf("Dot   : %.2c--", 'A');
//	printf("%d\n", count-2);
	count = printf("Width : %7c--", 'A');
	printf("%d\n", count-2);
	count = printf("Width : %2c--", 'A');
	printf("%d\n", count-2);
//	count = printf("Hash  : %#c--", 'A');
//	printf("%d\n", count-2);
//	count = printf("Space : % c--", 'A');
//	printf("%d\n", count-2);
//	count = printf("Plus  : %+c--", 'A');
//	printf("%d\n", count-2);
	ft_printf("\n");
	count = ft_printf("Nada  : %c--", 'A');
	printf("%d\n", count-2);
	count = ft_printf("Minus : %-7c--", 'A');
	printf("%d\n", count-2);
	count = ft_printf("Minus : %-2c--", 'A');
	printf("%d\n", count-2);
	count = ft_printf("Minus : %-c--", 'A');
	printf("%d\n", count-2);
//	count = ft_printf("Zero  : %07c--", 'A');
//	printf("%d\n", count-2);
//	count = ft_printf("Zero  : %02c--", 'A');	
//	printf("%d\n", count-2);
//	count = ft_printf("Dot   : %.7c--", 'A');
//	printf("%d\n", count-2);
//	count = ft_printf("Dot   : %.2c--", 'A');
//	printf("%d\n", count-2);
	count = ft_printf("Width : %7c--", 'A');
	printf("%d\n", count-2);
	count = ft_printf("Width : %2c--", 'A');
	printf("%d\n", count-2);
//	count = printf("Hash  : %#c--", 'A');
//	printf("%d\n", count-2);
//	count = printf("Space : % c--", 'A');
//	printf("%d\n", count-2);
//	count = printf("Plus  : %+c--", 'A');
//	printf("%d\n", count-2);

	ft_printf("\n*****  BONUS 1 (s) *****\n\n");

	count = printf("Nada  : %s--", "abcd");
	printf("%d\n", count-2);
	count = printf("Minus : %-7s--", "abcd");
	printf("%d\n", count-2);
	count = printf("Minus : %-2s--", "abcd");
	printf("%d\n", count-2);
	count = printf("Minus : %-s--", "abcd");
	printf("%d\n", count-2);
//	count = printf("Zero  : %07s--\n", "abcd");
//	count = printf("Zero  : %02s--\n", "abcd");	
	count = printf("Dot   : %.7s--", "abcd");
	printf("%d\n", count-2);
	count = printf("Dot   : %.2s--", "abcd");
	printf("%d\n", count-2);
	count = printf("Dot   : %.s--", "abcd");
	printf("%d\n", count-2);
	count = printf("Width : %7s--", "abcd");
	printf("%d\n", count-2);
	count = printf("Width : %2s--", "abcd");
	printf("%d\n", count-2);
//	count = printf("Hash  : %#s--\n", "abcd");
//	count = printf("Space : % s--\n", "abcd");
//	count = printf("Plus  : %+s--\n", "abcd");
	ft_printf("\n");
	count = ft_printf("Nada  : %s--", "abcd");
	printf("%d\n", count-2);
	count = ft_printf("Minus : %-7s--", "abcd");
	printf("%d\n", count-2);
	count = ft_printf("Minus : %-2s--", "abcd");
	printf("%d\n", count-2);
	count = ft_printf("Minus : %-s--", "abcd");
	printf("%d\n", count-2);
//	count = ft_printf("Zero  : %07s--\n", "abcd");
//	count = ft_printf("Zero  : %02s--\n", "abcd");	
	count = ft_printf("Dot   : %.7s--", "abcd");
	printf("%d\n", count-2);
	count = ft_printf("Dot   : %.2s--", "abcd");
	printf("%d\n", count-2);
	count = ft_printf("Dot   : %.s--", "abcd");
	printf("%d\n", count-2);
	count = ft_printf("Width : %7s--", "abcd");
	printf("%d\n", count-2);
	count = ft_printf("Width : %2s--", "abcd");
	printf("%d\n", count-2);
//	count = ft_printf("Hash  : %#s--\n", "abcd");
//	count = ft_printf("Space : % s--\n", "abcd");
//	count = ft_printf("Plus  : %+s--\n", "abcd");

	ft_printf("\n*****  BONUS 1 (p) *****\n\n");

	count = printf("Nada  : %p--\n", "abcd");
	count = printf("Minus : %-18p--\n", "abcd");
	count = printf("Minus : %-2p--\n", "abcd");
// 	count = printf("Zero  : %07p--\n", "abcd");
// 	count = printf("Zero  : %02p--\n", "abcd");	
// 	count = printf("Dot   : %.7p--\n", "abcd");
//	count = printf("Dot   : %.2p--\n", "abcd");
	count = printf("Width : %18p--\n", "abcd");
	count = printf("Width : %2p--\n", "abcd");
//	count = printf("Hash  : %#p--\n", "abcd");
//	count = printf("Space : % p--\n", "abcd");
//	count = printf("Plus  : %+p--\n", "abcd");

	ft_printf("\n*****  BONUS 1 (d) *****\n\n");

	count = printf("Nada  : %d--\n", 1234);
	count = printf("Minus : %-7d--\n", 1234);
	count = printf("Minus : %-2d--\n", 1234);
	count = printf("Zero  : %07d--\n", 1234);
	count = printf("Zero  : %02d--\n", 1234);	
	count = printf("Dot   : %.7d--\n", 1234);
	count = printf("Dot   : %.2d--\n", 1234);
	count = printf("Width : %7d--\n", 1234);
	count = printf("Width : %2d--\n", 1234);
//	count = printf("Hash  : %#d--\n", 1234);
	count = printf("Space : % 10d--\n", 1234);
	count = printf("Plus  : %+10d--\n", 1234);
	ft_printf("\n");
	count = ft_printf("Nada  : %d--\n", 1234);
	count = ft_printf("Minus : %-7d--\n", 1234);
	count = ft_printf("Minus : %-2d--\n", 1234);
	count = ft_printf("Zero  : %07d--\n", 1234);
	count = ft_printf("Zero  : %02d--\n", 1234);	
	count = ft_printf("Dot   : %.7d--\n", 1234);
	count = ft_printf("Dot   : %.2d--\n", 1234);
	count = ft_printf("Width : %7d--\n", 1234);
	count = ft_printf("Width : %2d--\n", 1234);
//	count = ft_printf("Hash  : %#d--\n", 1234);
	count = ft_printf("Space : % 10d--\n", 1234);
	count = ft_printf("Plus  : %+10d--\n", 1234);
	

	ft_printf("\n*****  BONUS 1 (i) *****\n\n");

	count = printf("Nada  : %i--\n", 1234);
	count = printf("Minus : %-7i--\n", 1234);
	count = printf("Minus : %-2i--\n", 1234);
	count = printf("Zero  : %07i--\n", 1234);
	count = printf("Zero  : %02i--\n", 1234);	
	count = printf("Dot   : %.7i--\n", 1234);
	count = printf("Dot   : %.2i--\n", 1234);
	count = printf("Width : %7i--\n", 1234);
	count = printf("Width : %2i--\n", 1234);
//	count = printf("Hash  : %#i--\n", 1234);
	count = printf("Space : % 10i--\n", 1234);
	count = printf("Plus  : %+10i--\n", 1234);

	ft_printf("\n*****  BONUS 1 (u) *****\n\n");

	count = printf("Nada  : %u--\n", 1234);
	count = printf("Minus : %-7u--\n", 1234);
	count = printf("Minus : %-2u--\n", 1234);
	count = printf("Zero  : %07u--\n", 1234);
	count = printf("Zero  : %02u--\n", 1234);	
	count = printf("Dot   : %.7u--\n", 1234);
	count = printf("Dot   : %.2u--\n", 1234);
	count = printf("Width : %7u--\n", 1234);
	count = printf("Width : %2u--\n", 1234);
//	count = printf("Hash  : %#u--\n", 1234);
//	count = printf("Space : % 10u--\n", 1234);
//	count = printf("Plus  : %+10u--\n", 1234);

	ft_printf("\n*****  BONUS 1 (x) *****\n\n");

	count = printf("Nada  : %x--\n", 1234);
	count = printf("Minus : %-7x--\n", 1234);
	count = printf("Minus : %-2x--\n", 1234);
	count = printf("Zero  : %07x--\n", 1234);
	count = printf("Zero  : %02x--\n", 1234);	
	count = printf("Dot   : %.7x--\n", 1234);
	count = printf("Dot   : %.2x--\n", 1234);
	count = printf("Width : %7x--\n", 1234);
	count = printf("Width : %2x--\n", 1234);
	count = printf("Hash  : %#x--\n", 1234);
//	count = printf("Space : % 10x--\n", 1234);
//	count = printf("Plus  : %+10x--\n", 1234);

	ft_printf("\n*****  BONUS 1 (X) *****\n\n");

	count = printf("Nada  : %X--\n", 1234);
	count = printf("Minus : %-7X--\n", 1234);
	count = printf("Minus : %-2X--\n", 1234);
	count = printf("Zero  : %07X--\n", 1234);
	count = printf("Zero  : %02X--\n", 1234);	
	count = printf("Dot   : %.7X--\n", 1234);
	count = printf("Dot   : %.2X--\n", 1234);
	count = printf("Width : %7X--\n", 1234);
	count = printf("Width : %2X--\n", 1234);
	count = printf("Hash  : %#X--\n", 1234);
//	count = printf("Space : % 10x--\n", 1234);
//	count = printf("Plus  : %+10x--\n", 1234);

//	printf("%d\n", count-2);

    return 0;
}
