#include "includes/fdf.h"

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
