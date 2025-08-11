#include "includes/fdf.h"

//react to key event
int	handle_key(int keycode, void *param)
{
	t_app	*app;
	
	app = (t_app *)param;
	if (keycode == XK_Escape)
		mlx_loop_end(app->mlx_ptr);//mlx loop end. no more key is catched.
	return (0);
}

//react to "X" window close event
int	handle_close(void *param)
{
	t_app *app;

	app = (t_app *)param;
	mlx_loop_end(app->mlx_ptr);//mlx loop end. no more key is catched
	return 0;
}

destroy_app(t_app *app)
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
	if (app->img->img_ptr)
		free(app->img->img_ptr);
	if (app->img)
		free(app->img);
	if (app->win_ptr)
		free(app->win_ptr);
	if (app->mlx_ptr)
		free(app->mlx_ptr);
}

bool draw_map(t_img *img)
{
	//draw maps
	//draw
	1. draw_lines
	2. draw_line
	//proj_3d_to_2d
	1. convert<proj> 3d vector to 2d vector //display and the centre of object coordination is fixed

//additional features for convert<proj> section.
	//another object
	1. project one more object with the same condition or light version
	//rotation
	1. rotation_matrix_multiplication to 3d vector
		//keys
			:shift click + direction key up/down/left/right
	//translation
	1. horizontal -> +x
	2. virtical -> +y
		//keys
		:left/right
		:up/down
	//scale
	1. scalar multiplication for 2d vector
		//keys
		:if it is not complex, straight forward/backward wheel.
		:if it is, +/-
	//color
	1. add some color to "the another object"
		:shift + r/g/b
}

void	clear_img(t_img *img)
{
	ft_bzero(img->data_addr, img->img_height * img->size_line);
}

//draw the picture of parsed 3d map in 2d display
void	draw_field(t_app *app)
{
	//initialize img
	clear_img(app->img);
	//set the mapped vector
	draw_line();
	//put the complete img to the window
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr, 800, 600);
}

//redraw the picture with connected event
int	expose_hook(void *param)
{
	t_app *app = (t_app *)param;
	draw_field(app);
	return 0;
}

// Initialize MiniLibX establish the connection between software and hardware
// get new window
//get new image with image size
//get data addr 
//Assign the image to the app structure
	
//draw lines to image
		// put_pixels();
// Set up event hooks
	// set up for close event with "ESC" in X11 17:ESC
	//handle_close(void *app)
// Enter the event loop

//現在のデータ構造、処理フローをまとめる。
//引数バリデーションのあと、mlxオブジェクトを初期化する。
//マップをパースして、intの二次元マップを取得する。
//map 情報に基づいてwindowにimgとして画像を配置する。

static	void	set_map_array(t_map_3d *p_3d, int **map_orig, int width, int height, int color)
{
	size_t x;
	size_t y;
	size_t i;

	x = 0;
	y = 0;
	i = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			p_3d[i].x = x;
			p_3d[i].y = y;
			p_3d[i].z = map_orig[y][x];
			p_3d[i].color = color;
			i++;
			x++;
		}
		y++;
	}
}

t_map_3d	*set_map_3d(int **map_orig, int width, int height, int color)
{
	t_map_3d	*p_3d;

	p_3d = malloc(sizeof(t_map_3d) * width * height);
	if (!p_3d)
		return (NULL);
	set_map_array(p_3d, map_orig, width, height, color);
	return (p_3d);
}



	void	w_parse_map(char *map_file, char **map_orig, t_map_info *map_info)
	{
		map_orig = parse_map(map_file, map_info);
		if (!map_orig)
		{
			ft_putstr_fd("Error: Failed to parse map.\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	void	w_set_map_3d(int **map_orig, t_map_3d *map_3d, t_map_info *map_info, int color)
	{
		map_3d = set_map_3d(map_orig, map_info->width, map_info->height, color);
		if (!map_3d)
		{
			free_map_orig(map_3d);
			exit (EXIT_FAILURE);
		}
	}

//entry point
int	main(int argc, char **argv)
{
	int				**map_orig;
	int				color = 0xFFFFFF;
	t_map_info		*map_info;
	t_map_2d		*map_2d;
	t_map_3d		*map_3d;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf map_file.fdf\n", 2);
		return (1);
	}
	w_parse_map(argv[1], map_orig, &map_info);
	size_t map_size = map_info->width * map_info->height;
	w_set_map_3d(map_orig, map_3d, map_info, color);
	w_set_map_2d(map_3d, map_size, color);
	map_2d = malloc(sizeof(t_map_2d) * map_size);
	if (!map_2d)
	{
		free_double_array(map_3d);
		free(map_3d);
		return(1);
	}

	t_matrix mat;
	//react to key events and set rotation angle, 
	// set_matrix(mat);
	size_t i = 0;
	while (i < map_size)
	{
		map_2d[i] = convert_object(map_3d[i], &mat);
		map_2d[i].color = color;
		i++;
	}

	t_app	app;
	t_img	img;
	// Initialize the FDF application >> init_mlx(app);
	app.mlx_ptr = mlx_init(); 
	app.win_ptr = mlx_new_window(app.mlx_ptr, 800, 600, "FDF");
	img.img_ptr = mlx_new_image(app.mlx_ptr, 800, 600); 
	img.data_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	app.img = &img;

	draw_map(&app);

	mlx_key_hook(app.win_ptr, handle_key, &app); 
	mlx_hook(app.win_ptr, 17, 0, handle_close, &app);
	mlx_loop(app.mlx_ptr);
	distroy_app(&app);
	return (0);
}
