/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_culc1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:11 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/02 22:09:20 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_vec3	scl(t_vec3 v, float s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	return (v);
}

t_vec3	sub(t_vec3 a, t_vec3 b)
{
	t_vec3	s;

	s.x = a.x - b.x;
	s.y = a.y - b.y;
	s.z = a.z - b.z;
	return (s);
}

float	dot(t_vec3 a, t_vec3 b)
{
	size_t	i;
	float	scl;

	scl = 0.f;
	i = 0;
	while (i < 3)
	{
		if (i == 0)
			scl += a.x * b.x;
		if (i == 1)
			scl += a.y * b.y;
		if (i == 2)
			scl += a.z * b.z;
		i++;
	}
	return (scl);
}

// a x b = aybz - azby, azbx - axbz, axby - aybx;

t_vec3	cross(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_vec3	normalize(t_vec3 v)
{
	float	l2;
	float	inv;

	l2 = dot(v, v);
	if (l2 <= 1e-8f)
		return (scl(v, 0));
	inv = 1.0f / sqrtf(l2);
	return (scl(v, inv));
}
