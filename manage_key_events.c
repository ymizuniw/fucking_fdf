#include <includes/fdf.h>

static int validate_angle(t_app *app)
{
    if (app->mat->pan_x + PAN_UNIT > PI)
        app->mat->pan_x = 
}

//pan and rotate event
int key_pressed(int key, t_app *app)
{
    if (key == XK_Shift_L || key == XK_Shift_R)
        app->option->shift_on = 1;
    //pan and rot adjustment with boundary validation

    //validation for overing 2p

    if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
    {
        if (app->option->shift_on)
        {
            if (key == XK_Left)
                app->mat->pan_x -= PAN_UNIT;
            else if (key == XK_Right)
                app->mat->pan_x += PAN_UNIT;
            else if (key == XK_Up)
                app->mat->pan_y -= PAN_UNIT;
            else if (key == XK_Down)
                app->mat->pan_y += PAN_UNIT;
        }
        else
        {
            if (key == XK_Left)
                app->mat->theta_y -= ROT_UNIT;
            else if (key == XK_Right)
                app->mat->theta_y += ROT_UNIT;
            else if (key == XK_Up)
                app->mat->theta_x += ROT_UNIT;
            else if (key == XK_Down)
                app->mat->theta_x -= ROT_UNIT;
            validate_angle(app);
        }
    }
    //scale adjustment with boundary validation.
    if (key == XK_equal || key == XK_KP_Add || key == XK_minus || key == XK_KP_Subtract || key == XK_Escape)
    {
        if (key == XK_equal || XK_KP_Add)
            app->mat->scale *= SCALE_UNIT;
        else if (key == XK_minus || key == XK_KP_Subtract)
                app->mat->scale /= SCALE_UNIT;
        else if (key == XK_Escape)
            destroy_exit(app);
        clamp_scale(app);
        if (key != XK_Escape)
            refresh(app);
    }
    return (0);
}

//shift released, then turn the shift_on flag on.
//if BottonReleaseMask is called, then call this function.
int key_released(int key, t_app *a)
{
    if (key == XK_Shift_L || key == XK_Shift_R)
        a->option->shift_on = 0;
    return (0);
}

//how to descriminate the shift_pressed and shift_released?
//this is registered by the mlx, like XK_Key_release.

//redraw the picture with connected event
int	expose_hook(void *param)
{
	t_app *app = (t_app *)param;
	draw_map(app);
	return 0;
}
