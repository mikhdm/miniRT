# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 03:29:07 by rmander           #+#    #+#              #
#    Updated: 2021/04/25 17:38:28 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -I./lib/libft -I./lib/mlx 
LIB_DIR = ./lib
MLX_DIR = ./lib/mlx
LIBFT_DIR = ./lib/libft
MLX_DYLIB = ./lib/mlx/libmlx.dylib 
DYLIB = ./libmlx.dylib
SRCS = ./src/rt/image.c ./src/rt/event.c ./src/rt/linop.c ./src/rt/ray.c \
	   ./src/utils/calc_quad_equation.c ./src/utils/ft_swap.c \
	   ./src/utils/deg_to_rad.c ./src/rt/light.c ./src/main.c
INCLUDES = 	./include/rt.h ./mlx/mlx.h ./include/event.h \
			./include/parser.h ./include/figure.h ./include/linop.h \
			./include/ray.h ./include/utils.h ./include/light.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): mlx libft | $(OBJS)
	mv $(MLX_DYLIB) $(DYLIB)
	$(CC) $(CFLAGS) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

mlx:
	$(MAKE) -j1 -C $(MLX_DIR) all

libft:
	$(MAKE) -C $(LIBFT_DIR) all

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -j 1 -C $(MLX_DIR) clean
	rm -f $(DYLIB)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx libft