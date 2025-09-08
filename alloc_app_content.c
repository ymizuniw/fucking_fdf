/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_app_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:39 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/08 16:34:34 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// initialize s_app contents
void	alloc_app_content(t_app *app)
{
	ft_bzero(app, sizeof(*app));
	app->map = malloc(sizeof(t_map));
	if (app->map == NULL)
	{
		ft_putstr_fd("malloc map failed\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(app->map, sizeof(*app->map));
	app->mat = malloc(sizeof(t_matrix));
	if (app->mat == NULL)
		free_app(app, "malloc matrix failed\n");
	ft_bzero(app->mat, sizeof(t_matrix));
	app->mat->usr = mat3_identity();
	app->mat->scale = 1.0f;
	app->img = malloc(sizeof(t_img));
	if (app->img == NULL)
		free_app(app, "malloc img structure failed\n");
	ft_bzero(app->img, sizeof(t_img));
	app->option = malloc(sizeof(t_option));
	if (!app->option)
		free_app(app, "malloc option structure failed\n");
	ft_bzero(app->option, sizeof(t_option));
}
