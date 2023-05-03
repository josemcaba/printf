/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:36:56 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/02 19:16:37 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(char c)
{
	ssize_t	len;

	len = write(1, &c, 1);
	return (len);
}

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
		len = ft_putchar(flags->specifier);
	return (len);
}

int	ft_parse_and_print(char const *format, t_flags *flags, va_list *args)
{
	int	len;

	if (*format == '%')
	{
		ft_read_flags(flags, ++format);
		len = ft_convert(args, flags);
		if (len == -1)
			return (-1);
	}
	else
	{
		len = ft_putchar(*format);
		if (len == -1)
			return (-1);
	}
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		t_len;
	t_flags	flags;

	va_start (args, format);
	len = 0;
	while (*format)
	{
		flags.nflags = 0;
		t_len = ft_parse_and_print(format, &flags, &args);
		if (t_len == -1)
			return (-1);
		len += t_len;
		if (*format == '%')
			format += 2;
		else
			format += 1;
		format += flags.nflags;
	}
	va_end(args);
	return (len);
}
