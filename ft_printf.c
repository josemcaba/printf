/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:36:56 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/30 08:37:59 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char specifier, va_list *args)
{
	int	len;
	
	len = 0;
	if (specifier == 'c')
		len = ft_pf_char(args);
	else if (specifier == 's')
		len = ft_pf_string(args);
	else if ((specifier == 'p') || (specifier == 'x') || (specifier == 'X'))
		len = ft_pf_hex(args, specifier);
	else if ((specifier == 'd') || (specifier == 'i') || (specifier == 'u'))
		len = ft_pf_nbr(args, specifier);
	else if (specifier == '%')
		ft_putchar_fd(specifier, ++len);
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list args;
	int		len;

    va_start(args, format);
	len = 0;
	while(*format)
	{
		if (*format == '%')
			len += ft_convert(*(++format), &args);
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return(len);
}
