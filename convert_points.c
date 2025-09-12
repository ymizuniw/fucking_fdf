/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:42 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/12 20:04:31 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// maps 3d points to 2d following isometric projection formula.
t_map_2d	convert_points(t_map_3d ptr, t_matrix *mat, float center_x,
		float center_y)
{
	t_map_2d	new;
	t_vec3		v;

	v.x = ptr.x - center_x;
	v.y = ptr.y - center_y;
	v.z = ptr.z;
	v = mat3_apply(mat->usr, v);
	v.x *= mat->scale;
	v.y *= mat->scale;
	v.z *= mat->scale;
	new.x = (v.x - v.y) * COS30;
	new.y = (v.x + v.y) * SIN30 - v.z;
	new.color = ptr.color;
	return (new);
}
