#include "includes/fdf.h"

static float	round_pi(float theta)
{
	while (theta > (float)M_PI)
		theta -= 2.0f * (float)M_PI;
	while (theta <= (float)M_PI)
		theta += 2.0f * (float)M_PI;
	return (theta);
}

static void	validate_angles(t_app *app)
{
	app->mat->theta_x = round_pi(app->mat->theta_x);
	app->mat->theta_y = round_pi(app->mat->theta_y);
}

void	direction_mono(int key, t_app *app)
{
	if (key == XK_Left)
		app->mat->theta_y -= ROT_UNIT;
	else if (key == XK_Right)
		app->mat->theta_y += ROT_UNIT;
	else if (key == XK_Up)
		app->mat->theta_x += ROT_UNIT;
	else if (key == XK_Down)
		app->mat->theta_x -= ROT_UNIT;
	validate_angles(app);
}
