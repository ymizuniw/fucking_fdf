#include <includes/fdf.h>

//PROBLEM NOT SOLVED.
//if angle is larger than pi, -2pi,
//else if angle is smaller than -pi, +2pi
//therefore, use while loop to increment/decrement to the range of -pi<theta<pi.

static float round_pi(float theta)
{
    while (theta > (float)M_PI)
        theta -= 2.0f * (float)M_PI;
    while (theta <= (float)M_PI)
        theta += 2.0f * (float)M_PI;
    return (theta);
}

static void validate_angles(t_app *app)
{
    app->mat->theta_x = round_pi(app->mat->theta_x);
    app->mat->theta_y = round_pi(app->mat->theta_y);
}

//what is clamp?
static float clamp_elem(float pan)
{
    if (pan < -PAN_LIMIT)
        return (-PAN_LIMIT);
    else if (pan > PAN_LIMIT)
        return (PAN_LIMIT);
    else
        return (pan);
}

static void clamp_pan(t_app *app)
{
    app->mat->pan_x = clamp_elem(app->mat->pan_x);
    app->mat->pan_y = clamp_elem(app->mat->pan_y);
}

//pan and rotate event
int key_pressed(int key, t_app *app)
{
    int changed = 0;

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
            clamp_pan(app);
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
            validate_angles(app);
        }
        changed = 1;
    }
    //scale adjustment with boundary validation.
    if (key == XK_equal || key == XK_KP_Add || key == XK_minus || key == XK_KP_Subtract || key == XK_Escape)
    {
        if (key == XK_equal || key == XK_KP_Add)
        {
            app->mat->scale *= SCALE_UNIT;
            changed = 1;
        }
        else if (key == XK_minus || key == XK_KP_Subtract)
        {
            app->mat->scale /= SCALE_UNIT;
            changed = 1;
        }
        else if (key == XK_Escape)
            destroy_exit(app);
        clamp_scale(app);
    }
    if (changed == 1)
        refresh(app);
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
