/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:10:10 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 21:03:33 by ymizuniw         ###   ########.fr       */
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
	head->int_array = NULL;
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

	fd = wopen(map_path);
	head = alloc_head();
	if (!head)
		close_free_exit(fd, app, head, "malloc head failed\n");
	if (!get_int_array_list(head, fd))
		close_free_exit(fd, app, head, "map data composed of int?\n");
	wclose(fd);
	alloc_maps(app, head);
	set_map_3d(app, head);
	free_parse_list(head);
}
