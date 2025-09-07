/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:10 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/07 21:47:13 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// allocate a dummy head. 
static t_parse_list	*alloc_head(void)
{
	t_parse_list	*head;

	head = malloc(sizeof(t_parse_list));
	if (head == NULL)
		return (NULL);
	head->points = NULL;
	head->next = NULL;
	return (head);
}

void	close_free_exit(int fd, t_app *app, t_parse_list *head, const char *msg)
{
	if (close(fd) < 0)
		perror("close");
	free_parse_list(head);
	free_all_rscs(app, msg);
	ft_putstr_fd("fatal! parse_map failed.\n", 2);
	exit(EXIT_FAILURE);
}

static void	free_app_exit(t_app *app, const char *msg)
{
	free_app(app, msg);
	exit(EXIT_FAILURE);
}

//parse map and get height and color of each points.
void	parse_map(const char *map_path, t_app *app)
{
	int				fd;
	t_parse_list	*head;
	size_t			len;

	len = ft_strlen(map_path);
	if (ft_strncmp(&map_path[len - 4], ".fdf", 4) != 0)
		free_app_exit(app, "file format is incorrect. provide .fdf file\n");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		free_app_exit(app, "open map file failed\n");
	head = alloc_head();
	if (!head)
		close_free_exit(fd, app, head, "malloc head failed\n");
	if (!get_points_list(head, fd))
		close_free_exit(fd, app, head, "map data composed of int?\n");
	if (close(fd) < 0)
		perror("close");
	alloc_maps(app, head);
	set_map_3d(app, head);
	free_parse_list(head);
}
