cmake_minimum_required(VERSION 3.9)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_printf main.c ft_printf.h libft/srcs/ft_printuntil.c path.c int.c string.c void.c)
target_link_libraries(ft_printf "~/dev/ft_printf/libft/libft.a")