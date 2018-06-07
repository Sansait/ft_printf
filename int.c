/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:57:05 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/07 12:58:01 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_param(const char *ptr, va_list param)
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

int		unsignedint_param_hexc(const char *ptr, va_list param)
{
	unsigned int n;

	n = va_arg(param, unsigned int);
	return (0);
}
