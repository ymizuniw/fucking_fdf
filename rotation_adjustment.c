/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_adjustment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/02 21:24:34 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_mat3	mat3_transpose(t_mat3 a)
{
	t_mat3	ta;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			ta.m[i][j] = a.m[j][i];
			j++;
		}
		i++;
	}
	return (ta);
}

t_mat3	mat3_identity(void)
{
	t_mat3	iden;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i == j)
				iden.m[i][j] = 1;
			else
				iden.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (iden);
}

t_mat3	mat3_multiple(t_mat3 a, t_mat3 b)
{
	t_mat3	r;
	size_t	i;
	size_t	j;
	size_t	k;

	ft_bzero(&r, sizeof(t_mat3));
	i = 0;
	j = 0;
	k = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			while (k < 3)
			{
				r.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (r);
}

t_vec3	mat3_apply(t_mat3 m, t_vec3 v)
{
	t_vec3	rv;

	rv.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z;
	rv.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z;
	rv.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z;
	return (rv);
}

typedef struct s_axis_rot
{
	float	x;
	float	y;
	float	z;
	float	c;
	float	s;
	float	t;
}			t_axis_rot;

t_mat3	display_axis_rot(t_vec3 axis, float angle)
{
	float		len;
	t_axis_rot	ax;
	t_mat3		r;

	len = sqrtf(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
	if (len < (float)(1e-8))
		return (mat3_identity());
	ax.x = axis.x / len;
	ax.y = axis.y / len;
	ax.z = axis.z / len;
	ax.c = cosf(angle);
	ax.s = sinf(angle);
	ax.t = 1.f - ax.c;
	r.m[0][0] = ax.t * ax.x * ax.x + ax.c;
	r.m[0][1] = ax.t * ax.x * ax.y - ax.s * ax.z;
	r.m[0][2] = ax.t * ax.x * ax.z + ax.s * ax.y;
	r.m[1][0] = ax.t * ax.y * ax.x + ax.s * ax.z;
	r.m[1][1] = ax.t * ax.y * ax.y + ax.c;
	r.m[1][2] = ax.t * ax.y * ax.z - ax.s * ax.x;
	r.m[2][0] = ax.t * ax.z * ax.x - ax.s * ax.y;
	r.m[2][1] = ax.t * ax.z * ax.y + ax.s * ax.x;
	r.m[2][2] = ax.t * ax.z * ax.z + ax.c;
	return (r);
}

// app->mat 内に：base_rot(B), user_rot(U) を持つ設計を推奨
// 等角ベース：B = Rz(45°) * Rx(35.264°) を初期化時に作る

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
