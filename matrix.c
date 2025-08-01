#include "includes/fdf.h"

typedef struct s_point
{
    float x;
    float y;
    float z;
} t_point;

void rotate_x(t_point *p, float angle);
void rotate_y(t_point *p, float angle);
void rotate_z(t_point *p, float angle);
void project_iso(t_point *p);

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

void    rotate_x(t_point *p, float angle)
{
    tmp_y = p->y * cos(t) - p->z * sin(t);
    tmp_z = p->y * sin(t) + p->z * cos(t);
}

void    rotate_y(t_point *p, float angle)
{
    tmp_x = p->x * cos(t) + p->z * sin(t);
    tmp_z = p->x * (-sin(t)) + p->z * cos(t);
}

void    rotate_z(t_point *p, float angle)
{
    tmp_x = p->x * cos(t) - p->y * sin(t);
    tmp_y = p->x * sin(t) + p->y * cos(t);
}