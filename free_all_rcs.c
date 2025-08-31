#include "includes/fdf.h"

//free vectors
void free_map(t_app *app)
{
	if (!app || !app->map)
		return ;
	if(app->map->map_2d)
		free(app->map->map_2d);
	if (app->map->map_3d)
		free(app->map->map_3d);
	free(app->map);
}

void	free_app(t_app *app, const char *msg)
{
	if (app->map)
		free_map(app);
	if (app->mat)
		free(app->mat);
	if (app->img)
		free(app->img);
    if (app->option)
	{
		free(app->option);
	}
	ft_putstr_fd(msg, 2);
}

void	free_all_rscs(t_app *app, const char *msg)
{	
	if (app && app->img->img_ptr)
		mlx_destroy_image(app->mlx_ptr, app->img->img_ptr);
	if (app && app->mlx_ptr && app->win_ptr)
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	if (app && app->mlx_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
	}
	free_app(app, msg);
}

void free_all_rscs_exit(t_app *app, int status)
{
	free_all_rscs(app, "fuck\n");
	exit(status);
}
