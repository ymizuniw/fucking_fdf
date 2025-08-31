#include "includes/fdf.h"

// this is not solved
static float	clamp_elem(float pan)
{
	if (pan < -PAN_LIMIT)
		return (-PAN_LIMIT);
	else if (pan > PAN_LIMIT)
		return (PAN_LIMIT);
	else
		return (pan);
}

static void	clamp_pan(t_app *app)
{
	app->mat->pan_x = clamp_elem(app->mat->pan_x);
	app->mat->pan_y = clamp_elem(app->mat->pan_y);
}

void	direction_shift(int key, t_app *app)
{
	if (key == XK_Left)
		app->mat->pan_x -= PAN_UNIT;
	else if (key == XK_Right)
		app->mat->pan_x += PAN_UNIT;
	else if (key == XK_Up)
		app->mat->pan_y -= PAN_UNIT;
	else if (key == XK_Down)
		app->mat->pan_y += PAN_UNIT;
	clamp_pan(app);
}