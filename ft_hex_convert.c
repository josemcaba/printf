/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/03 11:26:33 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(size_t n, char specifier, int *error_flag)
{
	char	*hex_base;
	int		digit;
	int		len;

	hex_base = "0123456789abcdef";
	if (specifier == 'X')
		hex_base = "0123456789ABCDEF";
	len = 0;
	if (n > 15)
		len = ft_puthex((n / 16), specifier, error_flag);
	if (*error_flag)
		return (-1);
	digit = n % 16;
	if (ft_putchar(hex_base[digit]) == -1)
	{
		*error_flag = 1;
		return (-1);
	}
	return (len + 1);
}

int	ft_pf_ptr(va_list *args, char specifier)
{
	size_t	nbr;
	int		len;
	int		error_flag;

	len = 0;
	nbr = (size_t)va_arg(*args, void *);
	if (!nbr)
	{
		if (ft_putstr("0x0") == -1)
			return (-1);
		return (ft_strlen("0x0"));
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	error_flag = 0;
	len = ft_puthex(nbr, specifier, &error_flag);
	if (len == -1)
		return (-1);
	return (len + 2);
}

// La funcion printf() admite maximo unsigned int
int	ft_pf_hex(va_list *args, t_flags *flags)
{
	unsigned int	nbr;
	int				len;
	int				t_len;
	int				error_flag;

	nbr = va_arg(*args, unsigned int);
	len = ft_putprefix(nbr, flags);
	error_flag = 0;
	t_len = ft_puthex(nbr, flags->specifier, &error_flag);
	if (t_len == -1)
		return (-1);
	len += t_len;
	return (len);
}
