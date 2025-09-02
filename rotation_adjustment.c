/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_adjustment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/02 22:20:26 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	rotation_adjustment(t_app *app, t_vec3 axis_screen, float delta)
{
	t_mat3	rv;
	t_mat3	rw;
	t_mat3	base;

	base = app->mat->usr;
	rv = display_axis_rot(axis_screen, delta);
	rw = mat3_multiple(mat3_transpose(base), mat3_multiple(rv, base));
	app->mat->usr = mat3_multiple(rw, app->mat->usr);
	orthonormalize(&app->mat->usr);
}
