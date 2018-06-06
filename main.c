/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/06 15:31:14 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	 ft_printf(const char *str, ...)
{
	va_list		pointerlst;
	char 		*ptr;
	int			i;
	t_data		data;

	va_start(pointerlst, str);
	i = 0;
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		ft_printuntil(str, ptr);
		ptr += 1;
		i = conversion(ptr, pointerlst, &data);
		str = ptr + i;
	}
	ft_printuntil(str, ptr);
	va_end(pointerlst);
	return (0);
}



int main(void)
{
	ft_printf("salut les zickos %d %i %d %s ca va ", 1, 2, 3, "123");
	return (0);
}
