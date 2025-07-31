#include "includes/fdf.h"

//	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//Bresenham's line algorithm, round by the measure of delta 0.5
void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	//start（x0, y0）、end (x1, y1)
	//the length of edge = sqrt((x1 - x0)^2 + (y1 - y0)^2);


	//define which point is to start;
	small_x = min (x0, x1);
	if (small_x == x0)
	{
		start_x = x0;
		start_y = y0;
		end_x = x1;
		end_y = y1;
	}
	else
	{
		start_x = x1;
		start_y = y1;
		end_x = x0;
		end_y = y0;
	}

	//define delta x and y

	int	  dx = end_x - start_x // 0 < end_x - start_x < width
	int   dy = end_y - start_y // 0 < end_y - start_y < height

	//define slope
	int   a = dy / dx;

	size_t scale = 2 * dx;

	size_t derr;
	size_t err;

	
	while (!(x == end_x && y == end_y))
	{
		derr = 2 * dy * dx;
		err += derr;
		if (err > dx)
			y++;
		mlx_pixel_put(app->mlx_ptr, app->win_ptr, x, y, 1);
		x++;
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

dx = abs(x1 - x0)
dy = -abs(y1 - y0)
int sign_x = (x1 > x0) ? 1 : -1;
int sign_y = (y1 > y0) ? 1 : -1;
int err = 

D = dy;
if (err )



y = (dy/dx) * x + C

dx * y = dy * x + C

xdy - ydx + C = 0;

2 * xdy - 2 * ydx + C = 0;


// if y is less by 0.5 or more, the left value will INCREASE.
// However, you don't wanna use float, so multiply by 2 both ends.
//
// Then, increment y++ to adjust the equation keep established.
// Thuss, the equation below is used to judgement.

int err = 2 * xdy - 2 * ydx + C;
if (err != 0)
	y++;
