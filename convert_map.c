#include "includes/fdf.h"

//how to set it correctly.
static void centering_screen(t_map_2d *ptr, t_app *app)
{
    ptr->x += (float)(app->img->img_width * 0.5f) + app->mat->pan_x;
    ptr->y += (float)(app->img->img_height * 0.5f) + app->mat->pan_y;
}

//convert 3d vector to 2d
void	convert_map(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->map->map_size)
	{
		app->map->map_2d[i] = convert_points(app->map->map_3d[i], app->mat);
        centering_screen(&app->map->map_2d[i], app);
		app->map->map_2d[i].color = app->map->color;
		i++;
	}
}
