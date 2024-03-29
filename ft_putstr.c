/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:06:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/11 20:32:01 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : s: La cadena a enviar.
// Devuelve	   : Longitud de lo enviado a la salida estandar (fd = 1).
//               Si se produce un error devuelve -1
// Descripcion : Envía la cadena ’s’ a la salida estandard.

#include "ft_printf.h"

ssize_t	ft_putstr(char *s)
{
	ssize_t	len;

	len = write(1, s, ft_strlen(s));
	return (len);
}
