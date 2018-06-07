//verifier qu'on gere biens les flages de type hh, h, l, ll, j et z au depart
//se mettre daccord sur les prototypes des micor fonctions
#include "ft_printf.h"

void	ft_put_u(unsigned int nb)
{
	if (nb / 10)
		ft_put_u(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int		pick_f_u(va_list param, t_data *data)
{
	unsigned int	nb;

	nb = va_arg(param, unsigned int);
	if (data->flags[MINUS])
	{//prevaut sur la largeur
		if (data->precision > 0)
		{
			//unsigned flag - + data precision 
		}
		//fonction : unsigned flag - 
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
	return (0);
}
