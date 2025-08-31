#include "includes/fdf.h"

// bool draw_map(t_img *img)
// {
// 	//draw maps
// 	//draw
// 	1. draw_lines
// 	2. draw_line
// 	//proj_3d_to_2d
// 	1. convert<proj> 3d vector to 2d vector
		//display and the centre of object coordination is fixed

// //additional features for convert<proj> section.
// 	//another object
// 	1. project one more object with the same condition or light version
// 	//rotation
// 	1. rotation_matrix_multiplication to 3d vector
// 		//keys
// 			:shift click + direction key up/down/left/right
// 	//translation
// 	1. horizontal -> +x
// 	2. virtical -> +y
// 		//keys
// 		:left/right
// 		:up/down
// 	//scale
// 	1. scalar multiplication for 2d vector
// 		//keys
// 		:if it is not complex, straight forward/backward wheel.
// 		:if it is, +/-
// 	//color
// 	1. add some color to "the another object"
// 		:shift + r/g/b
// }

void	clear_img(t_img *img)
{
	ft_bzero(img->data_addr, img->img_height * img->size_line);
}

void refresh(t_app *app)
{
	clear_img(app->img);
	convert_map(app);
	draw_map(app);
}

// Initialize MiniLibX establish the connection between software and hardware
// get new window
// get new image with image size
// get data addr
// Assign the image to the app structure

// draw lines to image
// put_pixels();
// Set up event hooks
// set up for close event with "ESC" in X11 17:ESC
// handle_close(void *app)
// Enter the event loop

//現在のデータ構造、処理フローをまとめる。
//引数バリデーションのあと、mlxオブジェクトを初期化する。
//マップをパースして、intの二次元マップを取得する。
// map 情報に基づいてwindowにimgとして画像を配置する。

void	mlx_app_work(t_app *app)
{
	// Initialize the FDF application >> init_mlx(app);
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, 800, 600, "FDF");
	app->img->img_width = 800;
	app->img->img_height = 600;
	app->img->img_ptr = mlx_new_image(app->mlx_ptr, 800, 600);
	app->img->data_addr = mlx_get_data_addr(&app->img->img_ptr, &(app->img->bits_per_pixel),
			&(app->img->size_line), &(app->img->endian));
	refresh(app);
	mlx_hook(app->win_ptr, KEYPRESS, KEYPRESSMASK, key_pressed, app);
	mlx_hook(app->win_ptr, KEYRELEASE, KEYRELEASEMASK, key_released, app);
	mlx_expose_hook(app->wind_ptr, expose_hook, app);
	mlx_loop(app->mlx_ptr);
	free_all_resources(app);
}

void alloc_app_content(t_app *app)
{
	app->map = malloc(sizeof(t_map));
	if (app->map == NULL)
		perror_exit();
	app->mat = malloc(sizeof(t_matrix));
	if (app->mat == NULL)
		free_exit();
	app->img = malloc(sizeof(t_img));
	if (app->img == NULL)
		free_exit();
}

// entry point
int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf map_file.fdf\n", 2);
		return (1);
	}
	alloc_app_content(&app);
	prepare_map(argv[1], &app);
	mlx_app_work(&app);
	return (0);
}
