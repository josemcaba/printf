/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/08 22:26:41 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	str_nbr = ft_itoa(nbr);
	if (!str_nbr)
		return (NULL);
	str = ft_strjoin(str_prfx, str_nbr);
	free(str_nbr);
	if (!str)
		return (NULL);
	return (str);
}

int	alloc_pad_int(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int no_zero;

	pad_len = ft_strlen(nbr);
	if (*nbr == '-')
	{
		flags->negative = 1;
		pad_len--;
	}
	no_zero = ft_strncmp(nbr, "0", pad_len);
	if (flags->dot && (flags->precision > pad_len))
		pad_len = flags->precision;
	if (flags->negative && no_zero)
		pad_len++;
	if (flags->space && !flags->negative)
		pad_len++;
	if (flags->plus && !flags->negative)
		pad_len++;
	if (flags->width > pad_len)
		pad_len = flags->width;
	*pad = (char *)ft_calloc(pad_len + 1, sizeof(char));
	if (!*pad)
		return (-1);
	ft_memset(*pad, ' ', pad_len);
	return (pad_len);
}

void	add_prefix_int(char **pad, int *nbr_len, t_flags *flags, int no_zero)
{
	if ((flags->negative) && (no_zero))
	{
		ft_memmove(&(*pad)[1], *pad, *nbr_len);
		ft_memcpy(*pad, "-", 1);
		*nbr_len += 1;
	}
	(void)no_zero;
	if (flags->space && !flags->negative)
	{
		ft_memmove(&(*pad)[1], *pad, *nbr_len);
		ft_memcpy(*pad, " ", 1);
		*nbr_len += 1;
	}
	if (flags->plus && !flags->negative)
	{
		ft_memmove(&(*pad)[1], *pad, *nbr_len);
		ft_memcpy(*pad, "+", 1);
		*nbr_len += 1;
	}
}

void	add_width_int(char **pad, int nbr_len, t_flags *flags)
{
	int	pad_len;

	pad_len = ft_strlen(*pad);
	if (flags->zero && !flags->precision)
	{
		ft_memset(*pad, '0', pad_len - nbr_len);
		if (ft_strchr(*pad, '-'))
		{
			*ft_strchr(*pad, '-') = '0';
			(*pad)[0] = '-';
		}
	}
}

void	fill_pad_int(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int	nbr_len;
	int	no_zero;

	pad_len = ft_strlen(*pad);
	nbr_len = ft_strlen(nbr) - flags->negative;
	no_zero = ft_strncmp(nbr, "0", nbr_len);
	ft_memcpy(*pad, nbr + flags->negative, nbr_len);
	add_precision(&(*pad), &nbr_len, flags);
	add_prefix_int(&(*pad), &nbr_len, flags, no_zero);
	if (!flags->minus)
	{
		ft_memmove(&(*pad)[pad_len - nbr_len], *pad, nbr_len);
		ft_memset(*pad, ' ', pad_len - nbr_len);
		add_width_int(&(*pad), nbr_len, flags);
	}
}

int	ft_pf_nbr(va_list *args, t_flags *flags)
{
	size_t	nbr;
	int				len;
	char			*str_nbr;
	char			*pad;

	nbr = va_arg(*args, int);
	str_nbr = ft_itoa(nbr);
	if (!str_nbr)
		return (-1);
//	if (flags->nflags)
//	{
		len = alloc_pad_int(&pad, str_nbr, flags);
		if (len != -1)
		{
			fill_pad_int(&pad, str_nbr, flags);
			len = ft_putstr(pad);
			free(pad);
		}
//	}
//	else
//		len = ft_putstr(str_nbr);
	free(str_nbr);
	return (len);
}

// int	ft_pf_nbr(va_list *args, t_flags *flags)
// {
// 	int		len;
// 	int		nbr;
// 	char	*str;

// 	nbr = va_arg(*args, int);
// 	str = ft_putprfx(nbr, flags);
// 	if (!str)
// 		return (-1);
// 	if (flags->nflags)
// 		len = padding_nbr(str, flags);
// 	else
// 		len = ft_putstr(str);
// 	free(str);
// 	return (len);
// }


