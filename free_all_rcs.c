#include "includes/fdf.h"

void	free_all_resources(t_app *app)
{
	if (app && app->mlx_ptr && app->win_ptr)
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	if (app && app->mlx_ptr)
		mlx_destroy_display(app->mlx_ptr);
	// Free image resources
	if (app && app->img->img_ptr)
		mlx_destroy_image(app->mlx_ptr, app->img->img_ptr);
	if (app && app->img->data_addr)
		free(app->img->data_addr);
	if (app && app->img)
		free(app->img);
	if (app)
		free(app);
}

//free vectors

void free_map(app)
{
	//original map : 

	//3d map

	//2d map

	//for all maps, ensure that they are with if (exist) condition.
}