/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/02 12:34:58 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_nbr(va_list *args, t_flags *flags)
{
	int		len;
	int		nbr;
	char	*str;

	nbr = va_arg(*args, int);
	len = ft_putprefix(nbr, flags);
	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	len += ft_strlen(str);
	free(str);
	return (len);
}

static int	ft_putuint(unsigned int n)
{
	int	digit;
	int	len;

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

	len = 0;
	if (flags->specifier == 'u')
		len = ft_putuint(va_arg(*args, unsigned int));
	return (len);
}
