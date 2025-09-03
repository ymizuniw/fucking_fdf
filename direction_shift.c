/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_shift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:47 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 21:03:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	direction_shift(int key, t_app *app)
{
	if (key == XK_Left && app->mat->pan_x - PAN_UNIT >= -PAN_LIM_W)
		app->mat->pan_x -= PAN_UNIT;
	else if (key == XK_Right && app->mat->pan_x + PAN_UNIT <= PAN_LIM_W)
		app->mat->pan_x += PAN_UNIT;
	else if (key == XK_Up && app->mat->pan_y - PAN_UNIT >= -PAN_LIM_H)
		app->mat->pan_y -= PAN_UNIT;
	else if (key == XK_Down && app->mat->pan_y + PAN_UNIT <= PAN_LIM_H)
		app->mat->pan_y += PAN_UNIT;
}
