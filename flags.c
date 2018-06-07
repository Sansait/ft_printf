/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:19:16 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/07 16:58:18 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_sharp(const char *ptr, t_data *data)
{
	if (*ptr == '#')
	{
		data->flags[SHARP] = 1;
		return (1);
	}
	data->flags[SHARP] = 0;
	return (0);
}

int		flag_zero(const char *ptr, t_data *data)
{
	if (*ptr == '0')
	{
		data->flags[ZERO] = 1;
		return (1);
	}
	data->flags[ZERO] = 0;
	return (0);
}

int		flag_minus(const char *ptr, t_data *data)
{
	if (*ptr == '-')
	{
		data->flags[MINUS] = 1;
		return (1);
	}
	data->flags[MINUS] = 0;
	return (0);
}

int		flag_plus(const char *ptr, t_data *data)
{
	if (*ptr == '+')
	{
		data->flags[PLUS] = 1;
		return (1);
	}
	data->flags[PLUS] = 0;
	return (0);
}

int		flag_space(const char*ptr, t_data *data)
{
	if (*ptr == ' ')
	{
		data->flags[SPACE] = 1;
		return (1);
	}
	data->flags[SPACE] = 0;
	return (0);
}
