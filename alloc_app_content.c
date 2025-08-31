#include "includes/fdf.h"

//initialize app contents
void	alloc_app_content(t_app *app)
{
    ft_bzero(app, sizeof(*app));
	app->map = malloc(sizeof(t_map));
	if (app->map == NULL)
		perror_exit(MALLOC_FAILURE);
    ft_bzero(app->map, sizeof(*app->map));
	app->mat = malloc(sizeof(t_matrix));
	if (app->mat == NULL)
		free_app(app, "malloc matrix\n");
    ft_bzero(app->mat, sizeof(*app->mat));
    app->mat->scale = 1.0f;
	app->img = malloc(sizeof(t_img));
	if (app->img == NULL)
		free_app(app, "malloc img structure failed\n");
    ft_bzero(app->img, sizeof(*app->img));
    app->option = malloc(sizeof(t_option));
    if (!app->option)
        free_app(app, "malloc option structure failed\n");
    ft_bzero(app->option, sizeof(*app->option));
    app->map->color = 0xFFFFFF;
}
