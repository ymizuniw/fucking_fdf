#include "includes/fdf.h"

int	handle_key(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app)
	{
		fprintf(stderr, "App parameter is NULL\n");
		return (0);
	}
	// Handle key events here
	if (keycode == XK_Escape) // Escape key
	{
		mlx_destroy_window(app->mlx_ptr, app->win_ptr); // Close the window
		printf("Escape key pressed, exiting...\n");
		exit(0);
		// free_all_resources();
	}
	return (0);
}

int	handle_close(void *param)
{
	t_app	*app;

	// Handle window close event
	app = (t_app *)param;
	mlx_destroy_window(app->mlx_ptr, app->win_ptr); // Close the window
	printf("Window closed, exiting...\n");
	exit(0);
	// free_all_resources();
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	app;
	t_img	img;

	// Initialize the FDF application
	if (argc != 1)
	{
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return (1);
	}
	app.mlx_ptr = mlx_init(); // Initialize MiniLibX
	if (!app.mlx_ptr)
	{
		fprintf(stderr, "Failed to initialize MiniLibX\n");
		return (1);
	}
	app.win_ptr = mlx_new_window(app.mlx_ptr, 800, 600, "FDF");
	if (!app.win_ptr)
	{
		fprintf(stderr, "Failed to create window\n");
		return (1);
	}
	img.img_ptr = mlx_new_image(app.mlx_ptr, 800, 600);
	if (!img.img_ptr)
	{
		fprintf(stderr, "Failed to create image\n");
		mlx_destroy_window(app.mlx_ptr, app.win_ptr);
		return (1);
	}
	img.data_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	if (!img.data_addr)
	{
		fprintf(stderr, "Failed to get image data address\n");
		mlx_destroy_image(app.mlx_ptr, img.img_ptr);
		mlx_destroy_window(app.mlx_ptr, app.win_ptr);
		return (1);
	}
	app.img = &img; // Assign the image to the app structure
	// Draw the scene
	draw_scene(&app);
	// Set up event hooks
	mlx_key_hook(app.win_ptr, handle_key, &app);
	mlx_hook(app.win_ptr, 17, 0, handle_close, &app);
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img->img_ptr, 0, 0);
	mlx_loop(app.mlx_ptr); // Enter the event loop
	return (0);
}
