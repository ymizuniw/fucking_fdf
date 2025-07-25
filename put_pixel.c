#include "includes/fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int		bytes_per_pixel;
	char	*dst;

	if (!img || x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	bytes_per_pixel = img->bits_per_pixel / 8;
	dst = img->data_addr + (y * img->size_line + x * bytes_per_pixel);
	*(int *)dst = color;
}



//Bresenham's line algorithm, round by the measure of delta 0.5
void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;


}
void	draw_scene(t_app *app)
{
	int x;
	int y;
	if (!app || !app->img || !app->img->img_ptr)
		return ;
	for (x = 0; x < app->img->width; x++)
	{
		for (y = 0; y < app->img->height; y++)
			put_pixel(app->img, x, y, (x ^ y) << 16);
		}
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr, 0, 0);
}
