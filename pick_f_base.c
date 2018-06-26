#include <stdio.h>
#include "ft_printf.h"

static int	f_x_sharp(t_data *data, const char *ptr)
{
	if (data->flags[SHARP] > 0 && *ptr == 'x')
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

char	*determine_xo_call(const char *ptr, va_list param)
{
	char	*result;

	if (*ptr == 'x')
		result = to_base(va_arg(param, int), BASE_H);
	else if (*ptr == 'X')
		result = to_base(va_arg(param, int), BASE_HC);
	else if (*ptr == 'o')
		result = to_base(va_arg(param, int), BASE_O);
	else
		return (NULL);
	return (result);
}

int	pick_f_base(va_list param, t_data *data, const char *ptr)
{
	//comportement indéfini precision et largeur = int max
	char	*result;

	if (!(result = determine_xo_call(ptr, param)))
		return (-1);
	if ((data->len = ft_strlen(result)) == 1 && *result == '0')
		return (print_str("0", data));
	data->len = (data->flags[SHARP] && (*ptr == 'x' || *ptr == 'X')) ? data->len + 2 : data->len;
	data->len = (data->flags[SHARP] && (*ptr == 'o' || *ptr == 'O')) ? ++data->len : data->len;
	data->precision = (data->precision > data->len) ? data->precision - (data->len) : 0;
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
