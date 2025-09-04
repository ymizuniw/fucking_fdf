/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:10 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 05:08:21 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// assure that head is non-null ptr
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
	wclose(fd);
	free_parse_list(head);
	free_all_rscs(app, msg);
	gnl_clear();
	ft_putstr_fd("fatal! parse_map failed.\n", 2);
	exit(EXIT_FAILURE);
}

void	parse_map(const char *map_path, t_app *app)
{
	int				fd;
	t_parse_list	*head;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		free_app(app, "open err\n");
		exit(1);
	}
	head = alloc_head();
	if (!head)
		close_free_exit(fd, app, head, "malloc head failed\n");
	if (!get_points_list(head, fd))
		close_free_exit(fd, app, head, "map data composed of int?\n");
	wclose(fd);
	alloc_maps(app, head);
	set_map_3d(app, head);
	free_parse_list(head);
}
