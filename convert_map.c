/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:15:37 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/08 15:21:01 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// the centre of coordination is half len of img plus accumulated pan.
static void	centering_screen(t_map_2d *ptr, t_app *app)
{
	float	dia;

	dia = sqrtf(app->map->width * app->map->width + app->map->height
			* app->map->height);
	ptr->x += (float)(IMG_WIDTH * 0.5f) + app->mat->pan_x;
	ptr->y += (float)(IMG_HEIGHT * 0.5f) + app->mat->pan_y;
}

// convert 3d map to 2d.
void	convert_map(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->map->map_size)
	{
		app->map->map_2d[i] = convert_points(app->map->map_3d[i], app->mat,
				app->map->width / 2, app->map->height / 2);
		centering_screen(&app->map->map_2d[i], app);
		i++;
	}
}
