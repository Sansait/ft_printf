/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/19 12:49:46 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>

int	printuntil(const char *str, const char *ptr)
{
	int i;

	i = 0;
	while (str + i != ptr && str[i] != '\0')
		i++;
	write(1, str, i);
	return (i);
}

void	init_struct(t_data *data)
{
	int i;

	data->precision = 0;
	data->width = 0;
	data->ret_val = 0;
	i = -1;
	while (++i <= 4)
		data->flags[i] = 0;
	i = -1;
	while (++i <= 3)
		data->length[i] = 0;
}

int	 ft_printf(const char *str, ...)
{//ATTENTION AU :AKEFILE QUI CLEAN DIRECT
	va_list		pointerlst;
	char 		*ptr;
	int		i;
	int		ret_val;
	t_data		data;

	ret_val = 0;
	va_start(pointerlst, str);
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		init_struct(&data);
		ret_val += printuntil(str, ptr);
		ptr += 1;
		init_struct(&data);
		while ((i = path(ptr, pointerlst, &data)) > 0)
		{
			ptr += i;
			ret_val += data.ret_val;
		}			
		ret_val += data.ret_val;
		str = ptr + 1;
	}
	ft_printuntil(str, ptr);
	va_end(pointerlst);
	return (ret_val);
}


int main(void)
{
	//il est probable que la precision ne soit pas réinitialisée à 0 quand on passe a une convertion suivante
	//x ne fonctionne pas avec 0
	int		nb;
	unsigned int	u_nb;
	char		c;
	wchar_t		test;

	c = 'c';
	ft_printf("salut c'est nous -> %-2c\n", c);
	printf("salut c'est vous -> %-2c\n", c);
	return (0);
}
