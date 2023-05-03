/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:30:55 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/03 11:23:56 by jocaball         ###   ########.fr       */
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
	int	count;
	
	atexit(ft_leaks);
	count = printf("%p", (void *)-14523);
	printf("\n%d\n", count);
	count = ft_printf("%p", (void *)-14523);
	printf("\n%d\n", count);
	return (0);
}
