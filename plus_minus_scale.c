/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus_scale.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:14 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 21:03:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plus_minus_scale(int key, t_app *app)
{
	if ((key == XK_equal || key == XK_KP_Add) && (app->mat->scale
			* SCALE_UNIT < SCALE_LIM_L))
		app->mat->scale *= SCALE_UNIT;
	else if (app->mat->scale / SCALE_UNIT > SCALE_LIM_S)
		app->mat->scale /= SCALE_UNIT;
}
