/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:49 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/07 22:20:14 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//put pixel color info to the culculated address from data address of img.
static void	put_pixel(t_img *img, size_t x, size_t y, int color)
{
	char	*dst;

	if (x < 0 || x >= IMG_WIDTH || y < 0 || y >= IMG_HEIGHT)
		return ;
	dst = img->data_addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// draw_line function is based on Bresenham's line drawing algorithm.
static void	initialize_draw_line_struct(t_draw_line *dl, t_map_2d *start,
		t_map_2d *end)
{
	dl->x = (size_t)start->x;
	dl->y = (size_t)start->y;
	dl->dx = (int)end->x - (int)start->x;
	dl->dy = (int)end->y - (int)start->y;
	dl->sign_x = 1;
	dl->sign_y = 1;
	if (dl->dx < 0)
	{
		dl->dx *= -1;
		dl->sign_x *= -1;
	}
	if (dl->dy < 0)
	{
		dl->dy *= -1;
		dl->sign_y *= -1;
	}
}

// x major axis bresenham
static void	x_major_axis(t_draw_line *dl, t_img *img, t_map_2d *start,
		t_map_2d *end)
{
	int	err;

	err = dl->dx / 2;
	while (dl->x != (size_t)end->x)
	{
		put_pixel(img, dl->x, dl->y, start->color);
		err -= dl->dy;
		if (err < 0)
		{
			dl->y += dl->sign_y;
			err += dl->dx;
		}
		dl->x += dl->sign_x;
	}
}

// y major axis bresenham
static void	y_major_axis(t_draw_line *dl, t_img *img, t_map_2d *start,
		t_map_2d *end)
{
	int	err;

	err = dl->dy / 2;
	while (dl->y != (size_t)end->y)
	{
		put_pixel(img, dl->x, dl->y, start->color);
		err -= dl->dx;
		if (err < 0)
		{
			dl->x += dl->sign_x;
			err += dl->dy;
		}
		dl->y += dl->sign_y;
	}
}

// draw_line() put pixels to img buffer by Bresenham's line algorithm.
// start point and end point are given by t_map_2d struct.
void	draw_line(t_img *img, t_map_2d *start, t_map_2d *end)
{
	t_draw_line	dl;

	initialize_draw_line_struct(&dl, start, end);
	if (dl.dx > dl.dy)
		x_major_axis(&dl, img, start, end);
	else
		y_major_axis(&dl, img, start, end);
	put_pixel(img, dl.x, dl.y, start->color);
}
