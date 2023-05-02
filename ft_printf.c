/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:36:56 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/30 10:37:59 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(va_list *args, t_flags *flags)
{
	int		len;
	
	len = 0;
	if (flags->specifier == 'c')
		len = ft_pf_char(args, flags);
	else if (flags->specifier == 's')
		len = ft_pf_string(args, flags);
	else if (flags->specifier == 'p') 
		len = ft_pf_ptr(args, flags->specifier);
	else if ((flags->specifier == 'x') || (flags->specifier == 'X'))
		len = ft_pf_hex(args, flags);
	else if ((flags->specifier == 'd') || (flags->specifier == 'i'))
		len = ft_pf_nbr(args, flags);
	else if (flags->specifier == 'u')
		len = ft_pf_uint(args, flags);
	else if (flags->specifier == '%')
		ft_putchar_fd(flags->specifier, ++len);
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list args;
	int		len;
	t_flags	flags;

    va_start(args, format);
	len = 0;
	while(*format)
	{
		flags.nflags = 0;
		if (*format == '%')
		{
			ft_read_flags(&flags, ++format);
			len += ft_convert(&args, &flags);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format += (1 + flags.nflags);
	}
	va_end(args);
	return(len);
}
