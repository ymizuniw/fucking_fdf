#include "includes/fdf.h"

//mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
//dst holds the infromation of color of the designated pixel.
void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->img_width || y < 0 || y >= img->img_height)
		return ;
	//1 byte ptr designated by coordination information. the increment unit is 1byte.
	char *dst = img->img_ptr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	//4bytes data set from dst. 
	*(unsigned int *)dst = color;
}
		// err += dx;/基準値がdx/2より、dyを減算することで誤差の蓄積を行う。境界値を超えたら、dxに1加算することで、dxの1ピクセル分の増分に対して1ピクセルの増加により修正された新しい誤差から次の境界到達値までの基準値を設定する。
		//dy >= dx / 2がピクセル上でyの増加条件になることは簡単に分かる。xの１単位増加に対して、yのfloat時の増加量が0.5を上回るなら、次のピクセルに進む方が、数値とグラフ表現の整合性が取れる。
		//そして、yを1単位増加させたなら、誤差は1ピクセル分リセットされるべきである。この「１ピクセル分のリセット」が味噌で、acu_err = dy / dx > 0.5 -> acu_err * dx = dy > 0.5dxとしているので、
		//acu_err -= 1 -> acu_err * dx -= dx　となる。恒等式である。
		//もっとも簡単なのは、傾きm = dy/dx: 0 < m < 1 の場合である。ここで、m > 1の場合を考えると、xが1変化した時のyの変化量が1を超え、mが90°に近づくに連れて、xの増加量に対するyの増加量が限りなく増えていき、x, ++x間でyのピクセルが大きく飛ぶことになる。
		//これを避けながら全方向の直線を描画するために、主軸の変更という手法を用いる。これは、直線が恒等写像であることを利用した逆関数の利用に近い。
		//①dy/dx < 1 ならばxが1ピクセル移動した時にyは1ピクセル以下の移動に収まる。②dy/dx > 1ならば、主軸を変換して、xをyの関数とみなす。これにより、直線の傾きはdx/dyとなり、
		//dy/dx > 1より、1 > dx/dyであるから、①の場合に帰着できる。
		//x, yの進行方向はsignにより定義し、適切に加算代入する。これにより、任意の2点間で密度の高い直線を引くことができる。

//直線の端点の位置を示すとともに、色の情報も示す必要がある。
//Bresenham's line algorithm, round by the measure of delta 0.5 to flexible scaling by x or y way.

static void	initialize_draw_line_struct(t_draw_line dl)
{
	dl.dx = 0;
	dl.dy = 0;
	dl.x = 0;
	dl.y = 0;
	dl.sign_x = 0;
	dl.sign_y = 0;
	dl.err = 0;
}

//if map_2d is set as two dimention array, then it can be referenced by [y][x].
void	draw_line(t_img *img, t_map_2d *start, t_map_2d *end)
{
	t_draw_line dl;

	initialize_draw_line_struct(dl);
	dl.x = (int)start->x;
	dl.y = (int)start->y;
	dl.dx = (int)end->x - start->x;
	dl.dy = (int)end->y - start->y;
	//set dx positive
	if (dl.dx < 0)
	{
		dl.dx *= -1;
		dl.sign_x *= - 1;
	}
	//set dy positive
	if (dl.dy < 0)
	{
		dl.dy *= -1;
		dl.sign_y *= -1;
	}
	//condition to keep dividing num bigger than devided.
	//color set problem is not solved.

	//vec_2 is set as if two dimention arrray, but the way to access is
	//img->data_addr + (y * img->size_line + x);
	if (dl.dx > dl.dy)
	{
		dl.err = dl.dx / 2;
		while (dl.x != (int)end->x)
		{
			put_pixel(img, dl.x, dl.y, start->color);
			dl.err -= dl.dy;
			if (dl.err < 0)
			{
				dl.y += dl.sign_y;
				dl.err -= dl.dx;
				start->y += dl.sign_y;
			}
			dl.x += dl.sign_x;
		}
	}
	else
	{
		dl.err = dl.dy / 2;
		while (dl.y != (int)end->y)
		{
			put_pixel(img, dl.x, dl.y, start->color);
			dl.err -= dl.dx;
			if (dl.err < 0)
			{
				dl.x += dl.sign_x;
				dl.err += dl.dy;
			}
			dl.y += dl.sign_y;
		}
	}
	put_pixel(img, dl.x, dl.y, start->color);
}
