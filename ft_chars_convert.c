/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:19:30 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/30 09:19:30 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_char(va_list *args)
{
	int c;

	c = va_arg(*args, int);
	ft_putchar_fd(c, 1);
	return (1);	
}

int ft_pf_string(va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (len);
}
