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

t_bool draw_map(t_img *img)
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
	ft_bzero(img->data_addr, img->height * img->size_line);
}

void	draw_lines(t_img *img)
{
	size_t j;

	j = 0;
	while (j < )
		draw_line();
}

//draw the picture of parsed 3d map in 2d display
draw_field(t_app *app)
{
	clear_img(app->img);
	proj_3d_to_2d();
	draw_lines();
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr, 800, 600);
}

//redraw the picture with connected event
int expose_hook(void *param)
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

//entry point
int	main(int argc, char **argv)
{

	// //parse map
	// t_parsing par;//wrapping struct
	// t_map map;
	
	// parse_map(t_map *map);
	// set_three_dimentional_vector(map, &par.v_third);

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
