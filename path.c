/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:01:47 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/07 11:38:11 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		path(char *ptr, va_list param, t_data *data)
{
	int i;

	i = 0;
	if ((i = flags(ptr, data)) > 0)
		return (i);
	else if ((i = length(ptr, data)) > 0)
		return (i);
	else if ((i = width(ptr, data)) > 0)
		return (i);
	else if (*ptr == '%')
		ft_putchar('%');
	else
		conversion(ptr, param, data);
	return (0);
}

int		width(char *ptr, t_data *data)
{
	if (*ptr == '.')
		return (precision(ptr + 1, data) + 1);
	else if (*ptr > '0' && *ptr <= '9')
		return (width_min(ptr, data));
	return (0);
}

int		flags(const char *ptr, t_data *data)
{
	if (*ptr == '#')
		return (flag_sharp(data));
	else if (*ptr == '0')
		return (flag_zero(data));
	else if (*ptr == '-')
		return (flag_minus(data));
	else if (*ptr == '+')
		return (flag_plus(data));
	else if (*ptr == ' ')
		return (flag_space(data));
	return (0);
}

int		length(const char *ptr, t_data *data)
{
	if (*ptr == 'h')
		return (length_h(ptr, data));
	else if (*ptr == 'l')
		return (length_l(ptr, data));
	else if (*ptr == 'j')
		return (length_j(data));
	else if (*ptr == 'z')
		return (length_z(data));
	return (0);
}

int		conversion(const char *ptr, va_list param, t_data *data)
{
	if (*ptr == 's' || *ptr == 'S')
		string_param(ptr, param);
//	else if (*ptr == 'p')
//		void_param(ptr, param);
	else if (*ptr == 'd' || *ptr == 'i' || *ptr == 'D')
		int_param(ptr, param);
	else if (*ptr == 'o' || *ptr == 'O')
		unsignedint_param_oct(ptr, param);
	else if (*ptr == 'u' || *ptr == 'U')
		unsignedint_param(ptr, param);
	else if (*ptr == 'x')
		unsignedint_param_hex(ptr, param);
	else if (*ptr == 'X')
		unsignedint_param_hexc(ptr, param);
	else if (*ptr == 'c' || *ptr == 'C')
		unsignedint_param_hexc(ptr, param);
	return (0);
}
