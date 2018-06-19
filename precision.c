/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:13:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/19 12:05:34 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		precision(char *ptr, t_data *data)
{
	int i;

	i = 0;
	while (*(ptr + i) >= '0' && *(ptr + i) <= '9')
		i++;
	if (i > 0)
		data->precision = ft_atoi(ptr);
	else
		data->precision = 1;
	return (i);
}

int		width_min(char *ptr, t_data *data)
{
	int i;

	i = 0;
	while (*(ptr + i) >= '0' && *(ptr + i) <= '9')
		i++;
	if (i > 0)
		data->width = ft_atoi(ptr);
	return (i);
}
