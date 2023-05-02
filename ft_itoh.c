/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:52:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 21:49:06 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : n: el entero a convertir.
// Devuelve    : La string que represente el número.
//               NULL si falla la reserva de memoria.
// Descripcion : Utilizando malloc(3), genera una string que represente el
//               valor entero recibido como argumento. Los números negativos
//               tienen que gestionarse.

#include "ft_printf.h"

static int	ft_hnbr_len(size_t n)
{
	int	len;

	len = 1;
	n = n / 16;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_fillhnbr(size_t n, char *str)
{
	hex_base = "0123456789abcdef";
	if (n > 15)
		ft_fillhnbr(n / 16, str - 1);
	*str = hex_base[n % 16];
}

char	*ft_htoa(size_t n)
{
	int		len;
	char	*str;

	len = ft_hnbr_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_fillhnbr(n, &str[len - 1]);
	return (str);
}

