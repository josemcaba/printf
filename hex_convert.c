/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/09 14:09:13 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	alloc_pad(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int	no_zero;

	pad_len = ft_strlen(nbr);
	no_zero = ft_strncmp(nbr, "0", pad_len);
	if (flags->dot && (flags->precision > pad_len))
		pad_len = flags->precision;
	if (flags->dot && (flags->precision == 0) && !no_zero)
		pad_len--;
	if ((flags->hash && no_zero) || (flags->specifier == 'p'))
		pad_len += 2;
	if (flags->width > pad_len)
		pad_len = flags->width;
	*pad = (char *)ft_calloc(pad_len + 1, sizeof(char));
	if (!*pad)
		return (-1);
	ft_memset(*pad, ' ', pad_len);
	return (pad_len);
}

void	add_prefix(char **pad, int *nbr_len, t_flags *flags, int no_zero)
{
	char	*prefix;

	prefix = "0x";
	if (flags->specifier == 'X')
		prefix = "0X";
	if ((flags->hash && no_zero) || (flags->specifier == 'p'))
	{
		ft_memmove(&(*pad)[2], *pad, *nbr_len);
		ft_memcpy(*pad, prefix, 2);
		*nbr_len += 2;
	}
}

void	add_width(char **pad, int nbr_len, t_flags *flags)
{
	int	pad_len;

	pad_len = ft_strlen(*pad);
	if (flags->zero && !flags->dot)
	{
		ft_memset(*pad, '0', pad_len - nbr_len);
		if (ft_strchr(*pad, flags->specifier))
		{
			*ft_strchr(*pad, flags->specifier) = '0';
			(*pad)[1] = flags->specifier;
		}
	}
}

void	fill_pad(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int	nbr_len;
	int	no_zero;

	pad_len = ft_strlen(*pad);
	if (pad_len)
	{
		nbr_len = ft_strlen(nbr);
		no_zero = ft_strncmp(nbr, "0", nbr_len);
		ft_memcpy(*pad, nbr, nbr_len);
		add_precision(&(*pad), &nbr_len, flags, !no_zero);
		add_prefix(&(*pad), &nbr_len, flags, no_zero);
		if (!flags->minus)
		{
			ft_memmove(&(*pad)[pad_len - nbr_len], *pad, nbr_len);
			ft_memset(*pad, ' ', pad_len - nbr_len);
			add_width(&(*pad), nbr_len, flags);
		}
	}
}

size_t	read_hex_nbr(va_list *args, t_flags *flags)
{
	if (flags->specifier == 'p')
		return ((size_t)va_arg(*args, void *));
	else
		return (va_arg(*args, unsigned int));
}

int	hex_convert(va_list *args, t_flags *flags)
{
	size_t	nbr;
	int		len;
	char	*str_nbr;
	char	*pad;

	nbr = read_hex_nbr(args, flags);
	str_nbr = ft_htoa(nbr, flags->specifier);
	if (!str_nbr)
		return (-1);
	len = alloc_pad(&pad, str_nbr, flags);
	if (len != -1)
	{
		fill_pad(&pad, str_nbr, flags);
		len = ft_putstr(pad);
		free(pad);
	}
	free(str_nbr);
	return (len);
}
