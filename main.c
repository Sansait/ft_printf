/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/23 18:35:14 by jlehideu         ###   ########.fr       */
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
	data->ret_val += i;
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
	printuntil(str, ptr, &data);
	va_end(pointerlst);
	return (data.ret_val);
}

int main(void)
{//fix two commented codes@
	int	i;
	int	ret;

	i = -1;

	printf("Vret -> %d\n", printf("moulitest %x jdfhjsdfh\n", 0));
	printf("Nret -> %d\n", ft_printf("moulitest %x\n dskjfhd", 0));
//	ft_printf("%%");
	return (0);
}
