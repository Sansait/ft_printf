/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:19:16 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/06 13:35:38 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_sharp(t_data *data)
{
	data->flags[0] = 1;
	return (1);
}

int		flag_zero(t_data *data)
{
	data->flags[1] = 1;
	return (1);
}

int		flag_minus(t_data *data)
{
	data->flags[2] = 1;
	return (1);
}

int		flag_plus(t_data *data)
{
	data->flags[3] = 1;
	return (1);
}

int		flag_space(t_data *data)
{
	data->flags[4] = 1;
	return (1);
}