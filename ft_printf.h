/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:36:40 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/08 23:39:31 by jocaball         ###   ########.fr       */
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
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *s);
void	ft_init_flags(t_flags *flags);
void	ft_read_flags(t_flags *flags, char const *format);
int		ft_pf_char(va_list *args, t_flags *flags);
int		ft_pf_string(va_list *args, t_flags *flags);
int		ft_pf_ptr(va_list *args, char specifier);
int		hex_convert(va_list *args, t_flags *flags);
int		ft_pf_nbr(va_list *args, t_flags *flags);
int		ft_pf_uint(va_list *args, t_flags *flags);
int		ft_pf_char_na(t_flags *flags);
int		ft_putprefix(int nbr, t_flags *flags);
int		padding_nbr(char *str, t_flags *flags);
char	*ft_uitoa(unsigned int n);
char	*ft_htoa(size_t n, int specifier);
void	add_precision(char **pad, int *nbr_len, t_flags *flags, int zero);
void	fill_pad_int(char **pad, char *nbr, t_flags *flags);
int	alloc_pad_int(char **pad, char *nbr, t_flags *flags);

#endif