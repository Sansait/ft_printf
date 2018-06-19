/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:13:59 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/19 12:41:02 by jlehideu         ###   ########.fr       */
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

void	print_str(const char *str, t_data *data)
{//un putstr qui incrémente notre valeur de retour
	while (*str)
	{
		ft_putchar(*str);
		++data->ret_val;
		++str;
	}
}

void	print_char(char c, t_data *data)
{
	ft_putchar(c);
	++data->ret_val;
}
