#include "includes/fdf.h"

void		rotate_x(t_vec_3 *p, float t);
void		rotate_y(t_vec_3 *p, float t);
void		rotate_z(t_vec_3 *p, float t);
void		project_iso(t_vec_3 *p);

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

typedef struct s_vec_3
{
	float	x;
	float	y;
	float	z;
}			t_vec_3;

typedef struct s_vec_2
{
	float	x;
	float	y;
}			t_vec_2;

typedef struct s_matrix
{
	int		theta_x;
	int		theta_y;
	int		theta_z;
	float	scale;
}			t_matrix;

transform_object(t_vec_3 p, t_matrix *mat)
{
    t_vec_2 new;
	
    rotate_x(&p, mat->theta_x);
	rotate_y(&p, mat->theta_y);
	rotate_z(&p, mat->theta_z);
	new = proj_iso(p);
}

void	rotate_x(t_vec_3 *p, float t)
{
	p->y = p->y * cos(t) - p->z * sin(t);
	p->z = p->y * sin(t) + p->z * cos(t);
}

void	rotate_y(t_vec_3 *p, float t)
{
	p->x = p->x * cos(t) + p->z * sin(t);
	p->z = p->x * (-sin(t)) + p->z * cos(t);
}

void	rotate_z(t_vec_3 *p, float t)
{
	p->x = p->x * cos(t) - p->y * sin(t);
	p->y = p->x * sin(t) + p->y * cos(t);
}

//isometric projection using angle t = 30;
t_vec_2	proj_iso(t_vec_3 p)
{
	t_vec_2 res;

	res.x = (p.x - p.y) * cos(30);
	res.y = (p.x + p.y) * sin(30) - p.z;
	return (res);
}