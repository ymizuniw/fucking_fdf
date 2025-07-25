// #include "capture.h"
// #include "fdf.h"
#include "mlx.h"


void init_capture(void)
{
	void *mlx_ptr;
	int width = 800; // Set the desired width of the window
	int height = 600; // Set the desired height of the window
	mlx_ptr = mlx_init(); // Initialize the MiniLibX library
	mlx_new_window(mlx_ptr, width, height, "Capture Window");


}

int main(int argc, char **argv)
{
	// Initialize the FDF application
	// fdf_init(argc, argv);

	// Capture the screen or perform some operations
	// capture_screen();

	// Finalize and clean up resources
	// fdf_cleanup();

	return 0;
}
