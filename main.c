/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/06 15:57:48 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

//test
int	 ft_printf(const char *str, ...)
{
	va_list		pointerlst;
	char 		*ptr;
	int			i;

	va_start(pointerlst, str);
	i = 0;
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		i++;
		ft_printuntil(str, ptr) + 1;
		ptr += 1;
		conversion(ptr, pointerlst, i);
		str = ptr + 1;
	}
	ft_printuntil(str, ptr);
	va_end(pointerlst);
	return (0);
}


int main(int ac, char **av)
{
	//ft_printf("salut les zickos %d %i %d %s ca va ", 1, 2, 3, "123");
	int nb;

	if (ac < 2)
	{
		printf("veuillew entrer un parametre");
		return (0);
	}
	nb = ft_atoi(av[1]);
	printf("%s\n", to_base(nb, av[2]));
	return (0);
}
