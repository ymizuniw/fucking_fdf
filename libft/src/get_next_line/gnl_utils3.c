/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:59:51 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 19:03:12 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	set_fd_node(t_fd *fd_node)
{
	size_t		i;
	t_read_buf	*rd_node;

	if (fd_node->remain_len > 0)
	{
		rd_node = malloc(sizeof(t_read_buf));
		if (!rd_node)
			return ;
		i = 0;
		while (i < fd_node->remain_len)
		{
			rd_node->buffer[i] = fd_node->remain[i];
			i++;
		}
		rd_node->buffer[i] = '\0';
		rd_node->br_flag = (ft_find_br(rd_node->buffer) != (size_t) - 1);
		rd_node->next = NULL;
		fd_node->head = rd_node;
		fd_node->remain_len = 0;
		return ;
	}
	fd_node->head = NULL;
	fd_node->remain_len = 0;
}

bool	read_until_newline(t_fd *node, int fd)
{
	t_read_buf	*new;
	ssize_t		bytes;

	while (1)
	{
		new = malloc(sizeof(t_read_buf));
		if (!new)
			return (false);
		new->br_flag = 0;
		new->next = NULL;
		bytes = read(fd, new->buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(new);
			if (bytes == 0)
				return (node->head != NULL);
			return (false);
		}
		new->buffer[bytes] = '\0';
		new->br_flag = (ft_find_br(new->buffer) != (size_t) - 1);
		append_read_buf(&(node->head), new);
		if (new->br_flag)
			break ;
	}
	return (true);
}

char	*extract_line(t_read_buf *head)
{
	size_t	len;
	char	*line;

	if (!head)
	{
		return (NULL);
	}
	len = get_ext_len(head);
	if (len == 0)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	copy_line(line, head);
	line[len] = '\0';
	return (line);
}
