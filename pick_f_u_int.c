//envoyer chier l'utilisateur si les flags ne sont pas copmatibles
//on ne recupere pas la bonne valeur en appelant va_arg(param, type)
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

int		f_u(unsigned int nb, t_data *data)
{
	ft_put_u(nb);
	return (0);
}

int		f_u_min(unsigned int nb, t_data *data)
{
	size_t			len;

	printf("MIN\n");
	len = len_u(nb);
	ft_put_u(nb);
	if (len < data->width)
		while (++len <= data->width)
			ft_putchar(' ');
	return (0);
}

int		pick_f_u(va_list param, t_data *data)
{//fonction appellee dans path, variable convertion
	unsigned int	nb;

	nb = va_arg(param, unsigned int);
	if (data->flags[MINUS])
	{	
		printf("data width -> %d\n", data->precision);
		if (data->width > 0)
			f_u_min(nb, data);
		else
			f_u(nb, data);
	}
	else if (data->flags[ZERO])
	{//prevaut sur la largeur
		if (data->precision > 0)
		{
			//unsigned flag 0 + data precision
		}
		//fonction unsigned flag 0
	}
	else if (data->precision > 0)
	{//nombre minimum de chiffres
		if (data->width > 0)//taille minimum du champ
		{
			//une fonction : data precision + data width
		}
		else
		{
			//une fonction : data precision tout court
		}
	}
	else
	{//cas normal
		printf("data->flags : %d\n", data->flags[MINUS]);
		f_u(nb, data);
	}
	return (0);
}
