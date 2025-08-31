#include "includes/fdf.h"

static void	free_exit(t_app *app)
{
	if (app->map)
		free(app->map);
	if (app->mat)
		free(app->mat);
	if (app->img)
		free(app->img);
}

void	alloc_app_content(t_app *app)
{
	app->map = malloc(sizeof(t_map));
	if (app->map == NULL)
		perror_exit(MALLOC_FAILURE);
	app->mat = malloc(sizeof(t_matrix));
	if (app->mat == NULL)
		free_exit(app);
	app->img = malloc(sizeof(t_img));
	if (app->img == NULL)
		free_exit(app);
}
