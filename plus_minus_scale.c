#include "includes/fdf.h"

void	plus_minus_scale(int key, t_app *app)
{
	if ((key == XK_equal || key == XK_KP_Add) && (app->mat->scale * SCALE_UNIT < (float)20))
		app->mat->scale *= SCALE_UNIT;
	else if (app->mat->scale / SCALE_UNIT > -(float)20)
		app->mat->scale /= SCALE_UNIT;
	// clamp_scale(app);
}
