#include "ft_printf.h"

int ft_putprefix(int nbr, t_flags *flags)
{
	int	len;

	len = 0;
	if ((nbr > 0) && (flags->plus))
	{
		ft_putchar_fd('+', 1);
		len = 1;
	}
	else if ((nbr > 0) && (flags->space))
	{
		ft_putchar_fd(' ', 1);
		len = 1;
	}
	else if ((flags->hash) && (nbr != 0))
	{
		if (flags->specifier == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		len = 2;
	}
	return (len);
}
