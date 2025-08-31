#include "includes/fdf.h"

void	free_all_resources(t_app *app)
{
	if (app && app->mlx_ptr && app->win_ptr)
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	if (app && app->mlx_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
	}
	if (app->mat)
		free(app->mat);
	free_map(app);
	// Free image resources
	if (app && app->img->img_ptr)
		mlx_destroy_image(app->mlx_ptr, app->img->img_ptr);
}

//free vectors
void free_map(t_app *app)
{
	if (!app || !app->map)
		return ;
	if(app->map->map_2d)
		free(app->map->map_2d);
	if (app->map->map_3d)
		free(app->map->map_3d);
	free(map);
}
