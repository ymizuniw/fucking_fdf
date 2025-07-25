#include "includes/fdf.h"

void free_all_resources(t_app *app)
{
	if (app->mlx_ptr && app->win_ptr)
	{
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	}
	if (app->mlx_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
	}
	// Free image resources
	if (app->img->img_ptr)
	{
		mlx_destroy_image(app->mlx_ptr, app->img->img_ptr);
	}
	if (app->img->data_addr)
	{
		free(app->img->data_addr);
	}
	free(app->img);
	free(app);
}
