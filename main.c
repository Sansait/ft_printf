/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/07 16:58:25 by jlehideu         ###   ########.fr       */
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

	u_nb = 98765; 
	ft_printf("ft ->%u\n", u_nb);
	printf("print ->%u\n\n", u_nb);
	ft_printf("ft- ->%-u\n", u_nb);
	printf("print- ->%-u\n\n", u_nb);
	ft_printf("ft-12 ->%-12u\n", u_nb);
	printf("print ->%-12u\n\n", u_nb);
	return (0);
}
