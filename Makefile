# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlehideu <jlehideu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 10:23:16 by jlehideu          #+#    #+#              #
#    Updated: 2018/06/05 12:30:58 by jlehideu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_printf

SRC = main.c to_base.c string.c

OBJ = $(SRC:.c=.o) 

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o ft_printf $(SRC) -lft -L./libft/.

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
