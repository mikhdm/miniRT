/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:01:38 by rmander           #+#    #+#             */
/*   Updated: 2021/05/09 18:21:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "utils.h"

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

	viewport = calc_viewport(data);
	printf("projection plane width = %f, height = %f\n", viewport.width, viewport.height);
}

void test(t_data *data)
{
	test_linop();
	test_quad_equation();
	test_deg_to_rad();
	test_calc_viewport(data);
}
