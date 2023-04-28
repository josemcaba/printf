#include "./libft/libft.h"
#include <stdarg.h>

void	ft_putnbr_len(int n, int *len)
{
	int	digit;
	int sign;

	(*len)++;
	sign = 1;
	if (n < 0)
	{
		(*len)++;	
		ft_putchar_fd('-', 1);
		sign = -1;
	}
	if ((n < -9) || (n > 9))
		ft_putnbr_len(sign * (n / 10), len);
	digit = sign * (n % 10) + '0';
	ft_putchar_fd(digit, 1);
}

static void	ft_putptr_fd(size_t n, int num_digits)
{
	char	*hex_base;
	int		digit;

	hex_base = "0123456789abcdef";

	if (n > 15)
		ft_putptr_fd((n / 16), --num_digits);
	digit = n % 16;
	ft_putchar_fd(hex_base[digit], 1);
}

static int ft_pf_onechar(va_list *args)
{
	int c;

	c = va_arg(*args, int);
	ft_putchar_fd(c, 1);
	return (1);	
}

static int ft_pf_string(va_list *args)
{
	char *s;

	s = (char *)va_arg(*args, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

static int ft_pf_pointer(va_list *args)
{
	size_t	p;

	p = va_arg(*args, size_t);
	ft_putstr_fd("0x", 1);
	ft_putptr_fd(p, sizeof(size_t));
	return (sizeof(size_t));
}

int ft_convert(char specifier, va_list *args)
{
	int		len;
	int		d;
	
	if (specifier == 'c')
		len = ft_pf_onechar(args);
	else if (specifier == 's')
		len = ft_pf_string(args);
	else if (specifier == 'p')
		len =ft_pf_pointer(args);
	else if (specifier == 'd')
	{
		d = va_arg(*args, int);
		len = 0;
		ft_putnbr_len(d, &len);
		return (len);
	}
	else
	{
		ft_putchar_fd(specifier, 1);
		return (1);
	}
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list args;
	int		count;

    va_start(args, format);
	count = 0;
	while(*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		else
			count += ft_convert(*(++format), &args);
		format++;
	}
	va_end(args);
	return(count);
}

