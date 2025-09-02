#include "includes/fdf.h"

// static float	round_pi(float theta)
// {
// 	while (theta > PI)
// 		theta -= 2.0f * PI;
// 	while (theta <= -PI)
// 		theta += 2.0f * PI;
// 	return (theta);
// }

// static void	validate_angles(t_app *app)
// {
// 	app->mat->theta_x = round_pi(app->mat->theta_x);
// 	app->mat->theta_y = round_pi(app->mat->theta_y);
// 	app->mat->theta_z = round_pi(app->mat->theta_z);
// }

// void	direction_mono(int key, t_app *app)
// {
// 	if (key == XK_Left)
// 		app->mat->theta_z -= ROT_UNIT;
// 	else if (key == XK_Right)
// 		app->mat->theta_z += ROT_UNIT;
// 	else if (key == XK_Up)
// 		app->mat->theta_x -= ROT_UNIT;
// 	else if (key == XK_Down)
// 		app->mat->theta_x += ROT_UNIT;
// 	validate_angles(app);
// }

t_vec3 get_axis_z(void)
{
	t_vec3 axis;

	axis.x = 0;
	axis.y = 0;
	axis.z = 1;
	return (axis);
}

t_vec3 get_axis_x(void)
{
	t_vec3 axis;

	axis.x = 1;
	axis.y = 0;
	axis.z = 0;
	return (axis);	
}

void direction_mono(int key, t_app *app)
{
    t_vec3 axis_x;
	t_vec3 axis_z;

	axis_x = get_axis_x();
	axis_z = get_axis_z();
    if (key == XK_Left)
        rotation_adjustment(app, axis_z, -ROT_UNIT);
    else if (key == XK_Right)
        rotation_adjustment(app, axis_z, ROT_UNIT);
    else if (key == XK_Up)
        rotation_adjustment(app, axis_x, -ROT_UNIT);
    else if (key == XK_Down) 
        rotation_adjustment(app, axis_x, ROT_UNIT);
}
