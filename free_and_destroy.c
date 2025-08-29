#include <includes/fdf.h>

void destroy_app(t_app *app)
{
	//clear window ?
	mlx_clear_window(app->mlx_ptr, app->win_ptr);
	//detroy the image
	if (app->img->img_ptr)
		mlx_destroy_image(app->mlx_ptr, app->img->img_ptr);
	//destroy the window
	if (app->win_ptr)
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	//destroy the display
	mlx_destroy_display(app->mlx_ptr);
	//free mlx ptr
	free_app(app);
}

void free_app(t_app *app)
{
	if (app->img->data_addr)
		free(app->img->data_addr);
	if (app->img)
		free(app->img);
}

//t_app 's direct members should be freed, but the content of each member is not.
//because they are internally processed by mlx.