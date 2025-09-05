/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:22 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 17:39:28 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_padding(t_app *app, t_set_map stm)
{
	app->map->map_3d[stm.i].z = 0.0f;
	app->map->map_3d[stm.i].x = (float)stm.x;
	app->map->map_3d[stm.i].y = (float)stm.y;
	app->map->map_3d[stm.i].color = 0x000000;
}

static void	fill_map_3d(t_app *app, t_set_map stm, t_parse_list *head)
{
	app->map->map_3d[stm.i].z = (float)head->points[stm.x]->height;
	app->map->map_3d[stm.i].x = (float)stm.x;
	app->map->map_3d[stm.i].y = (float)stm.y;
	app->map->map_3d[stm.i].color = head->points[stm.x]->color;
}

//set map 3d, adjusting lacking or excessive length of line.
void	set_map_3d(t_app *app, t_parse_list *head)
{
	t_set_map	stm;

	head = head->next;
	stm.y = 0;
	while (app->map->height > stm.y && head)
	{
		stm.x = 0;
		stm.start = stm.y * app->map->width;
		stm.line_w = get_map_width(head->points);
		while (stm.line_w > stm.x && app->map->width > stm.x)
		{
			stm.i = stm.start + stm.x;
			fill_map_3d(app, stm, head);
			stm.x++;
		}
		while (app->map->width > stm.x)
		{
			stm.i = stm.start + stm.x;
			fill_padding(app, stm);
			stm.x++;
		}
		head = head->next;
		stm.y++;
	}
}
