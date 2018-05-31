/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:21:52 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/31 18:27:49 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/includes/libft.h"

int		conversion(const char *ptr, va_list param, int i);
int		int_param(const char * str, va_list param, int i);
int		string_param(const char *ptr, va_list param);
int		void_param(const char *ptr, va_list param);

#endif //FT_PRINTF_H
