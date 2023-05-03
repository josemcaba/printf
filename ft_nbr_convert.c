/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/02 23:09:19 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_nbr(va_list *args, t_flags *flags)
{
	int		len;
	int		t_len;
	int		nbr;
	char	*str;

	nbr = va_arg(*args, int);
	len = ft_putprefix(nbr, flags);
	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	t_len = ft_putstr(str);
	free(str);
	if (t_len == -1)
		return (-1);
	len += t_len;
	return (len);
}

static int	ft_putuint(unsigned int n, int *error_flag)
{
	int	digit;
	int	len;

	len = 0;
	if (n > 9)
		len = ft_putuint((n / 10), error_flag);
	if (*error_flag)
		return (-1);
	digit = (n % 10) + '0';
	if (ft_putchar(digit) == -1)
	{
		*error_flag = 1;
		return (-1);
	}
	return (len + 1);
}

int	ft_pf_uint(va_list *args, t_flags *flags)
{
	int	len;
	int	error_flag;

	len = 0;
	error_flag = 0;
	if (flags->specifier == 'u')
		len = ft_putuint(va_arg(*args, unsigned int), &error_flag);
	return (len);
}