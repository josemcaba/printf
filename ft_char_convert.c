/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:19:30 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/03 14:10:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding_char(unsigned char c, t_flags *flags)
{
	int	len;

	len = flags->width;
	if (flags->minus)
	{
		if (ft_putchar(c) == -1)
			return (-1);
		while (--flags->width)
			if (ft_putchar(' ') == -1)
				return (-1);
	}
	else
	{
		while (--flags->width)
			if (ft_putchar(' ') == -1)
				return (-1);
		if (ft_putchar(c) == -1)
			return (-1);
	}
	return (len);
}

int	ft_pf_char(va_list *args, t_flags *flags)
{
	unsigned int	c;
	int				len;

	c = va_arg(*args, unsigned int);
	if (flags->width)
		len = padding_char(c, flags);
	else
		len = ft_putchar(c);
	return (len);
}
