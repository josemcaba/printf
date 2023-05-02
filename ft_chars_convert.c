/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:19:30 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/02 12:13:02 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding_char(unsigned char c, t_flags *flags)
{
	int	len;

	len = flags->width;
	if (flags->minus)
	{
		ft_putchar_fd(c, 1);
		while (--flags->width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (--flags->width)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	return (len);
}

int	ft_pf_char(va_list *args, t_flags *flags)
{
	unsigned int	c;
	int				len;

	c = va_arg(*args, unsigned int);
	if (flags->width)
		len = padding_char(c, flags);
	else
	{
		ft_putchar_fd(c, 1);
		len = 1;
	}
	return (len);
}

int	padding_str(char *str, t_flags *flags)
{
	char	*s;
	int		s_len;

	s_len = ft_strlen(str);
	if (flags->dot && (flags->width < s_len))
		s_len = flags->width;
	if (!flags->dot && (flags->width > s_len))
		s_len = flags->width;
	s = (char *)malloc(s_len * sizeof(char) + 1);
	ft_memset(s, ' ', s_len);
	s[s_len] = '\0';
	if (flags->dot)
		ft_memcpy(s, str, s_len);
	else if (flags->minus)
		ft_memcpy(s, str, ft_strlen(str));
	else
		ft_memcpy(s + s_len - ft_strlen(str), str, ft_strlen(str));
	ft_putstr_fd(s, 1);
	free(s);
	return (s_len);
}

int	ft_pf_string(va_list *args, t_flags *flags)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	if (flags->nflags)
		len = padding_str(str, flags);
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}
