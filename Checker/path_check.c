/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:36:26 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/20 15:55:16 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		width_check(const char *ptr, t_data *data)
{
	if (*ptr == '.')
	{
		if (data->precision != 0)
			return (-1);
		return (precision(ptr + 1, data) + 1);
	}
	else if (*ptr > '0' && *ptr <= '9')
	{
		if (data->width != 0)
			return (-1);
		return (width_min(ptr, data));
	}
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


int		conversion_check(const char *ptr, t_data *data)
{
	if (*ptr == 's' || *ptr == 'c')
		return (check_s(data));
	else if (*ptr == 'S' || *ptr == 'C' || *ptr == 'p')
		return (check_s_c_p(data));
	else if (*ptr == 'd' || *ptr == 'i' || *ptr == 'D')
		return (check_di(data));
	else if (*ptr == 'o' || *ptr == 'O' || *ptr == 'x' || *ptr == 'X')
		return (check_ox(data));
	else if (*ptr == 'u' || *ptr == 'U')
		return (check_u(data));
	return (-1);
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

int		check(const char *str)
{
	t_data	data;
	const char	*ptr;
	int		i;

	ptr = str;
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		init_struct(&data);
		ptr += 1;
		while (flags_check(ptr, &data) > 0)
			ptr += 1;
		while ((i = width_check(ptr, &data)) > 0)
			ptr += i;
		if (i == -1 || conversion_check(ptr, &data) == -1)
			return (-1);
		str = ptr + 1;
	}
	return (0);
}