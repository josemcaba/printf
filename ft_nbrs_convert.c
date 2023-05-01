/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/30 09:26:05 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_putuint(unsigned int n)
{
	int	digit;
	int len;

	len = 0;		
	if (n > 9)
		len = ft_putuint((n / 10));
	digit = (n % 10) + '0';
	ft_putchar_fd(digit, 1);
	return (len + 1);
}

int	ft_pf_uint(va_list *args, t_flags *flags)
{
	int		len;

	if (flags->specifier == 'u')
		len = ft_putuint(va_arg(*args, unsigned int));
	return (len);
}

int	ft_pf_nbr(va_list *args, t_flags *flags)
{
	int		len;
	int		nbr;
	char	*str;

	nbr = va_arg(*args, int);
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
	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	len += ft_strlen(str);
	free(str);
	return (len);
}
