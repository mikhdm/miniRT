# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 03:29:07 by rmander           #+#    #+#              #
#    Updated: 2021/04/23 15:33:16 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./mlx
LIBFT_DIR = ./libft
MLX_DYLIB = ./mlx/libmlx.dylib 
DYLIB = ./libmlx.dylib
SRCS = ./src/rt/image.c ./src/rt/event.c ./src/rt/linop.c ./src/rt/ray.c \
	   ./src/utils/calc_quad_equation.c ./src/utils/ft_swap.c \
	   ./src/utils/deg_to_rad.c ./src/main.c
INCLUDES = 	./include/rt.h ./mlx/mlx.h ./include/event.h \
			./include/parser.h ./include/figure.h ./include/linop.h \
			./include/ray.h ./include/utils.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR) all
	mv $(MLX_DYLIB) $(DYLIB)
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) -L. -lmlx -Llibft -lft -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -Iinclude -Imlx -Ilibft -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(DYLIB)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
