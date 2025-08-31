#include "includes/fdf.h"

void	mlx_app_work(t_app *app)
{
	// Initialize the FDF application >> init_mlx(app);
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, 800, 600, "FDF");
	app->img->img_width = 800;
	app->img->img_height = 600;
	app->img->img_ptr = mlx_new_image(app->mlx_ptr, 800, 600);
	app->img->data_addr = mlx_get_data_addr(&app->img->img_ptr,
			&(app->img->bits_per_pixel), &(app->img->size_line),
			&(app->img->endian));
	refresh(app);
	mlx_hook(app->win_ptr, KEYPRESS, KEYPRESSMASK, key_pressed, app);
	mlx_hook(app->win_ptr, KEYRELEASE, KEYRELEASEMASK, key_released, app);
	mlx_expose_hook(app->win_ptr, expose_hook, app);
	mlx_loop(app->mlx_ptr);
	free_all_rscs(app);
}
