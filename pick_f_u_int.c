//verifier qu'on gere biens les flages de type hh, h, l, ll, j et z au depart
//se mettre daccord sur les prototypes des micor fonctions
#include "ft_printf.h"

static void ft_put_u(unsigned int nb)
{
	if (nb / 10)
		ft_put_u_nbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

static unsigned int	int_to_u(int nb)
{
	//valeur max unsigned int 4294967296
	unsigned int	result;
	unsigned int	result2;

	if (nb < 0)
		result = 4294967296 + nb;
	result2 = nb;
}

static int				pick_f_u(const char *ptr, va_list param, t_data *data)
{
	//sharp n'a aucun effet sur un u
	//plus n'a aucun effet sur un u
	//space n'a aucun effet sur un u
	int	nb;

	nb = ft_atoi(ptr);//nombre a envoyer aux fonctions
	if (data->flag[MINUS])
	{//prevaut sur la largeur
		if (data->precision > 0)
		{
			//unsigned flad - plus data precision 
		}
		//fonction : unsigned flag - 
	}
	else if (data->flag[ZERO])
	{//prevaut sur la largeur
		if (data->precision > 0)
		{
			//unsigned flag 0 plus data precision
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
