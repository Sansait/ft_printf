#include <stdio.h>
#include "ft_printf.h"

int	f_x_sharp(t_data *data, const char *ptr)
{
	if (data->flags[SHARP] && *ptr == 'x')
		ft_putstr("0x");
	else if (data->flags[SHARP] && *ptr == 'X')
		ft_putstr("0X");
	if (data->flags[SHARP] && (*ptr == 'x' || *ptr == 'X'))
		data->ret_val += 2;
	return (0);
}

int	pick_f_x_two(char *result, t_data *data, const char *ptr)
{
	if (data->precision > 0)
	{
		printf("PRECISION -> %d\n", data->precision);
		f_width(data);
		f_x_sharp(data, ptr);
		f_precision(data);
		print_str(result, data);
	}
	else if (data->flags[ZERO])
	{//ne fonctionne pas avec 012.14x 
	//mauvaise valeur de retour avec une précision
		printf("ZERO\n");
		f_width(data);
		f_x_sharp(data, ptr);
		print_str(result, data);
	}
	else if (data->width > 0)
	{
		printf("WIDTH\n");
		f_width(data);
		f_x_sharp(data, ptr);
		print_str(result, data);
	}
	else
	{
		printf("ELSE\n");
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
	data->len = ft_strlen(result);
	data->precision = (data->precision > data->len) ? data->precision - (data->len): 0;
	data->len = (data->flags[SHARP]) ? ft_strlen(result) + 2 : ft_strlen(result);
	if (data->flags[MINUS])
	{//OP
		printf("MINUS\n");
		f_x_sharp(data, ptr);
		f_precision(data);
		ft_putstr(result);
		f_width(data);
	}
	else if (data->precision > 0 && data->width > 0)
		{//OP
		printf("data->precision -> %d\n, data->width -> %d\n", data->precision, data->width);
		f_width(data);
		f_x_sharp(data, ptr);
		f_precision(data);
		print_str(result, data);
	}
	else (pick_f_x_two(result, data, ptr));
	free(result);
	return (0);
}
