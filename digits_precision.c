#include "ft_printf.h"
#include <stdio.h>

int	f_precision(t_data *data)
{
	int	precision;

	precision = data->precision;
	if (precision > 0)
		while (--precision >= 0)
		{
			ft_putchar('0');
			++data->ret_val;
		}
	return (0);
}

int	f_zero(t_data *data)
{
	if (data->zero > 0)
		while(--data->zero >= 0)
		{
			ft_putchar('0');
			++data->ret_val;
		}
	return (0);
}

int	f_width(t_data *data)
{
	int	width;

	width = data->width - (data->len + data->precision);
	printf("width = %d\n", width);
	printf("data->len %zu\n", data->len);
	printf("data->precision %d\n", data->precision);
	if (width > 0)
		while (--width >= 0)
		{
			ft_putchar(' ');
			++data->ret_val;
		}
	return (0);
}
