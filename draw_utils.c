#include "includes/fdf.h"

//	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//dst holds the infromation of color of the designated pixel.
void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	//1 byte ptr designated by coordination information. the increment unit is 1byte.
	char *dst = img->img_ptr + (y * img->size_line + x * (img->bits_per_pixel));

	//4bytes data set from dst. 
	*(unsigned int *)dst = color;
}

//Bresenham's line algorithm, round by the measure of delta 0.5
void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	//dx
	//dy
	//sign_x
	//sign_y
	//err

	int sign_x;
	int sign_y;

	dx = x1 - x0;
	dy = y1 - y0;
	if (x1 - x0 > 0)
	{
		dx = x1 - x0;
		sign_x = 1;
	}

}

//

// int *p0 = malloc(sizeof(int) * 2);
// *p0 = x0;
// *(p0++) = y0;
//to make it compact


void	BresenHam(int x0, int y0, int x1, int y1)
{
	int sign_x = (x1 > x0) ? 1 : -1;
	int sign_y = (y1 > y0) ? 1 : -1;
	int err = 0;
	int border = 

	if ((sign_x sign_y) > 0)
		bresenham to judge y increment
	else ((sign_x * sign_y) < 0)
		bresenham to judge y decrement
}

void	case_pos()
{

}