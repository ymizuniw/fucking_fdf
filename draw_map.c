/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:51 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 06:14:48 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	connect_row(t_img *img, t_map_2d *map_2d, size_t map_width,
		size_t map_height)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map_height)
	{
		x = 0;
		while (x < map_width - 1)
		{
			draw_line(img, &map_2d[y * map_width + x], &map_2d[y * map_width + x
				+ 1]);
			x++;
		}
		y++;
	}
}

static void	connect_column(t_img *img, t_map_2d *map_2d, size_t map_width,
		size_t map_height)
{
	size_t	y;
	size_t	x;

	x = 0;
	while (x < map_width)
	{
		y = 0;
		while (y < map_height - 1)
		{
			draw_line(img, &map_2d[y * map_width + x], &map_2d[(y + 1)
				* map_width + x]);
			y++;
		}
		x++;
	}
}

void	draw_map(t_app *app)
{
	connect_row(app->img, app->map->map_2d, app->map->width, app->map->height);
	connect_column(app->img, app->map->map_2d, app->map->width,
		app->map->height);
}
