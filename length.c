/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:40:48 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/06 14:41:30 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length_h(const char *ptr, t_data *data)
{
	data->length[0] = 1;
	if (*(ptr + 1) == 'h')
	{
		data->length[0] = 2;
		return (2);
	}
	return (1);
}

int		length_l(const char *ptr, t_data *data)
{
	data->length[1] = 1;
	if (*(ptr + 1) == 'h')
	{
		data->length[1] = 2;
		return (2);
	}
	return (1);
}

int		length_j(const char *ptr, t_data *data)
{
	data->length[2] = 1;
	return (1);
}

int		length_z(const char *ptr, t_data *data)
{
	data->length[3] = 1;
	return (1);
}
