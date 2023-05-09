/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/09 14:11:50 by jocaball         ###   ########.fr       */
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

void	fill_pad_int(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int	nbr_len;
	int	no_zero;

	pad_len = ft_strlen(*pad);
	if (pad_len)
	{
		nbr_len = ft_strlen(nbr) - flags->negative;
		no_zero = ft_strncmp(nbr, "0", nbr_len);
		ft_memcpy(*pad, nbr + flags->negative, nbr_len);
		add_precision(&(*pad), &nbr_len, flags, !no_zero);
		add_prefix_int(&(*pad), &nbr_len, flags, no_zero);
		if (!flags->minus)
		{
			ft_memmove(&(*pad)[pad_len - nbr_len], *pad, nbr_len);
			ft_memset(*pad, ' ', pad_len - nbr_len);
			add_width_int(&(*pad), nbr_len, flags);
		}
	}
}

int	ft_pf_uint(va_list *args, t_flags *flags)
{
	size_t	nbr;
	int		len;
	char	*str_nbr;
	char	*pad;

	nbr = va_arg(*args, unsigned int);
	str_nbr = ft_uitoa(nbr);
	if (!str_nbr)
		return (-1);
	len = alloc_pad_int(&pad, str_nbr, flags);
	if (len != -1)
	{
		fill_pad_int(&pad, str_nbr, flags);
		len = ft_putstr(pad);
		free(pad);
	}
	free(str_nbr);
	return (len);
}
