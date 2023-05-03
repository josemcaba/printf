/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:14:11 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/03 13:47:54 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->specifier = '\0';
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->nflags = 0;
}

static void	ft_fill_flags(t_flags *flags, char flag)
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

void	ft_read_flags(t_flags *flags, char const *format)
{
	int		i;
	char	*valid_flags;

	valid_flags = "-0.# +";
	ft_init_flags(flags);
	i = 0;
	while (ft_strchr(valid_flags, format[i]))
	{
		ft_fill_flags(flags, format[i]);
		i++;
	}
	flags->width = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		i++;
	flags->nflags = i;
	if (format[i] == '.')
	{
		i++;
		flags->dot = 1;
		flags->precision = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
		flags->nflags = i;
	}
	flags->specifier = format[i];
}
