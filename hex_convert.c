/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/08 20:44:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_puthex(size_t n, char specifier, int *error_flag)
// {
// 	char	*hex_base;
// 	int		digit;
// 	int		len;

// 	hex_base = "0123456789abcdef";
// 	if (specifier == 'X')
// 		hex_base = "0123456789ABCDEF";
// 	len = 0;
// 	if (n > 15)
// 		len = ft_puthex((n / 16), specifier, error_flag);
// 	if (*error_flag)
// 		return (-1);
// 	digit = n % 16;
// 	if (ft_putchar(hex_base[digit]) == -1)
// 	{
// 		*error_flag = 1;
// 		return (-1);
// 	}
// 	return (len + 1);
// }

// int	ft_pf_ptr(va_list *args, char specifier)
// {
// 	size_t	nbr;
// 	int		len;
// 	int		error_flag;

// 	len = 0;
// 	nbr = (size_t)va_arg(*args, void *);
// 	if (!nbr)
// 	{
// 		if (ft_putstr("0x0") == -1)
// 			return (-1);
// 		return (ft_strlen("0x0"));
// 	}
// 	if (ft_putstr("0x") == -1)
// 		return (-1);
// 	error_flag = 0;
// 	len = ft_puthex(nbr, specifier, &error_flag);
// 	if (len == -1)
// 		return (-1);
// 	return (len + 2);
// }

// char	*put_hex_prefix(unsigned int nbr, t_flags *flags)
// {
// 	char	*str;
// 	char	*prefix;
// 	char	*str_nbr;

// 	prefix = "";
// 	if ((flags->hash) && (nbr != 0))
// 	{
// 		prefix = "0x";
// 		if (flags->specifier == 'X')
// 			prefix = "0X";
// 	}
// 	str_nbr = ft_htoa(nbr, flags->specifier);
// 	if (!str_nbr)
// 		return (NULL);
	
// 	str = ft_strjoin(prefix, str_nbr);
// 	free(str_nbr);
// 	if (!str)
// 		return (NULL);
// 	return (str);
// }

int	alloc_pad(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int no_zero;

	
	pad_len = ft_strlen(nbr);
	no_zero = ft_strncmp(nbr, "0", pad_len);
	if (flags->dot && (flags->precision > pad_len))
		pad_len = flags->precision;
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

void	add_prefix(char **pad, int *nbr_len, t_flags *flags,  int no_zero)
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

void	add_precision(char **pad, int *nbr_len, t_flags *flags)
{
	int	offset;

	offset = 0;
	if (flags->dot && (flags->precision > *nbr_len))
	{
		offset = flags->precision - *nbr_len;
		ft_memmove(&(*pad)[offset], *pad, *nbr_len);
		ft_memset(*pad, '0', offset);
		*nbr_len += offset;
	}
}

void	add_width(char **pad, int nbr_len, t_flags *flags)
{
	int	pad_len;

	pad_len = ft_strlen(*pad);
	if (flags->zero && !flags->precision)
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
	nbr_len = ft_strlen(nbr);
	no_zero = ft_strncmp(nbr, "0", nbr_len);
	ft_memcpy(*pad, nbr, nbr_len);
	add_precision(&(*pad), &nbr_len, flags);
	add_prefix(&(*pad), &nbr_len, flags, no_zero);
	if (!flags->minus)
	{
		ft_memmove(&(*pad)[pad_len - nbr_len], *pad, nbr_len);
		ft_memset(*pad, ' ', pad_len - nbr_len);
		add_width(&(*pad), nbr_len, flags);
	}
}

size_t	read_hex_nbr(va_list *args, t_flags *flags)
{
	if (flags->specifier == 'p')
	{
//		flags->specifier = 'x';
//		flags->hash = 1;
//		flags->nflags += 1;
		return ((size_t)va_arg(*args, void *));
	}
	else
		return (va_arg(*args, unsigned int));
}

int	hex_convert(va_list *args, t_flags *flags)
{
	size_t	nbr;
	int				len;
	char			*str_nbr;
	char			*pad;

	nbr = read_hex_nbr(args, flags);
	str_nbr = ft_htoa(nbr, flags->specifier);
	if (!str_nbr)
		return (-1);
//	if (flags->nflags)
//	{
		len = alloc_pad(&pad, str_nbr, flags);
		if (len != -1)
		{
			fill_pad(&pad, str_nbr, flags);
			len = ft_putstr(pad);
			free(pad);
		}
//	}
//	else
//		len = ft_putstr(str_nbr);
	free(str_nbr);
	return (len);
}
