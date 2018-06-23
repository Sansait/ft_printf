#include "ft_printf.h"
#include <stdio.h>

void	ft_put_u(unsigned int nb, t_data *data)
{
	if (nb / 10)
		ft_put_u(nb / 10, data);
	ft_putchar(nb % 10 + 48);
	data->ret_val++;
}

size_t	len_u(unsigned int nb)
{
	size_t		len;
	long int	prod;

	len = 0;
	prod = 1;
	while (nb / prod >= 1)
	{
		prod *= 10;
		++len;
	}
	return (len);
}

int	pick_f_u(va_list param, t_data *data)
{
	unsigned int	nb;

	nb = va_arg(param, unsigned int);
	data->len = len_u(nb);
	data->precision = (data->precision > data->len) ? data->precision - data->len : 0;
	if (data->flags[MINUS])
	{	
		printf("MINUS\n");
		printf("precision -> %d\n", data->precision);
		f_precision(data);
		ft_put_u(nb, data);
		f_width(data);
	}
	else if (data->precision > 0 && data->width > 0)
	{
		f_width(data);
		f_precision(data);
		ft_put_u(nb, data);
	}
	else if (data->precision > 0)
	{
		f_width(data);
		f_precision(data);
		ft_put_u(nb, data);
	}
	else if (data->flags[ZERO])
	{ 
		f_width(data);
		ft_put_u(nb, data);
	}
	else if (data->width > 0)
	{
		f_width(data);
		ft_put_u(nb, data);
	}
	else
		ft_put_u(nb, data);
	return (0);
}
