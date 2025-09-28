cmake_minimum_required(VERSION 3.5)
project(miniRT)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SOURCE_DIR cmake.build)
 
include_directories(include lib/libft lib/mlx)

add_library(ft STATIC
lib/libft/ft_atoi.c
lib/libft/ft_bzero.c
lib/libft/ft_calloc.c
lib/libft/ft_isalnum.c
lib/libft/ft_isalpha.c
lib/libft/ft_isascii.c
lib/libft/ft_isdigit.c
lib/libft/ft_islower.c
lib/libft/ft_isprint.c
lib/libft/ft_isspace.c
lib/libft/ft_isupper.c
lib/libft/ft_itoa.c
lib/libft/ft_lstadd_back.c
lib/libft/ft_lstadd_front.c
lib/libft/ft_lstclear.c
lib/libft/ft_lstdelone.c
lib/libft/ft_lstiter.c
lib/libft/ft_lstlast.c
lib/libft/ft_lstmap.c
lib/libft/ft_lstnew.c
lib/libft/ft_lstsize.c
lib/libft/ft_memccpy.c
lib/libft/ft_memchr.c
lib/libft/ft_memcmp.c
lib/libft/ft_memcpy.c
lib/libft/ft_memmove.c
lib/libft/ft_memset.c
lib/libft/ft_putchar_fd.c
lib/libft/ft_putendl_fd.c
lib/libft/ft_putnbr_fd.c
lib/libft/ft_putstr_fd.c
lib/libft/ft_split.c
lib/libft/ft_strchr.c
lib/libft/ft_strdup.c
lib/libft/ft_strjoin.c
lib/libft/ft_strlcat.c
lib/libft/ft_strlcpy.c
lib/libft/ft_strlen.c
lib/libft/ft_strmapi.c
lib/libft/ft_strncmp.c
lib/libft/ft_strnstr.c
lib/libft/ft_strrchr.c
lib/libft/ft_strtrim.c
lib/libft/ft_substr.c
lib/libft/ft_tolower.c
lib/libft/ft_toupper.c
# lib/libft/get_next_line/get_next_line.c
# lib/libft/get_next_line/get_next_line_utils.c
)

add_executable(miniRT
        src/rt/utils/calc_quad_equation.c
        src/rt/utils/calc_ray_point.c
        src/rt/utils/calc_sphere_orient.c
        src/rt/utils/deg_to_rad.c
        src/rt/utils/rad_to_deg.c
        src/rt/utils/swap_double.c
        src/rt/utils/gen_square_vertices.c
        src/rt/utils/alloca_to.c
        src/rt/utils/is_polygon_point.c
        src/rt/utils/calc_min_t.c
        src/rt/utils/calc_cylinder_min_t.c
        src/rt/utils/calc_triangle_orient.c
        src/rt/utils/calc_cylinder_orient.c
        src/rt/utils/calc_faceted_orient.c
        src/rt/utils/imax.c
        src/rt/utils/isdir.c
        src/rt/canvas.c
        src/rt/color.c
        src/rt/event.c
        src/rt/intersect.c
        src/rt/light.c
        src/rt/linop.c
        src/rt/rayop.c
        src/rt/render.c
        src/rt/shade.c
        src/parsing/parse.c
        src/parsing/errors.c
        src/parsing/serialize.c
        src/parsing/validate.c
        src/screenshot.c
        src/tests.c
        main.c)

target_link_libraries(miniRT ./libmlx.dylib)
target_link_libraries(miniRT ${CMAKE_SOURCE_DIR}/libft.a)
