# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 03:29:07 by rmander           #+#    #+#              #
#   Updated: 2021/06/03 14:36:56 by rmander          ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -I./lib/libft -I./lib/libft/get_next_line -I./lib/mlx

LIBFT_DIR = ./lib/libft

MLX_DIR = ./lib/mlx
MLX_DYLIB = ./lib/mlx/libmlx.dylib 
DYLIB = ./libmlx.dylib

SRCS =  src/rt/utils/calc_quad_equation.c \
        src/rt/utils/calc_ray_point.c \
        src/rt/utils/calc_sphere_orient.c \
        src/rt/utils/deg_to_rad.c \
        src/rt/utils/rad_to_deg.c \
        src/rt/utils/swap_double.c \
        src/rt/utils/gen_square_vertices.c \
        src/rt/utils/alloca_to.c \
        src/rt/utils/is_polygon_point.c \
        src/rt/utils/calc_min_t.c \
        src/rt/utils/calc_cylinder_min_t.c \
        src/rt/utils/calc_triangle_orient.c \
        src/rt/utils/calc_cylinder_orient.c \
        src/rt/utils/calc_faceted_orient.c \
        src/rt/utils/isdir.c \
        src/rt/utils/skip_spaces_str.c \
		src/rt/utils/mlx_reset_image.c \
		src/rt/utils/get_cam.c \
        src/parsing/parse.c \
        src/parsing/errors.c \
        src/parsing/cleanup.c \
        src/parsing/serialize.c \
        src/parsing/serializers/serialize_r.c \
        src/parsing/serializers/serialize_a.c \
		src/parsing/serializers/serialize_c.c \
		src/parsing/serializers/serialize_l.c \
		src/parsing/serializers/serialize_sp.c \
		src/parsing/serializers/serialize_cy.c \
		src/parsing/serializers/serialize_pl.c \
		src/parsing/serializers/serialize_tr.c \
		src/parsing/serializers/serialize_sq.c \
		src/parsing/serializers/helpers/serialize_point.c \
		src/parsing/serializers/helpers/serialize_orient.c \
		src/parsing/serializers/helpers/serialize_rgb.c \
		src/parsing/serializers/helpers/lst_figure_append.c \
		src/parsing/serializers/helpers/serialize_cy_rgb.c \
		src/parsing/serializers/helpers/serialize_sq_rgb.c \
		src/parsing/serializers/helpers/serialize_pl_rgb.c \
        src/parsing/validate.c \
        src/parsing/validators/valid_rgb.c \
        src/parsing/validators/valid_orient.c \
        src/parsing/validators/valid_point3.c \
        src/rt/canvas.c \
        src/rt/color.c \
        src/rt/event.c \
        src/rt/intersect.c \
        src/rt/light.c \
        src/rt/linop.c \
        src/rt/rayop.c \
        src/rt/render.c \
        src/rt/shade.c \
        src/screenshot.c \
        src/tests.c \
        main.c
		
INCLUDES = 	./lib/mlx/mlx.h \
			./lib/libft/libft.h \
			./lib/libft/get_next_line.h \
			./include/utils.h \
		   	./include/canvas.h \
		   	./include/color.h \
			./include/event.h \
		   	./include/intersect.h \
			./include/linop.h \
			./include/rayop.h \
			./include/render.h \
			./include/screenshot.h \
			./include/shade.h \
			./include/light.h \
			./include/parsing/errors.h \
			./include/parsing/parse.h \
			./include/parsing/serialize.h \
			./include/parsing/validate.h
		   
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): mlx libft | $(OBJS)
	mv $(MLX_DYLIB) $(DYLIB)
	$(CC) $(CFLAGS) -L. -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

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