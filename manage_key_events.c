#include "includes/fdf.h"

//pan and rotate event
int key_pressed(int key, t_app *app)
{
    int changed = 0;

    if (key == XK_Shift_L || key == XK_Shift_R)
        app->option->shift_on = 1;
    if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
    {
        if (app->option->shift_on)
            direction_shift(key, app);
        else
            direction_mono(key, app);
        changed = 1;
    }
    if (key == XK_equal || key == XK_KP_Add || key == XK_minus || key == XK_KP_Subtract)
    {
        plus_minus_scale(key, app);
        changed = 1;
    }
    else if (key == XK_Escape)
        free_all_rscs_exit(app, 0);
    if (changed == 1)
        refresh(app);
    return (0);
}

int key_released(int key, t_app *a)
{
    if (key == XK_Shift_L || key == XK_Shift_R)
        a->option->shift_on = 0;
    return (0);
}

//redraw the picture with connected event
int	expose_hook(void *param)
{
	t_app *app = (t_app *)param;
	refresh(app);
	return 0;
}
