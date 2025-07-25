// #include "capture.h"
#include "includes/fdf.h"

// void init_capture(void)
// {
// 	void *mlx_ptr;
// 	int width = 800; // Set the desired width of the window
// 	int height = 600; // Set the desired height of the window
// 	mlx_ptr = mlx_init(); // Initialize the MiniLibX library
// 	mlx_new_window(mlx_ptr, width, height, "Capture Window");
// }
// void capture_screen(void)
// {
// 	// This function would contain the logic to capture the screen
// 	// For now, we will just print a message
// 	printf("Screen captured!\n");
// }

int event_handler(int keycode, void *param)
{
	// Handle key events here
	(void)param; // Avoid unused parameter warning
	if (keycode == 65307) // Escape key
	{
		printf("Escape key pressed, exiting...\n");
		exit(0);
		// free_all_resources();
	}
	return 0;
}

int main(int argc, char **argv)
{
	// Initialize the FDF application
	void *mlx_ptr;
	void *win_ptr;

	(void)argv;
	(void)argc;
	mlx_ptr = mlx_init(); // Initialize MiniLibX
	if (!mlx_ptr)
	{
		fprintf(stderr, "Failed to initialize MiniLibX\n");
		return 1;
	}
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "FDF");
	if (!win_ptr)
	{
		fprintf(stderr, "Failed to create window\n");
		return 1;
	}
	// Set up event hooks
	mlx_hook(win_ptr, KeyPress, KeyPressMask, event_handler, mlx_ptr); // Key press event
	mlx_hook(win_ptr, KeyPress, KeyPressMask, event_handler, mlx_ptr); // Close window event
	mlx_loop(mlx_ptr); // Start the event loop
	return 0;
}
