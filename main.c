/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/07 12:42:42 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

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
		while ((i = path(ptr, pointerlst, &data)) > 0)
			ptr += i;
		str = ptr + 1;
	}
	ft_printuntil(str, ptr);
	va_end(pointerlst);
	return (0);
}


int main(int ac, char **av)
{
	int				nb;
	unsigned int	u_nb;

	if (ac < 2)
	{
		printf("veuillez entrer un parametre");
		return (0);
	}
	u_nb = -1; 
	ft_putstr("put_u_nbr ->");
	ft_put_u(u_nb);
	printf("\nprintf ->%u\n", u_nb);
	return (0);
}
