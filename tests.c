/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:30:55 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/03 14:04:52 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_leaks(void)
{
	system("leaks -q a.exe");
}

int	main(void)
{
	int	count;
	atexit(ft_leaks);
	count = printf("%-20.5s-", "42Malaga");
	printf("\n%d\n", count);
	count = ft_printf("%-20.5s-", "42Malaga");
	printf("\n%d\n", count);
	return (0);
}
