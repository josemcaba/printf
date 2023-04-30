/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/30 09:26:05 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putuint(unsigned int n)
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

int	ft_puthex(size_t n, char specifier)
{
	char	*hex_base;
	int		digit;
	int		len;

	hex_base = "0123456789abcdef";
	if (specifier == 'X')
		hex_base = "0123456789ABCDEF";
	len = 0;
	if (n > 15)
		len = ft_puthex((n / 16), specifier);
	digit = n % 16;
	ft_putchar_fd(hex_base[digit], 1);
	return (len + 1);
}

int	ft_pf_hex(va_list *args, char specifier)
{
	size_t	nbr;
	int		len;

	len = 0;
	if (specifier == 'p')
	{
		nbr = (size_t)va_arg(*args, void *);
		if (!nbr)
		{
			ft_putstr_fd("(null)", 1);
			return (ft_strlen("(null)"));
		}
		ft_putstr_fd("0x", 1);
		len = 2;
	}
	else
		nbr = va_arg(*args, size_t);
	len += ft_puthex(nbr, specifier);
	return (len);
}

int	ft_pf_nbr(va_list *args, char specifier)
{
	int		len;
	char	*str;


	if (specifier == 'u')
		len = ft_putuint(va_arg(*args, unsigned int));
	else
	{
		str = ft_itoa(va_arg(*args, int));
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
		free(str);
	}
	return (len);
}
