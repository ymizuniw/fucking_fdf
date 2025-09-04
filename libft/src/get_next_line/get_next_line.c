/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 08:42:31 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 22:49:30 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd	*fd_table[HASH_SIZE];

char	*get_next_line(int fd)
{
	t_fd		*node;
	t_read_buf	*cur;
	char		*got_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_fd_node(fd_table, fd);
	if (!node)
		return (NULL);
	set_fd_node(node);
	cur = node->head;
	if ((!cur || !cur->br_flag) && !read_until_newline(node, fd))
	{
		cleanup_fd_node(fd_table, fd);
		return (NULL);
	}
	got_line = extract_line(node->head);
	cleanup_node(node);
	return (got_line);
}

t_fd	*get_fd_node(t_fd **table, int fd)
{
	int		index;
	t_fd	*cur;
	t_fd	*new;

	index = hash_fd(fd);
	cur = table[index];
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	new = malloc(sizeof(t_fd));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->remain_len = 0;
	new->head = NULL;
	new->next = table[index];
	table[index] = new;
	return (new);
}

void	gnl_clear(void)
{
	clear_all_fd_nodes(fd_table);
}
