/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:42 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 17:12:11 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//maps 3d points to 2d following isometric projection formula.
t_map_2d	convert_points(t_map_3d ptr, t_matrix *mat)
{
	t_map_2d	new;
	t_vec3		v;

	v.x = ptr.x;
	v.y = ptr.y;
	v.z = ptr.z;
	v = mat3_apply(mat->usr, v);
	new.x = (v.x - v.y) * COS30;
	new.y = (v.x + v.y) * SIN30 - v.z;
	new.x *= mat->scale;
	new.y *= mat->scale;
	new.color = ptr.color;
	return (new);
}
