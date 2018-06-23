# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlehideu <jlehideu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 10:23:16 by jlehideu          #+#    #+#              #
#    Updated: 2018/06/23 16:40:11 by jlehideu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a 

NAMEN = ft_printf

SRC = main.c to_base.c string.c int.c length.c flags.c path.c precision.c pick_f_u_int.c pick_f_x.c digits_precision.c pick_f_c.c ft_itoa.c ft_memset.c ft_putstr.c ft_strchr.c ft_strcmp.c ft_strlen.c ft_putstr_fd.c \
      ft_putchar.c \
      ft_putnbr.c \
      ft_strnew.c \
      ft_strdel.c \
      ft_atoi.c \
      pick_f_w.c \
      pick_f_percent.c 

OBJ = $(SRC:.c=.o) 

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) 

yo: 	$(OBJ)
	gcc $(FLAGS) -o $(NAMEN) $(OBJ) -lft -L./libft/.
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMEN)

re: fclean all
