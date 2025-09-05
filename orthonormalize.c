/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthonormalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:07 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 17:24:34 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//make 3d vector whose bases crosses virtically, following the orthonormalizing formula.
void	orthonormalize(t_mat3 *r)
{
	t_orthon	orth;

	orth.a1.x = r->m[0][0];
	orth.a1.y = r->m[1][0];
	orth.a1.z = r->m[2][0];
	orth.a2.x = r->m[0][1];
	orth.a2.y = r->m[1][1];
	orth.a2.z = r->m[2][1];
	orth.u1 = normalize(orth.a1);
	orth.proj = scl(orth.u1, dot(orth.a2, orth.u1));
	orth.u2_tmp = sub(orth.a2, orth.proj);
	orth.u2 = normalize(orth.u2_tmp);
	orth.u3 = cross(orth.u1, orth.u2);
	r->m[0][0] = orth.u1.x;
	r->m[1][0] = orth.u1.y;
	r->m[2][0] = orth.u1.z;
	r->m[0][1] = orth.u2.x;
	r->m[1][1] = orth.u2.y;
	r->m[2][1] = orth.u2.z;
	r->m[0][2] = orth.u3.x;
	r->m[1][2] = orth.u3.y;
	r->m[2][2] = orth.u3.z;
}
