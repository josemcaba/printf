/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/04 00:32:31 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int padding_len(char *str, t_flags *flags)
{
	int	pad_len;
	
	pad_len = ft_strlen(str);
	if ((flags->dot) && (flags->precision > pad_len))
		pad_len = flags->precision;
	if ((flags->dot) && (flags->precision < pad_len))
		flags->precision = pad_len;	
	if (flags->width > pad_len)
		pad_len = flags->width;
	return (pad_len);
}

int	padding_nbr(char *str, t_flags *flags)
{
	char	*s;
	int		str_len;
	int		pad_len;

	str_len = ft_strlen(str);
	pad_len = padding_len(str, flags);
	s = (char *)malloc(pad_len * sizeof(char) + 1);
	if (!s)
		return (-1);
	ft_memset(s, ' ', pad_len);
	s[pad_len] = '\0';
	if (((flags->dot) || (flags->zero)) && !flags->minus)
	 	ft_memset(s + pad_len - flags->precision, '0', flags->precision);
	if (flags->minus)
	{
		ft_memset(s, '0', flags->precision);
		ft_memcpy(s + flags->precision - str_len, str, str_len);
	}
	else
		ft_memcpy(s + pad_len - str_len, str, str_len);
	if (ft_putstr(s) == -1)
		pad_len = -1;
	free(s);
	return (pad_len);
}

char	*ft_putprfx(int nbr, t_flags *flags)
{
	char	*str;
	char	*str_prfx;
	char	*str_nbr;

	str_prfx = "";
	if ((nbr >= 0) && (flags->plus))
		str_prfx = "+";
	else if ((nbr >= 0) && (flags->space))
		str_prfx = " ";
	else if ((flags->hash) && (nbr != 0))
	{
		if (flags->specifier == 'X')
			str_prfx = "0X";
		else
			str_prfx = "0x";
	}
	str_nbr = ft_itoa(nbr);
	if (!str_nbr)
		return (NULL);
	str = ft_strjoin(str_prfx, str_nbr);
	free(str_nbr);
	if (!str)
		return (NULL);
	return (str);
}

int	ft_pf_nbr(va_list *args, t_flags *flags)
{
	int		len;
	int		nbr;
	char	*str;

	nbr = va_arg(*args, int);
	str = ft_putprfx(nbr, flags);
	if (!str)
		return (-1);
	if (flags->nflags)
		len = padding_nbr(str, flags);
	else
		len = ft_putstr(str);
	free(str);
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
