/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:36:40 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/30 08:36:42 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
	char	specifier;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int 	space;
	int		plus;
	int		width;
}	t_flags;

int	ft_printf(char const *, ...);
int	ft_pf_char(va_list *args);
int	ft_pf_string(va_list *args);
int	ft_pf_ptr(va_list *args, char specifier);
int	ft_pf_hex(va_list *args, t_flags *flags);
int	ft_pf_nbr(va_list *args, char specifier);

#endif