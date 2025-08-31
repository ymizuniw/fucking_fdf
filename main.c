#include "includes/fdf.h"

// bool draw_map(t_img *img)
// {
// 	//draw maps
// 	//draw
// 	1. draw_lines
// 	2. draw_line
// 	//proj_3d_to_2d
// 	1. convert<proj> 3d vector to 2d vector
// display and the centre of object coordination is fixed

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
	fprintf(stderr, "alloc app content\n");
	prepare_map(argv[1], &app);
	fprintf(stderr, "prepare map\n");
	mlx_app_work(&app);
	fprintf(stderr, "mlx_app_work passed\n");
	return (0);
}
