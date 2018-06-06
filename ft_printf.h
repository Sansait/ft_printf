/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:21:52 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/06 15:24:15 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/includes/libft.h"

# define SHARP 0
# define ZERO 1
# define MINUS 2
# define PLUS 3
# define SPACE 4
# define H 0
# define L 1
# define J 2
# define Z 3

struct s_data
{
	int		flags[5];
	int		length[4];
	int		precision;
	int		width;
};

typedef struct s_data	t_data;

int		path(char *ptr, va_list param, t_data *data);
int		conversion(const char *ptr, va_list param, t_data *data);
int		int_param(const char * str, va_list param);
int		string_param(const char *ptr, va_list param);
int		void_param(const char *ptr, va_list param);
int		unsignedint_param_oct(const char *ptr, va_list param);
int		unsignedint_param(const char *ptr, va_list param);
int		unsignedint_param_hex(const char *ptr, va_list param);
int		unsignedint_param_hexm(const char *ptr, va_list param);
int		flags(const char *ptr, t_data *data);
int		flag_sharp(t_data *data);
int		flag_zero(t_data *data);
int		flag_minus(t_data *data);
int		flag_plus(t_data *data);
int		flag_space(t_data *data);
int		length(const char *ptr, t_data *data);
int		length_h(const char *ptr, t_data *data);
int		length_l(const char *ptr, t_data *data);
int		length_j(t_data *data);
int		length_z(t_data *data);
int		width(char *ptr, t_data *data);
int		precision(char *ptr, t_data *data);
int		width_min(char *ptr, t_data *data);


#endif
