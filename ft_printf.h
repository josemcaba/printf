/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:36:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/11 20:31:17 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	char	specifier;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	int		nflags;
	int		negative;
}	t_flags;

int		ft_printf(char const *format, ...);
int		pf_char_convert(va_list *args, t_flags *flags);
int		pf_char_convert_narg(t_flags *flags);
int		pf_str_convert(va_list *args, t_flags *flags);
int		pf_int_convert(va_list *args, t_flags *flags);
void	pf_fill_pad_int(char **pad, char *nbr, t_flags *flags);
void	pf_add_prfx_int(char **pad, int *nbr_len, t_flags *flags, int no_zero);
int		pf_alloc_pad_int(char **pad, char *nbr, t_flags *flags);
void	pf_add_precision(char **pad, int *nbr_len, t_flags *flags, int zero);
void	pf_add_width_int(char **pad, int nbr_len, t_flags *flags);
int		pf_uint_convert(va_list *args, t_flags *flags);
int		pf_hex_convert(va_list *args, t_flags *flags);
void	pf_flags_read(t_flags *flags, char const *format);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *s);
char	*ft_htoa(size_t n, int specifier);
char	*ft_uitoa(unsigned int n);

#endif
