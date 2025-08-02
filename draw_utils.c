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

	int dx;
	int dy;
	int sign_x;
	int sign_y;
	int err;
	
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0)
	{
		dx *= - 1;
		sign_x *= - 1;
	}
	if (dy < 0)
	{
		dy *= -1;
		sign_y *= -1;
	}
	if (dx > dy)
	{
		err = dx / 2;
		while (x < dx)
		{
			put_pixel();
			err -= dy;
			if (err < 0)
			{
				y += sign_y;
				// err += dx;/基準値がdx/2より、dyを減算することで誤差の蓄積を行う。境界値を超えたら、dxに1加算することで、dxの1ピクセル分の増分に対して1ピクセルの増加により修正された新しい誤差から次の境界到達値までの基準値を設定する。
				//dy >= dx / 2がピクセル上でyの増加条件になることは簡単に分かる。xの１単位増加に対して、yのfloat時の増加量が0.5を上回るなら、次のピクセルに進む方が、数値とグラフ表現の整合性が取れる。
				//そして、yを1単位増加させたなら、誤差は1ピクセル分リセットされるべきである。この「１ピクセル分のリセット」が味噌で、acu_err = dy / dx > 0.5 -> acu_err * dx = dy > 0.5dxとしているので、
				//acu_err -= 1 -> acu_err * dx -= dx　となる。恒等式である。
				//もっとも簡単なのは、傾きm = dy/dx: 0 < m < 1 の場合である。ここで、m > 1の場合を考えると、xが1変化した時のyの変化量が1を超え、mが90°に近づくに連れて、xの増加量に対するyの増加量が限りなく増えていき、x, ++x間でyのピクセルが大きく飛ぶことになる。
				//これを避けながら全方向の直線を描画するために、主軸の変更という手法を用いる。これは、直線が恒等写像であることを利用した逆関数の利用に近い。
				// ①dy/dx < 1 ならばxが1ピクセル移動した時にyは1ピクセル以下の移動に収まる。②dy/dx > 1ならば、主軸を変換して、xをyの関数とみなす。これにより、直線の傾きはdx/dyとなり、
				//dy/dx > 1より、1 > dx/dyであるから、①の場合に帰着できる。
				err -= dx;
			}
			x += sign_x;
		}
	}
}

