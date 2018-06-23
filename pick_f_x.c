#include <stdio.h>
#include "ft_printf.h"

int	f_x_sharp(t_data *data, const char *ptr)
{
	if (data->flags[SHARP] && *ptr == 'x')
		print_str("0x", data);
	else if (data->flags[SHARP] && *ptr == 'X')
		print_str("0X", data);
	return (0);
}

int	pick_f_x_two(char *result, t_data *data, const char *ptr)
{
	if (data->precision > 0)
	{
		f_width(data);
		f_x_sharp(data, ptr);
		f_precision(data);
		print_str(result, data);
	}
	else if (data->flags[ZERO])
	{
		f_x_sharp(data, ptr);
		f_zero(data);
		print_str(result, data);
	}
	else if (data->width > 0)
	{
		f_width(data);
		f_x_sharp(data, ptr);
		print_str(result, data);
	}
	else
	{
		f_x_sharp(data, ptr);
		print_str(result, data);
	}
	return (0);
}

int	pick_f_x(va_list param, t_data *data, const char *ptr)
{
	//comportement indéfini precision et largeur = int max
	char	*result;

	result = (*ptr == 'x') ? to_base(va_arg(param, int), BASE_H) : to_base(va_arg(param, int), BASE_HC);
	if ((data->len = ft_strlen(result)) == 1 && *result == '0')
		return (print_str("0", data));
	data->precision = (data->precision > data->len) ? data->precision - (data->len) : 0;
	data->len = (data->flags[SHARP]) ? ft_strlen(result) + 2 : ft_strlen(result);
	if (data->flags[MINUS])
	{
		f_x_sharp(data, ptr);
		f_precision(data);
		print_str(result, data);
		f_width(data);
	}
	else if (data->precision > 0 && data->width > 0)
	{
		f_width(data);
		f_x_sharp(data, ptr);
		f_precision(data);
		print_str(result, data);
	}
	else (pick_f_x_two(result, data, ptr));
	free(result);
	return (0);
}
