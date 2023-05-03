/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:16:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/02 13:39:03 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putprefix(int nbr, t_flags *flags)
{
	int	len;

	len = 0;
	if ((nbr > 0) && (flags->plus))
	{
		ft_putchar_fd('+', 1);
		len = 1;
	}
	else if ((nbr > 0) && (flags->space))
	{
		ft_putchar_fd(' ', 1);
		len = 1;
	}
	else if ((flags->hash) && (nbr != 0))
	{
		if (flags->specifier == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		len = 2;
	}
	return (len);
}
