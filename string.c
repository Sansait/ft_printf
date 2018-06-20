/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:13:59 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/20 16:46:35 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pick_f_s(const char *ptr, t_data *data, va_list param)
{
	char *str;
	if (*ptr == 'S' || (*ptr == 's' && data->flags[L] == 1))
	{
		str = va_arg(param, char*);
	}

	return (0);
}

int		string_param(t_data *data, va_list param)
{
	char *str;

	str = va_arg(param, char*);
	print_str(str, data);
	return (0);
}

void	print_str(const char *str, t_data *data)
{//un putstr qui incrémente notre valeur de retour
	while (*str)
	{
		print_char(*str, data);
		++str;
	}
}

void	print_char(char c, t_data *data)
{
	ft_putchar(c);
	++data->ret_val;
}
