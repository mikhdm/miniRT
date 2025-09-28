/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:01:38 by rmander           #+#    #+#             */
/*   Updated: 2021/06/04 07:06:43 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "intersect.h"
#include "utils.h"
#include <stdio.h>

static void	test_linop(void)
{
	t_vector3 vec1 = (t_vector3) {.x = 4.0, .y = 0.0, .z = 0.0};
	t_vector3 vec2 = (t_vector3) {.x = -4.0, .y = 0.0, .z = 0.0};

	t_vector3 vec3 = diffvec3(&vec1, &vec2);
	printf("difference: (%f, %f, %f) - (%f, %f, %f) = (%f, %f, %f)\n",
		vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z, vec3.x, vec3.y, vec3.z);

	double scalar = dot3(&vec1, &vec2);
	printf("dot: <(%f, %f, %f), (%f, %f, %f)> = %f\n",
		vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z, scalar);

	t_vector3 vec4 = sumvec3(&vec1, &vec2);
	printf("sum: (%f, %f, %f) + (%f, %f, %f) = (%f, %f, %f)\n",
		vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z, vec4.x, vec4.y, vec4.z);
	
	t_vector3 vec5 = cmultvec3(scalar, &vec1);
	printf("mult by constant: %f * (%f, %f, %f) = (%f, %f, %f) \n",
		scalar, vec1.x, vec1.y, vec1.z, vec5.x, vec5.y, vec5.z);
	
	t_vector3 vec6 = cross3(&vec1, &vec2);
	printf("cross: (%f, %f, %f) x (%f, %f, %f) = (%f, %f, %f), length: || %f ||\n",
			vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z,
			vec6.x, vec6.y, vec6.z, hypotvec3(&vec6));

	printf("is collinear vectors: (%f, %f, %f) and (%f, %f, %f) ? %d \n",
			vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z,
			iscollinvec3(&vec1, &vec2));
}

static void	test_quad_equation(void)
{
	t_pair_double vals1 = calc_quad_equation(1, 2, 1);
	printf("x^2 + 2*x + 1 = 0 : x1 = %f, x2 = %f\n", vals1.first, vals1.second);

	/* inf test */
	t_pair_double vals2 = calc_quad_equation(1, 2, 3);
	printf("x^2 + 2*x + 3 = 0 : x1 = %f, x2 = %f\n", vals2.first, vals2.second);

	t_pair_double vals3 = calc_quad_equation(1, 2, -3);
	printf("x^2 + 2*x - 3 = 0 : x1 = %f, x2 = %f\n", vals3.first, vals3.second);
}

static void	test_deg_to_rad(void)
{
	double deg = 180;
	double deg2 = 90;
	printf("%f degrees in radians = %f\n", deg, deg_to_rad(deg)); 
	printf("%f degrees in radians = %f\n", deg2, deg_to_rad(deg2)); 
}

static void	test_calc_viewport(t_data *data)
{
	t_viewport	viewport;

	viewport = calc_viewport(data, data->cam);
	printf("projection plane width = %f, height = %f\n", viewport.width, viewport.height);
}

static void	test_gen_square_vertices(t_square *square)
{
	t_vector3 *vertices;
	t_vector3 vec[4];
	vertices = gen_square_vertices(square);

	printf("square: size: %f, orient: (%f, %f, %f), center: (%f, %f, %f) \n",
			square->size, square->orient.x, square->orient.y, square->orient.z,
			square->center.x, square->center.y, square->center.z);
	printf("P1: (%f, %f, %f), P2: (%f, %f, %f), P3: (%f, %f, %f), P4: (%f, %f, %f)\n",
			vertices[0].x, vertices[0].y, vertices[0].z,
			vertices[1].x, vertices[1].y, vertices[1].z,
			vertices[2].x, vertices[2].y, vertices[2].z,
			vertices[3].x, vertices[3].y, vertices[3].z);
	vec[0] = diffvec3(&vertices[1], &vertices[0]);
	vec[1] = diffvec3(&vertices[2], &vertices[1]);
	vec[2] = diffvec3(&vertices[3], &vertices[2]);
	vec[3] = diffvec3(&vertices[0], &vertices[3]);
	printf("|| P2 - P1 || = %f, || P3 - P2 || = %f, || P4 - P3 || = %f, || P1 - P4 || = %f\n",
			hypotvec3(&vec[0]),
			hypotvec3(&vec[1]),
			hypotvec3(&vec[2]),
			hypotvec3(&vec[3]));
}

static void test_alloca_to()
{
	t_vector3   *vec3;
	if (!alloca_to((void**)&vec3, sizeof(t_vector3) * 3))
		return ;
	vec3[0].x = 1;
	vec3[0].y = 2;
	vec3[0].z = 3;

	vec3[1].x = 1;
	vec3[1].y = 2;
	vec3[1].z = 3;

	vec3[2].x = 1;
	vec3[2].y = 2;
	vec3[2].z = 3;
	printf("alloca_to test: (%f, %f, %f), (%f, %f, %f), (%f, %f, %f)\n",
		vec3[0].x, vec3[0].y, vec3[0].z,
		vec3[1].x, vec3[1].y, vec3[1].z,
		vec3[2].x, vec3[2].y, vec3[2].z);
	free(vec3);
}

static void test_is_polygon_point(t_data *data, t_square *square)
{
	t_vector3   p_hit;
	double      t;
	t_vector3   dirvec;
	t_vector3   *vertices;

	vertices = gen_square_vertices(square);
	dirvec = canvas_to_viewport(data, data->cam, -1000, 300);
	t = intersect_square(data, &data->cam->center, &dirvec, square);
	p_hit = calc_ray_point(&data->cam->center, &dirvec, t);
	printf ("is polygon point test: (%f, %f, %f) ? %d, ",
		 p_hit.x, p_hit.y, p_hit.z,
		 is_polygon_point(&p_hit, vertices, &square->orient, 4));
}

void test(t_data *data)
{
	/* LOG */
	printf("bpp: %d;\nline length: %d;\nendian: %d;\n",
		data->bpp, data->length, data->endian);
	/* END LOG */

	t_square square = {.center = (t_vector3) {.x = 0, .y = 0, .z = 20},
						.color = 0xff0000,
						.orient = (t_vector3) {.x = 0, .y = 0, .z = 1},
						.size = 10.0};
	test_linop();
	test_quad_equation();
	test_deg_to_rad();
	test_calc_viewport(data);
	test_gen_square_vertices(&square);
	test_alloca_to();
	test_is_polygon_point(data, &square);
}