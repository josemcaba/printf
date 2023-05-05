/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/05 00:53:00 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_minus(char *pad, char sign)
{
	char	*fzero;

	if (sign == '-')
	{
		fzero = ft_strchr(pad, '0');
		if (fzero)
			*fzero = '-';
	}
}

int	padding(char *str, t_flags *flags, char **s)
{
	int	pad_len;
	int	sign;

	sign = 0;
	if (str[0] == '-')
		sign = 1;
	pad_len = ft_strlen(str);
	if (flags->dot && (flags->precision > pad_len))
		pad_len = flags->precision + sign;
	if (flags->dot && (flags->precision == 0))
		pad_len = 0;
	if (flags->width > pad_len)
		pad_len = flags->width;
	*s = (char *)ft_calloc(pad_len + 1, sizeof(char));
	if (!*s)
		return (-1);
	ft_memset(*s, ' ', pad_len);
	return (pad_len);
}

int	precision_nbr(char *str, t_flags *flags, char **nbr)
{
	int	nbr_len;
	int	str_len;
	int	sign;

	sign = 0;
	if (str[0] == '-')
		sign = 1;
	str_len = ft_strlen(str);
	nbr_len = str_len;
	if ((flags->dot) && (flags->precision > str_len))
		nbr_len = flags->precision + sign;
	*nbr = (char *)ft_calloc(nbr_len + 1, sizeof(char));
	if (!*nbr)
		return (-1);
	ft_memset(*nbr, '0', nbr_len - str_len + sign);
	ft_memcpy(*nbr + nbr_len - str_len + sign, str + sign, str_len - sign);
	if (flags->dot && (flags->precision == 0))
		nbr_len = 0;
	return (nbr_len);
}

int	padding_nbr(char *str, t_flags *flags)
{
	char	*pad;
	int		pad_len;
	char	*nbr;
	int		nbr_len;

	pad_len = padding(str, flags, &pad);
	if (!pad)
		return (-1);
	nbr_len = precision_nbr(str, flags, &nbr);
	if (!nbr)
		return (-1);
	if (flags->minus)
		ft_memcpy(pad, nbr, nbr_len);
	else
	{
		if (flags->zero && !flags->dot)
			ft_memset(pad, '0', pad_len);
		ft_memcpy(pad + pad_len - nbr_len, nbr, nbr_len);
	}
	ft_put_minus(pad, *str);
	if (ft_putstr(pad) == -1)
		pad_len = -1;
	free(pad);
	free(nbr);
	return (pad_len);
}

int	ft_pf_uint(va_list *args, t_flags *flags)
{
	int					len;
	unsigned int		nbr;
	char				*str;

	nbr = va_arg(*args, unsigned int);
	str = ft_uitoa(nbr);
	if (!str)
		return (-1);
	if (flags->nflags)
		len = padding_nbr(str, flags);
	else
		len = ft_putstr(str);
	free(str);
	return (len);
}

// static int	ft_putuint(unsigned int n, int *error_flag)
// {
// 	int	digit;
// 	int	len;

// 	len = 0;
// 	if (n > 9)
// 		len = ft_putuint((n / 10), error_flag);
// 	if (*error_flag)
// 		return (-1);
// 	digit = (n % 10) + '0';
// 	if (ft_putchar(digit) == -1)
// 	{
// 		*error_flag = 1;
// 		return (-1);
// 	}
// 	return (len + 1);
// }

// int	ft_pf_uint(va_list *args, t_flags *flags)
// {
// 	int	len;
// 	int	error_flag;

// 	len = 0;
// 	error_flag = 0;
// 	if (flags->specifier == 'u')
// 		len = ft_putuint(va_arg(*args, unsigned int), &error_flag);
// 	return (len);
// }
