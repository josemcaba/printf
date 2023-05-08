/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/04 23:54:28 by jocaball         ###   ########.fr       */
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

int	ft_pf_nbr(va_list *args, t_flags *flags)
{
	int		len;
	int		nbr;
	char	*str;

	nbr = va_arg(*args, int);
	str = ft_putprfx(nbr, flags);
	if (!str)
		return (-1);
	if (flags->nflags)
		len = padding_nbr(str, flags);
	else
		len = ft_putstr(str);
	free(str);
	return (len);
}
