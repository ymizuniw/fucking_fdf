/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:24:43 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 19:01:15 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	hash_fd(int fd)
{
	return (fd % HASH_SIZE);
}

void	append_read_buf(t_read_buf **head, t_read_buf *new)
{
	t_read_buf	*cur;

	if (!*head)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

void	cleanup_fd_node(t_fd **table, int fd)
{
	int		index;
	t_fd	*cur;
	t_fd	*prev;

	index = hash_fd(fd);
	cur = table[index];
	prev = NULL;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (prev)
				prev->next = cur->next;
			else
				table[index] = cur->next;
			cleanup_node(cur);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

void	clear_all_fd_nodes(t_fd *table[HASH_SIZE])
{
	int		i;
	t_fd	*cur;
	t_fd	*next;

	i = 0;
	while (i < HASH_SIZE)
	{
		cur = table[i];
		while (cur)
		{
			next = cur->next;
			cleanup_node(cur);
			free(cur);
			cur = next;
		}
		table[i] = NULL;
		i++;
	}
}
