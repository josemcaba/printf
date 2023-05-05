/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/04 23:54:28 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding(char *str, t_flags *flags, char **s)
{
	int	pad_len;

	pad_len = ft_strlen(str);
	if (flags->dot && (flags->precision > pad_len))
		pad_len = flags->precision;
	if (flags->dot && (flags->precision == 0))
		pad_len = 0;
	if (flags->width > pad_len)
		pad_len = flags->width;
	*s = (char *)malloc(pad_len * sizeof(char) + 1);
	if (!*s)
		return (-1);
	ft_memset(*s, ' ', pad_len);
	(*s)[pad_len] = '\0';
	return (pad_len);
}

int	precision_nbr(char *str, t_flags *flags, char **nbr)
{
	int		nbr_len;
	int		str_len;

	str_len = ft_strlen(str);
	nbr_len = str_len;
	if ((flags->dot) && (flags->precision > str_len))
		nbr_len = flags->precision;
	*nbr = (char *)malloc(nbr_len * sizeof(char) + 1);
	if (!*nbr)
		return (-1);
	ft_memset(*nbr, '0', nbr_len - str_len);
	ft_memcpy(*nbr + nbr_len - str_len, str, str_len);
	(*nbr)[nbr_len] = '\0';
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
	if (ft_putstr(pad) == -1)
		pad_len = -1;
	free(pad);
	free(nbr);
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
