#include <stdio.h>
#include "ft_printf.h"

int	pick_f_x(va_list param, t_data *data)
{
	char	*result;

	result = (to_base(va_arg(param, int), BASE_H));
	printf("result -> %s\n", result);
/*	if (data->flags[MINUS])
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
		ft_put_u(nb);*/
	return (0);
}
