#include <includes/fdf.h>

//pan and rotate event
int key_pressed(int key, t_app *a)
{
    if (key == XK_Shift_L || key == XK_Shift_R)
        a->option->shift_on = 1;
    if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
    {
        if (a->option->shift_on)
        {
            if (key == XK_Left)
                pan(a, -PAN_UNIT, 0);
            if (key == XK_Right)
                pan(a, PAN_UNIT, 0);
            if (key == XK_Up)
                pan(a, 0, PAN_UNIT);
            if (key == XK_Down)
                pan(a, 0, -PAN_UNIT);
        }
        else
        {
            if (key == XK_Left)
                rotate_y(a, -ROT_UNIT);
            if (key == XK_Right)
                rotate_y(a, ROT_UNIT);            
            if (key == XK_Up)
                rotate_x(a, ROT_UNIT);
            if (key == XK_Down)
                rotate_x(a, -ROT_UNIT);
        }
        refresh(a);
    }
    else if (key == XK_Escape)
        destroy_exit(a);
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
	draw_field(app);
	return 0;
}
