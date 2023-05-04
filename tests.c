/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:30:55 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/04 00:14:43 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// #define INT_MIN	0x80000000
// #define INT_MAX 0x7fffffff

void	ft_leaks(void)
{
	system("leaks -q a.exe");
}

void	test_d (char *format, int nbr)
{
	printf(" : %d\n", printf(format, nbr));
	printf(" : %d\n", ft_printf(format, nbr));	
}

int	main(void)
{
	//ptr = "42Malaga";
	atexit(ft_leaks);
	test_d("%d", 1523589012);
	test_d("%d", -354316);
//	test_d("%-7d", 1234);
//	test_d("%-2d", 1234);
	test_d("%07d", 1234);
	test_d("%02d", 1234);
	test_d("%.7d", 1234);
	test_d("%.2d", 1234);
	test_d("%7d", 1234);
	test_d("%2d", 1234);	
	test_d("% 10d", 1234);
	test_d("%+10d", 1234);	
	test_d("%.5d", 2);
	test_d("%.3d", 0);
	test_d("%8.5d", 34);	
	test_d("%8.5d", 0);
	test_d("%8.3d", 8375);
	test_d("%3.7d", 3267);
	test_d("%-8.5d", 34);
	test_d("%-8.5d", 0);
	test_d("%-8.3d", 8375);
	test_d("%-3.7d", 3267);
	test_d("%08.5d", 34);
	test_d("%08.5d", 0);

	return (0);
}
