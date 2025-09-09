/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/09 18:44:40 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// before redraw map, clear the img buffer.
static void	clear_img(t_img *img)
{
	ft_bzero(img->data_addr, IMG_HEIGHT * img->size_line);
}

// get the accumulated changes of params and draw map with it.
void	refresh(t_app *app)
{
	clear_img(app->img);
	convert_map(app);
	draw_map(app);
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr,
		(WIN_WIDTH - IMG_WIDTH) / 2, (WIN_HEIGHT - IMG_HEIGHT) / 2);
}
