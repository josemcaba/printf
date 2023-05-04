/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
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

static int	ft_nbrlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	if (len == 0)
		len++;
	return (len);
}

static void	ft_fillnbr(unsigned int n, char *str)
{
	if (n > 9)
		ft_fillnbr(n / 10, str - 1);
	*str = (n % 10) + '0';
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_nbrlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_fillnbr(n, &str[len - 1]);
	return (str);
}
