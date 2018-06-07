/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:13:59 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/06 17:43:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_param(const char *ptr, va_list param)
{
	char *str;

	str = va_arg(param, char*);
	ft_putstr(str);
	return (0);
}