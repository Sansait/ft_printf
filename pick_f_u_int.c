//envoyer chier l'utilisateur si les flags ne sont pas copmatibles
//on ne recupere pas la bonne valeur en appelant va_arg(param, type)
//FIX 0
#include "ft_printf.h"
#include <stdio.h>

void	ft_put_u(unsigned int nb)
{
	if (nb / 10)
		ft_put_u(nb / 10);
	ft_putchar(nb % 10 + 48);
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

int	f_u_precision(t_data *data)
{
	int	precision;

	precision = data->precision;
	if (precision > 0)
		while (--precision >= 0)
			ft_putchar('0');
	return (0);
}

int	f_u_zero(t_data *data)
{
	if (data->zero > 0)
		while(--data->zero >= 0)
			ft_putchar('0');
	return (0);
}

int	f_u_width(t_data *data)
{
	int	width;

	width = data->width - (data->len + data->precision);
	if (width > 0)
		while (--width >= 0)
			ft_putchar(' ');
	return (0);
}

int	pick_f_u(va_list param, t_data *data)
{
	unsigned int	nb;

	nb = va_arg(param, unsigned int);
	data->len = len_u(nb);
	data->precision = (data->precision > data->len) ? data->precision - data->len : 0;
	if (data->flags[MINUS])
	{	
		f_u_precision(data);
		ft_put_u(nb);
		f_u_width(data);
	}
	else if (data->precision > 0 && data->width > 0)
	{
		f_u_width(data);
		f_u_precision(data);
		ft_put_u(nb);
	}
	else if (data->precision > 0)
	{
		f_u_width(data);
		f_u_precision(data);
		ft_put_u(nb);
	}
	else if (data->flags[ZERO])
	{ 
		f_u_width(data);
		ft_put_u(nb);
	}
	else if (data->width > 0)
	{
		f_u_width(data);
		ft_put_u(nb);
	}
	else
		ft_put_u(nb);
	return (0);
}
