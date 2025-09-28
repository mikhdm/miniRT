# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 03:29:07 by rmander           #+#    #+#              #
#    Updated: 2021/04/17 03:30:48 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./mlx
LIBFT_DIR = ./libft
SRCS = ./src/main.c ./src/rt/image.c ./src/rt/event.c
INCLUDES = ./include/rt.h ./mlx/mlx.h ./include/event.h ./include/parser.h ./include/figure.h
MLX_DYLIB = ./mlx/libmlx.dylib 
DYLIB = ./libmlx.dylib
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
