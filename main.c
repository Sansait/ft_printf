/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/23 18:45:46 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int	printuntil(const char *str, const char *ptr, t_data *data)
{
	int i;

	i = 0;
	while (str[i] && str + i != ptr && str[i] != '\0')
		i++;
	print_str((char *)str, data);
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
	while (++i <= 4)
		data->length[i] = 0;
}

int	 ft_printf(const char *str, ...)
{
	va_list		pointerlst;
	char 		*ptr;
	int		i;
	t_data		data;

	va_start(pointerlst, str);
//	if (check(str) == -1)
//		return (-1);
	init_struct(&data);
	data.idx = -1;
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		init_struct(&data);
		ptr += 1;
		while (ptr && (i = path(ptr, pointerlst, &data)) > 0)
		{
			ptr += i;
		}
		str = ptr + 1;
	}
//	fill_buff_s(&data, -1, "");
	printuntil(str, ptr, &data);
	write(1, &data.buff, ++data.idx);
	va_end(pointerlst);
	return (data.ret_val);
}
/*
int main(void)
{//fix two commented codes@
	int	i;
	int	ret;

	i = -1;

	printf("Vret -> %d\n", printf("%x", 42));
	printf("Nret -> %d\n", ft_printf("%x", 42));
//	printf("Vret -> %d\n", printf("vous %#.6x\n", 987));
//	printf("Nret -> %d\n", printf("nous %#.6x\n", 987));
	return (0);
}*/
