#include <stdio.h>
#include "ft_printf.h"

static char	*ft_swap_chars(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++j])
		str[++i] = str[j];
	str[--j] = '\0';
	return (str);
}

char	*to_base(unsigned int nb, char *base)
{
	int				i;
	long long int	prod;
	long long int	tmp;
	char			*result;

	if (!base)
		return (NULL);
	prod = (ft_strcmp(base, BASE_O) == 0) ? 8 : 16;
	i = (nb < prod)? 1 : 0;
	tmp = nb;
	while (tmp > 0)
	{
		tmp = tmp / prod;
		i++;
	}
	if (!(result = ft_strnew(i)))
		return (NULL);
	result[i] = '\0';
	while (--i >= 0)
	{
		result[i] = base[nb % prod];
		nb = nb / prod;
	}
	if (result[++i] == '0' && nb != 0)
		result = ft_swap_chars(result);
	return (result);
}
