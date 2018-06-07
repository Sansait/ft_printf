/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/07 15:35:19 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

void	init_struct(t_data *data)
{
	int i;

	data->precision = 0;
	data->width = 0;
	i = -1;
	while (++i <= 4)
		data->flags[i] = 0;
	i = -1;
	while (++i <= 3)
		data->length[i] = 0;
}

int	 ft_printf(const char *str, ...)
{
	va_list		pointerlst;
	char 		*ptr;
	int			i;
	t_data		data;

	va_start(pointerlst, str);
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		init_struct(&data);
		ft_printuntil(str, ptr);
		ptr += 1;
		init_struct(&data);
		while ((i = path(ptr, pointerlst, &data)) > 0)
			ptr += i;
		str = ptr + 1;
	}
	ft_printuntil(str, ptr);
	va_end(pointerlst);
	return (0);
}


int main(void)
{
	int				nb;

	u_nb = 98765; 
	ft_printf("ft ->%-u\n", u_nb);
	printf("print ->%-u\n\n", u_nb);
/*	ft_printf("ft- ->%-u\n", u_nb);
	printf("print- ->%-u\n\n", u_nb);
	ft_printf("ft-12 ->%-12u\n", u_nb);
	printf("print ->%-12u\n\n", u_nb);*/
	return (0);
}
