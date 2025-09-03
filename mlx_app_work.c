/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_app_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:05 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 20:55:13 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	close_pressed(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	free_all_rscs_exit(app, 0);
	return (0);
}

void	mlx_app_work(t_app *app)
{
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	app->img->img_width = IMG_WIDTH;
	app->img->img_height = IMG_HEIGHT;
	app->img->img_ptr = mlx_new_image(app->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	app->img->data_addr = mlx_get_data_addr(app->img->img_ptr,
			&(app->img->bits_per_pixel), &(app->img->size_line),
			&(app->img->endian));
	refresh(app);
	mlx_hook(app->win_ptr, KEYPRESS, KEYPRESSMASK, key_pressed, app);
	mlx_hook(app->win_ptr, KEYRELEASE, KEYRELEASEMASK, key_released, app);
	mlx_hook(app->win_ptr, DestroyNotify, NoEventMask, close_pressed, app);
	mlx_expose_hook(app->win_ptr, expose_hook, app);
	mlx_loop(app->mlx_ptr);
}
