/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:01:47 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/31 18:38:14 by sklepper         ###   ########.fr       */
.fr       */
=======
/*   Updated: 2018/05/31 18:21:29 by sklepper         ###   ########.fr       */
>>>>>>> 8794c8696c0e62dc79cb42be1ccf32d63a4a3313
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	path(char *ptr, va_list arg, int i)
{

}

void	flags(const char *ptr, ...)
{
	if (*ptr == '#')
	{}
	else if (*ptr == '0')
	{}
	else if (*ptr == '-')
	{}
	else if (*ptr == '+')
	{}
	else if (*ptr == ' ')
	{}
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