/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:19:30 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/03 14:10:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding_str(char *str, t_flags *flags)
{
	char	*s;
	int		s_len;
	int		p_len;

	s_len = ft_strlen(str);
	if (flags->dot)
		s_len = flags->precision;
	p_len = s_len;
	if (flags->width > p_len)
		p_len = flags->width;
	s = (char *)malloc(p_len * sizeof(char) + 1);
	if (!s)
		return (0);
	ft_memset(s, ' ', p_len);
	s[p_len] = '\0';
	if (flags->minus)
		ft_memcpy(s, str, s_len);
	else
		ft_memcpy(s + p_len - s_len, str, s_len);
	if (ft_putstr(s) == -1)
		p_len = -1;
	free(s);
	return (p_len);
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
		len = ft_putstr(str);
	return (len);
}
