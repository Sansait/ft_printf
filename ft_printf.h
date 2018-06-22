/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:21:52 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/20 16:56:07 by sklepper         ###   ########.fr       */
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

# define BASE_O "01234567"
# define BASE_HC "0123456789ABCDEF"
# define BASE_H "0123456789abcdef"

struct s_data
{
	int		flags[5];
	int		length[5];
	int		precision;
	int		width;
	int		zero;
	int		ret_val;
	int		len;
};

typedef struct s_data	t_data;

int	path(char *ptr, va_list param, t_data *data);
int	conversion(const char *ptr, va_list param, t_data *data);
int	int_param(va_list param);
int	string_param(t_data *data, va_list param);
int	void_param(va_list param);
int	unsignedint_param_oct(va_list param);
int	unsignedint_param(va_list param);
int	unsignedint_param_hex(const char *ptr, va_list param);
int	unsignedint_param_hexc(const char *ptr, va_list param);
int	flags(const char *ptr, t_data *data);
int	flag_sharp(t_data *data);
int	flag_zero(t_data *data, const char *ptr);
int	flag_minus(t_data *data);
int	flag_plus(t_data *data);
int	flag_space(t_data *data);
int	length(const char *ptr, t_data *data);
int	length_h(const char *ptr, t_data *data);
int	length_l(const char *ptr, t_data *data);
int	length_j(t_data *data);
int	length_z(t_data *data);
int	width(char *ptr, t_data *data);
int	precision(const char *ptr, t_data *data);
void	print_str(const char *str, t_data *data);
void	print_char(char c, t_data *data);
int	width_min(const char *ptr, t_data *data);
char	*to_base(int nb, char *base);
int	pick_f_u(va_list param, t_data *data);
int	pick_f_x(va_list param, t_data *data, const char *ptr);
int	pick_f_c(va_list param, t_data *data);
int	pick_f_s(const char *str, t_data *data, va_list param);
int	pick_f_w(t_data *data, va_list param);
int	pick_f_percent(va_list param, t_data *data) ;
int	f_precision(t_data *data);
int	f_zero(t_data *data);
int	f_width(t_data *data);
void	init_struct(t_data *data);
int	check(const char *ptr);
int	path_check(char *ptr, t_data *data);
int	check_s(t_data *data);
int	check_s_c_p(t_data *data);
int	check_di(t_data *data);
int	check_ox(t_data *data);
int	check_u(t_data *data);


#endif
