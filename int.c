/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:57:05 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/31 18:38:14 by sklepper         ###   ########.fr       */
.fr       */
=======
/*   Updated: 2018/05/31 18:23:20 by sklepper         ###   ########.fr       */
>>>>>>> 8794c8696c0e62dc79cb42be1ccf32d63a4a3313
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_param(const char *ptr, va_list param, int i)
{
	int n;

	n = va_arg(param, int);
	ft_putnbr(n);
	return (0);
}

int		unsignedint_param(const char *ptr, va_list param)
{
	unsigned int n;

	n = va_arg(param, unsigned int);
	return (0);
}

int		unsignedint_param_oct(const char *ptr, va_list param)
{
	unsigned int n;

	n = va_arg(param, unsigned int);
	return (0);
}

int		unsignedint_param_hex(const char *ptr, va_list param)
{
unsigned int n;

	n = va_arg(param, unsigned int);
	return (0);
}

int		unsignedint_param_hexm(const char *ptr, va_list param)
{
	unsigned int n;

	n = va_arg(param, unsigned int);
	return (0);
}
