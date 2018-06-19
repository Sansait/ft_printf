# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlehideu <jlehideu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 10:23:16 by jlehideu          #+#    #+#              #
#    Updated: 2018/06/19 15:40:12 by jlehideu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_printf

SRC = main.c to_base.c string.c int.c length.c flags.c path.c precision.c pick_f_u_int.c pick_f_x.c digits_precision.c pick_f_c.c

OBJS = $(addprefix $(DIR), $(OBJ))

OBJ = $(SRC:.c=.o) 

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ)
		gcc $(FLAGS) -o $(NAME) $(OBJ) -lft -L./libft/.

yo: 	$(OBJ)
		gcc $(FLAGS) -o $(NAME) $(OBJ) -lft -L./libft/.
		rm -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
