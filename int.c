/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:57:05 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/31 18:27:49 by sklepper         ###   ########.fr       */
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
	ft_putnbr(n);
	return (0);
}