/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:58 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/04 21:55:50 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// create node and set the points
static int	add_points_tail(t_parse_list *head, t_point **points)
{
	t_parse_list	*new;

	if (!head || !points)
		return (-1);
	new = malloc(sizeof(t_parse_list));
	if (!new)
		return (-1);
	while (head && head->next)
		head = head->next;
	new->points = points;
	new->next = NULL;
	head->next = new;
	return (0);
}

// read map and set each line info to correspoinding s_parse_list node.
t_parse_list	*get_points_list(t_parse_list *head, int fd)
{
	char	*line;
	t_point	**points;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		points = ft_split_map(line);
		free(line);
		if (!points)
			return (NULL);
		if (add_points_tail(head, points) < 0)
			return (ft_putstr_fd("here", 2), NULL);
	}
	return (head);
}
