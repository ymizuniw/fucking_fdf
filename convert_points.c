/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:42 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/04 20:26:01 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

// t_map_2d	convert_points(t_map_3d ptr, t_matrix *mat)
// {
// 	t_map_2d	new;
// 	t_vec3		v;

// 	v.x = ptr.x;
// 	v.y = ptr.y;
// 	v.z = ptr.z;
// 	//mat->usr を三次元ベクトルｖに適用する。これにより、まずモデルの回転を行う。
// 	v = mat3_apply(mat->usr, v);
// 	//ここで三次元から二次元への射影を行う。公式に従い実装する。
// 	new.x = (v.x - v.y) * COS30;
// 	new.y = (v.x + v.y) * SIN30 - v.z;
// 	new.x *= mat->scale;
// 	new.y *= mat->scale;
// 	//set color info.
// 	new.color = ptr.color;
// 	return (new);
// }
