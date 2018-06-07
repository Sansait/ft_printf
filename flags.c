/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:19:16 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/07 17:13:06 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_sharp(t_data *data)
{
	data->flags[SHARP] = 1;
	return (1);
}

int		flag_zero(t_data *data)
{
	data->flags[ZERO] = 1;
	return (1);
}

int		flag_minus(t_data *data)
{
	data->flags[MINUS] = 1;
	return (1);
}

int		flag_plus(t_data *data)
{
	data->flags[PLUS] = 1;
	return (1);
}

int		flag_space(t_data *data)
{
	data->flags[SPACE] = 1;
	return (1);
}
