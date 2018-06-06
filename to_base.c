#include <stdio.h>
#include "ft_printf.h"

char	*to_base(int nb, char *base)
{
	int		i;
	int		prod;
	int		tmp;
	char	*result;

	if (!base)
		return (NULL);
	if (ft_strcmp(base, BASE_O) == 0)
		prod = 8;
	else 
		prod = 16;
	i = (nb < prod)? 1 : 0;
	tmp = nb;
	while (tmp > 0)
	{
		tmp = tmp / prod;
		i++;
	}
	if (!(result = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
	{
		result[i] = base[nb % prod];
		nb = nb / prod;
	}
	return (result);
}
