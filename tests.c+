/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:30:55 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/02 22:59:48 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_leaks(void)
{
	system("leaks -q a.exe");
}

void	test1(void)
{
	int				count;
	unsigned int	n;

	printf("\n");
	n = 0xfffffffa;
	while (n++ < 0xffffffff)
	{
		count = printf("Hexadecimal    -> %x", n);
		printf(" : %d\n", count - 18);
		count = ft_printf("FT Hexadecimal -> %x", n);
		printf(" : %d\n", count - 18);
	}
	printf("\n");
}

void	test2(void)
{
	int				count;

	printf("->\n");
	count = printf("\001\002\007\v\010\f\r\n");
	printf(" : %d\n", count - 13);
	count = ft_printf("\001\002\007\v\010\f\r\n");
	printf(" : %d\n", count - 13);
	printf("<-\n");
}

void	test3(void)
{
	int				count;

	printf("\n");
	count = printf("printf    -> dgs%dxx", 10);
	printf(" : %d\n", count - 13);
	count = ft_printf("ft_printf -> dgs%dxx", 10);
	printf(" : %d\n", count - 13);
	printf("\n");
}

void	test4(void)
{
	int				count;

	printf("\n");
	count = printf("printf    -> %d", 0);
	printf(" : %d\n", count - 13);
	count = ft_printf("ft_printf -> %d", 0);
	printf(" : %d\n", count - 13);
	printf("\n");
}

int	main(void)
{
	atexit(ft_leaks);
	printf("%xb%c\ttcQ4T=%sV$cK6A],`%ck3]_", -1194111971, 2042023024, "\rZ0)EGx\\3R[Is*!mnAq2)y3sNXfwavi8>QESA,Vax@bJDWwccgIh#3sN)h&|={\"Cdm%cs}98!M", 1448769200);
	printf("\n");
	ft_printf("%xb%c\ttcQ4T=%sV$cK6A],`%ck3]_", -1194111971, 2042023024, "\rZ0)EGx\\3R[Is*!mnAq2)y3sNXfwavi8>QESA,Vax@bJDWwccgIh#3sN)h&|={\"Cdm%cs}98!M", 1448769200);
	printf("\n");
	return (0);
}
