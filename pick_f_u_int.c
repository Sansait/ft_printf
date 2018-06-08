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

int	f_u_precision(unsigned int nb, t_data *data)
{
	int	precision;

	precision = data->precision;
	if (precision > 0)
		while (--precision >= 0)
			ft_putchar('0');
	return (0);
}

int	f_u_width(unsigned int nb, t_data *data)
{
	int	width;

	width = data->width - (data->len + data->precision);
	if (width > 0)
		while (--width >= 0)
			ft_putchar(' ');
	return (0);
}

int	pick_f_u(va_list param, t_data *data)
{//fonction appellee dans path, variable convertion
	//la precision prevaut sur le flag 0
	unsigned int	nb;

	nb = va_arg(param, unsigned int);
	data->len = len_u(nb);
	data->precision = (data->precision > data->len) ? data->precision - data->len : 0;
	if (data->flags[MINUS])
	{	
		f_u_precision(nb, data);
		ft_put_u(nb);
		f_u_width(nb, data);
	}
	else if (data->precision > 0 && data->width > 0)
	{//nombre minimum de chiffres
		f_u_width(nb, data);
		f_u_precision(nb, data);
		ft_put_u(nb);
	}
	else if (data->precision > 0)
	{
		f_u_precision(nb, data);
		ft_put_u(nb);
	}
	else if (data->flags[ZERO])
	{//prevaut sur la largeur 
		printf("zero precision-> %d\n", data->precision);
		ft_put_u(nb);
	}
	else if (data->width > 0)
	{
		f_u_width(nb, data);
		ft_put_u(nb);
	}
	else
	{//cas normal
		printf("data->flags : %d\n", data->flags[MINUS]);
		ft_put_u(nb);
	}
	return (0);
}
