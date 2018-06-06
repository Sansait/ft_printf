/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:01:47 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/06 13:34:27 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	path(char *ptr, va_list arg, int i)
{

}

int		flags(const char *ptr, t_data *data, ...)
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

void	length(const char *ptr, ...)
{
	if (*ptr == 'h')
	{
		if (*(ptr + 1) == 'h')
		{}
		else
		{}
	}
	else if (*ptr == 'l')
	{
		if (*(ptr + 1) == 'l')
		{}
		else
		{}
	}
	else if (*ptr == 'j')
	{}
	else if (*ptr == 'z')
	{}
}

int		conversion(const char *ptr, va_list param, int i)
{
	if (*ptr == 's' || *ptr == 'S')
		string_param(ptr, param);
	else if (*ptr == 'p')
		void_param(ptr, param);
	else if (*ptr == 'd' || *ptr == 'i' || *ptr == 'D')
		int_param(ptr, param, i);
	else if (*ptr == 'o' || *ptr == 'O')
		unsignedint_param_oct(ptr, param);
	else if (*ptr == 'u' || *ptr == 'U')
		unsignedint_param(ptr, param);
	else if (*ptr == 'x')
		unsignedint_param_hex(ptr, param);
	else if (*ptr == 'X')
		unsignedint_param_hexm(ptr, param);
	else if (*ptr == 'c' || *ptr == 'C')
		unsignedint_param_hexm(ptr, param);
}