#include "includes/fdf.h"

void		rotate_x(t_vec_3 *p, float t);
void		rotate_y(t_vec_3 *p, float t);
void		rotate_z(t_vec_3 *p, float t);
void		project_iso(t_vec_3 p);

// keep x
// {
//     1       0       0
//     0     cos(t)    -sin(t)
//     0     sin(t)    cos(t)
// }
// keep y
// {
//     cos(t)      0       sin(t)
//     0           1       0
//     -sin(t)     0       cos(t)
// }
// keep z
// {
//     cos(t)      -sin(t)     0
//     sin(t)      cos(t)      0
//     0           0           1
// }

t_vec_2	transform_object(t_vec_3 p, t_matrix *mat)
{
	t_vec_2	new;

	rotate_x(&p, mat->theta_x);
	rotate_y(&p, mat->theta_y);
	rotate_z(&p, mat->theta_z);
	new = proj_iso(p);
	new.x *= mat->scale;
	new.y *= mat->scale;
	return (new);
}

void	rotate_x(t_vec_3 *p, float t)
{
    float tmp_y;
    float tmp_z;

    tmp_y = p->y;
    tmp_z = p->z;
	p->y = tmp_y * cos(t) - tmp_z * sin(t);
	p->z = tmp_y * sin(t) + tmp_z * cos(t);
}

void	rotate_y(t_vec_3 *p, float t)
{
    float tmp_x;
    float tmp_z;

    tmp_x = p->x;
    tmp_z = p->z;
	p->x = tmp_x * cos(t) + tmp_z * sin(t);
	p->z = tmp_x * (-sin(t)) + tmp_z * cos(t);
}

void	rotate_z(t_vec_3 *p, float t)
{
    float tmp_x;
    float tmp_y;

    tmp_x = p->x;
    tmp_y = p->y;
	p->x = tmp_x * cos(t) - tmp_y * sin(t);
	p->y = tmp_x * sin(t) + tmp_y * cos(t);
}

// isometric projection using angle t = 30;
t_vec_2	proj_iso(t_vec_3 p)
{
	t_vec_2 res;

	res.x = (p.x - p.y) * COS30;
	res.y = (p.x + p.y) * SIN30 - p.z;
	return (res);
}