#include "includes/fdf.h"

static void	clear_img(t_img *img)
{
	ft_bzero(img->data_addr, img->img_height * img->size_line);
}

void	refresh(t_app *app)
{
	clear_img(app->img);
	convert_map(app);
	draw_map(app);
    mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr, 0, 0);
}
