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

void redraw(t_app *app)
{
	clear_img(app->img);
	convert_map(app);
	draw_map(app->img, app->map->map_2d, app->map->map_width, app->map->map_height);

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
	t_img	img;

	// Initialize the FDF application >> init_mlx(app);
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, 800, 600, "FDF");
	img.img_ptr = mlx_new_image(app->mlx_ptr, 800, 600);
	img.data_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	app->img = &img;
	draw_map(&img, app->map->map_2d, app->map->width,
		app->map->height);
	mlx_hook(app->win_ptr, KEYPRESS, KEYPRESSMASK, key_pressed, &app);
	mlx_loop(app->mlx_ptr);
	distroy_app(&app);
}

int	prepare_map(char *argv, t_app *app)
{
	int	**map_orig;

	map_orig = NULL;
	w_parse_map(argv, &map_orig, app->map);
	app->map->map_size = app->map->width * app->map->height;
	w_set_map_3d(map_orig, app->map->map_3d, app->map, app->map->color);
	w_set_map_2d(app->map->map_3d, app->map->map_size, app->map->color);
	app->map->map_2d = malloc(sizeof(t_map_2d) * app->map->map_size);
	if (!app->map->map_2d)
	{
		free_double_array(app->map->map_3d);
		free(app->map->map_3d);
		return (-1);
	}
	return (0);
}

void	convert_map(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->map->map_size)
	{
		app->map->map_2d[i] = convert_object(app->map->map_3d[i], app->map->mat);
		app->map->map_2d[i].color = app->map->color;
		i++;
	}
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
	prepare_map(argv[1], &app);
	// react to key events and set rotation angle,
	// set_matrix(mat);
	mlx_app_work(&app);
	return (0);
}
