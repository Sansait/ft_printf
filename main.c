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

void	print_str(const char *str, t_data *data)
{//un putstr qui incrémente notre valeur de retour
	while (*str)
	{
		ft_putchar(*str);
		++data->ret_val;
		++str;
	}
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
{
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
{//x a revoir
	//il est probable que la precision ne soit pas réinitialisée à 0 quand on passe a une convertion suivante
	int		nb;
	unsigned int	u_nb;
	char		c;
	wchar_t		test;

	printf("retour -> %d\n", ft_printf("Salut, c'est nous -> %12u, %012.16u, %014x", 42949672, 74, 876));
	printf("retour -> %d\n", printf("Salut, c'est vous -> %12u, %012.16u, %014x", 42949672, 74, 876));
	nb = 8;
	u_nb = 76987; 
	return (0);
}
