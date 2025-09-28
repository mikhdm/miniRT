#include "linop.h"

t_vector3   calc_faceted_orient(t_vector3 *dirvec, t_vector3 *orient)
{
	t_vector3   vec;
	t_vector3   facing_ratio;

	vec = *orient;
	facing_ratio = cmultvec3(-1, dirvec);
	facing_ratio = normvec3(&facing_ratio);
	if (dot3(&facing_ratio, orient) < 1e-10)
		vec = cmultvec3(-1, orient);
	return (vec);
}
