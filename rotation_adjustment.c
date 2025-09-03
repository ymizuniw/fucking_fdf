/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_adjustment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 21:03:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_adjustment(t_app *app, t_vec3 axis, float delta)
{
	t_mat3	rv;

	rv = display_axis_rot(axis, delta);
	app->mat->usr = mat3_multiply(rv, app->mat->usr);
	orthonormalize(&app->mat->usr);
}
