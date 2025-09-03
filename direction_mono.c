/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_mono.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:44 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 21:03:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	get_axis_z(void)
{
	t_vec3	axis;

	axis.x = 0.f;
	axis.y = 0.f;
	axis.z = 1.f;
	return (axis);
}

t_vec3	get_axis_x(void)
{
	t_vec3	axis;

	axis.x = cosf(15.f);
	axis.y = sinf(15.f);
	axis.z = 0.f;
	return (axis);
}

void	direction_mono(int key, t_app *app)
{
	t_vec3	axis_x;
	t_vec3	axis_z;

	axis_x = get_axis_x();
	axis_z = get_axis_z();
	if (key == XK_Left)
		rotation_adjustment(app, axis_z, ROT_UNIT);
	else if (key == XK_Right)
		rotation_adjustment(app, axis_z, -ROT_UNIT);
	else if (key == XK_Up)
		rotation_adjustment(app, axis_x, -ROT_UNIT);
	else if (key == XK_Down)
		rotation_adjustment(app, axis_x, ROT_UNIT);
}
