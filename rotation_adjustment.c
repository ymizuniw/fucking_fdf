/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_adjustment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 18:07:12 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

// void	rotation_adjustment(t_app *app, t_vec3 axis, float delta)
// {
// 	t_mat3	rv;
// 	t_mat3	rw;
// 	t_mat3	base;

// 	base = app->mat->usr;
// 	rv = display_axis_rot(axis, delta);
// 	rw = (mat3_transpose(base), mat3_multiply(rv, base));
// 	app->mat->usr = mat3_multiply(rw, app->mat->usr);
// 	orthonormalize(&app->mat->usr);
// }

void	rotation_adjustment(t_app *app, t_vec3 axis, float delta)
{
	t_mat3	rv;

	//base is the current status of matrix usr
	//rv is the rotation from the view of the display. conflict of recognition whether the current state is of 3d or 2d? proj_iso is when 3d to 2d convertion.
	//therefore, the 3d state is maybe not changed? -> what var keep it?
	//
	rv = display_axis_rot(axis, delta);
	app->mat->usr = mat3_multiply(rv, app->mat->usr);
	orthonormalize(&app->mat->usr);
}

//confirm that usr has the right information of the current state of the matrix to apply,
//because if the kept information is misleading, the rotation adjustment will fail.
// maybe the place applying the fixed angle of iso projection is wrong or recognized incorrectly