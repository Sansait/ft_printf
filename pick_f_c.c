// NO SHARP
// NO PRECISION
// MINUS -> bancks on the left
// 0, overrided by - 
// width -> usual
#include "ft_printf.h"
#include <stdio.h>

int	pick_f_c(va_list param, t_data *data)
{
	char	result;

	result = va_arg(param, int);
	printf("result -> %c\n", result);
	return (0);
}
