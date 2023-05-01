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

static void	ft_init_flags(t_flags *flags)
{
	flags->specifier = '\0';
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
}

static void ft_fill_flags(t_flags *flags, char flag)
{
	if (flag == '-')
		flags->minus = 1;
	else if (flag == '0') 
		flags->zero = 1;
	else if (flag == '.')
		flags->dot = 1;
	else if (flag == '#')
		flags->hash = 1;
	else if (flag == ' ')
		flags->space = 1;
	else if (flag == '+')
		flags->plus = 1;
}

static int	ft_convert(va_list *args, t_flags *flags)
{
	int		len;
	
	len = 0;
	if (flags->specifier == 'c')
		len = ft_pf_char(args);
	else if (flags->specifier == 's')
		len = ft_pf_string(args);
	else if (flags->specifier == 'p') 
		len = ft_pf_ptr(args, flags->specifier);
	else if ((flags->specifier == 'x') || (flags->specifier == 'X'))
		len = ft_pf_hex(args, flags);
	else if ((flags->specifier == 'd') \
		|| (flags->specifier == 'i') || (flags->specifier == 'u'))
		len = ft_pf_nbr(args, flags->specifier);
	else if (flags->specifier == '%')
		ft_putchar_fd(flags->specifier, ++len);
	return (len);
}

int	ft_parser(char const *format, va_list *args, int *nflags)
{
	char	*valid_flags;
	int		len;
	t_flags	flags;

	valid_flags = "-0.# +";
    ft_init_flags(&flags);
	while (1)
	{
		if (!ft_strchr(valid_flags, *format))
		{
			flags.specifier = *format;
			len = ft_convert(args, &flags);
			break;
		}
		ft_fill_flags(&flags, *format);
		format++;
		(*nflags)++;
	}
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list args;
	int		len;
	int		nflags;

    va_start(args, format);
	len = 0;
	while(*format)
	{
		nflags = 1;
		if (*format == '%')
			len += ft_parser((++format), &args, &nflags);
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format += nflags;
	}
	va_end(args);
	return(len);
}
