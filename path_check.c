/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:36:26 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/19 16:02:02 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_check(char *ptr, t_data *data)
{
	if (*ptr == '.')
		return (precision(ptr + 1, data) + 1);
	else if (*ptr > '0' && *ptr <= '9')
		return (width_min(ptr, data));
	return (0);
}

int		flags_check(const char *ptr, t_data *data)
{
	if (*ptr == '#')
		return (flag_sharp(data));
	else if (*ptr == '0')
		return (flag_zero(data, ptr));
	else if (*ptr == '-')
		return (flag_minus(data));
	else if (*ptr == '+')
		return (flag_plus(data));
	else if (*ptr == ' ')
		return (flag_space(data));
	return (0);
}

int		length_check(const char *ptr, t_data *data)
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

int		check_s(t_data *data)
{
	if (data->length[H] > 0 || data->length[L] > 1 || data->length[J] > 0 ||
			data->length[Z] > 0)
		return (-1);
	if (data->flags[SHARP] > 0 || data->flags[ZERO] > 0 ||
			data->flags[SPACE] > 0 || data->flags[PLUS] > 0)
		return (-1);
}

int		conversion_check(const char *ptr, t_data *data)
{
	if (*ptr == 's' || *ptr == 'S')
		return (check_s(data));
	else if (*ptr == 'p')
		void_param(ptr);
	else if (*ptr == 'd' || *ptr == 'i' || *ptr == 'D')
		int_param(ptr);
	else if (*ptr == 'o' || *ptr == 'O')
		unsignedint_param_oct(ptr);
	else if (*ptr == 'u' || *ptr == 'U')
		pick_f_u(data);
	else if (*ptr == 'x' || *ptr == 'X')
		pick_f_x(data, ptr);
	else if (*ptr == 'c' || *ptr == 'C')
		pick_f_c(data);
	return (0);
}

int		path_check(char *ptr, t_data *data)
{
	int i;

	i = 0;
	if ((i = flags_check(ptr, data)) > 0)
		return (i);
	else if ((i = length_check(ptr, data)) > 0)
		return (i);
	else if ((i = width_check(ptr, data)) > 0)
		return (i);
	else if (*ptr == '%')
		return (0);
	else
		conversion_check(ptr, data);
	return (0);
}