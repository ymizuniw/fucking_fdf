/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/02 21:24:52 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr, 0,
		0);
}
