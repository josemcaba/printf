/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:36:40 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/09 14:15:10 by jocaball         ###   ########.fr       */
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
int		char_convert(va_list *args, t_flags *flags);
int		char_convert_narg(t_flags *flags);
int		str_convert(va_list *args, t_flags *flags);
int		int_convert(va_list *args, t_flags *flags);
void	fill_pad_int(char **pad, char *nbr, t_flags *flags);
void	add_prefix_int(char **pad, int *nbr_len, t_flags *flags, int no_zero);
int		alloc_pad_int(char **pad, char *nbr, t_flags *flags);
void	add_precision(char **pad, int *nbr_len, t_flags *flags, int zero);
void	add_width_int(char **pad, int nbr_len, t_flags *flags);
int		uint_convert(va_list *args, t_flags *flags);
int		hex_convert(va_list *args, t_flags *flags);
void	flags_read(t_flags *flags, char const *format);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *s);
char	*ft_htoa(size_t n, int specifier);
char	*ft_uitoa(unsigned int n);

#endif