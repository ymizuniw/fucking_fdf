#include "includes/fdf.h"

// static void	rotate_x(t_map_3d *p, float t)
// {
//     float tmp_y;
//     float tmp_z;

//     tmp_y = p->y;
//     tmp_z = p->z;
// 	p->y = tmp_y * cosf(t) - tmp_z * sinf(t);
// 	p->z = tmp_y * sinf(t) + tmp_z * cosf(t);
// }

// static void	rotate_y(t_map_3d *p, float t)
// {
//     float tmp_x;
//     float tmp_z;

//     tmp_x = p->x;
//     tmp_z = p->z;
// 	p->x = tmp_x * cosf(t) + tmp_z * sinf(t);
// 	p->z = tmp_x * (-sinf(t)) + tmp_z * cosf(t);
// }

// static void	rotate_z(t_map_3d *p, float t)
// {
//     float tmp_x;
//     float tmp_y;

//     tmp_x = p->x;
//     tmp_y = p->y;
// 	p->x = tmp_x * cosf(t) - tmp_y * sinf(t);
// 	p->y = tmp_x * sinf(t) + tmp_y * cosf(t);
// }

// // isometric projection using angle t = 30;
// static t_map_2d	proj_iso(t_map_3d p)
// {
// 	t_map_2d res;

// 	res.x = (p.x - p.y) * COS30;
// 	res.y = (p.x + p.y) * SIN30 - p.z;
// 	res.color = 0;
// 	return (res);
// }

//define the point z(x,y) and then,
//call convert_object() for all elements of map_3d
t_map_2d		convert_points(t_map_3d ptr, t_matrix *mat)
{
	t_map_2d	new;

	// rotate_z(&ptr, mat->usr->theta_z);
	// rotate_y(&ptr, mat->theta_y);
	// rotate_x(&ptr, mat->theta_x);
	// new = proj_iso(ptr);
	t_vec3 v;

	v.x = ptr.x;
	v.y = ptr.y;
	v.z = ptr.z;
	v = mat3_apply(mat->usr, v);
	new.x = (v.x - v.y) * COS30;
	new.y = (v.x + v.y) * SIN30 - v.z;
	new.x *= mat->scale;
	new.y *= mat->scale;
	return (new);
}
