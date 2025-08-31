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
}
