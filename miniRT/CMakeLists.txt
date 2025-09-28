cmake_minimum_required(VERSION 3.5)
project(miniRT)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
 
include_directories(include lib/libft lib/mlx)
 
add_executable(miniRT
	src/main.c
	src/tests.c
	src/rt/canvas.c
	src/rt/color.c
	src/rt/event.c
	src/rt/intersect.c
	src/rt/light.c
	src/rt/linop.c
	src/rt/rayop.c
	src/rt/render.c
	src/rt/shade.c
	src/rt/utils/calc_quad_equation.c
	src/rt/utils/calc_ray_point.c
	src/rt/utils/calc_sphere_orient.c
	src/rt/utils/deg_to_rad.c
	src/rt/utils/gen_square_vertices.c
	src/rt/utils/is_polygon_point.c)
