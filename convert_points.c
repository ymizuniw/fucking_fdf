#include "includes/fdf.h"

static void	rotate_x(t_map_3d *p, float t)
{
    float tmp_y;
    float tmp_z;

    tmp_y = p->y;
    tmp_z = p->z;
	p->y = tmp_y * cos(t) - tmp_z * sin(t);
	p->z = tmp_y * sin(t) + tmp_z * cos(t);
}

static void	rotate_y(t_map_3d *p, float t)
{
    float tmp_x;
    float tmp_z;

    tmp_x = p->x;
    tmp_z = p->z;
	p->x = tmp_x * cos(t) + tmp_z * sin(t);
	p->z = tmp_x * (-sin(t)) + tmp_z * cos(t);
}

static void	rotate_z(t_map_3d *p, float t)
{
    float tmp_x;
    float tmp_y;

    tmp_x = p->x;
    tmp_y = p->y;
	p->x = tmp_x * (float)cos(t) - tmp_y * (float)sin(t);
	p->y = tmp_x * (float)sin(t) + tmp_y * (float)cos(t);
}

// isometric projection using angle t = 30;
static t_map_2d	proj_iso(t_map_3d p)
{
	t_map_2d res;

	res.x = (p.x - p.y) * COS30;
	res.y = (p.x + p.y) * SIN30 - p.z;
	return (res);
}

//define the point z(x,y) and then,
//call convert_object() for all elements of map_3d
t_map_2d		convert_points(t_map_3d ptr, t_matrix *mat)
{
	t_map_2d	new;

	new.x *= mat->scale;
	new.y *= mat->scale;
	rotate_z(&ptr, mat->theta_z);
	rotate_y(&ptr, mat->theta_y);
	rotate_x(&ptr, mat->theta_x);
	new = proj_iso(ptr);
	return (new);
}
