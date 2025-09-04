/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:27:26 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 07:13:06 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_find_br(const char *str)
{
	size_t	i;

	if (!str)
		return ((size_t) - 1);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return ((size_t)-1);
}

size_t	get_ext_len(t_read_buf *head)
{
	size_t		len;
	size_t		i;
	t_read_buf	*node;

	len = 0;
	node = head;
	while (node)
	{
		i = 0;
		while (node->buffer[i])
		{
			len++;
			if (node->buffer[i++] == '\n')
				return (len);
		}
		node = node->next;
	}
	return (len);
}

void	copy_line(char *line, t_read_buf *head)
{
	size_t		i;
	size_t		j;
	t_read_buf	*node;

	i = 0;
	node = head;
	while (node)
	{
		j = 0;
		while (node->buffer[j])
		{
			line[i++] = node->buffer[j];
			if (node->buffer[j++] == '\n')
			{
				line[i] = '\0';
				return ;
			}
		}
		node = node->next;
	}
	line[i] = '\0';
}

static void	set_rd_buf(t_fd *node, t_read_buf *cur)
{
	size_t	br_idx;
	size_t	buf_idx;
	size_t	j;

	buf_idx = 0;
	if (!cur)
		return ;
	br_idx = ft_find_br(cur->buffer);
	if (br_idx == (size_t)-1)
		return ;
	if (cur->buffer[br_idx] == '\n')
		br_idx++;
	while (cur->buffer[br_idx] && buf_idx < (size_t)BUFFER_SIZE)
		node->remain[buf_idx++] = cur->buffer[br_idx++];
	cur = cur->next;
	while (cur && buf_idx < (size_t)BUFFER_SIZE)
	{
		j = 0;
		while (cur->buffer[j] && buf_idx < (size_t)BUFFER_SIZE)
			node->remain[buf_idx++] = cur->buffer[j++];
		cur = cur->next;
	}
	node->remain[buf_idx] = '\0';
	node->remain_len = buf_idx;
}

void	cleanup_node(t_fd *node)
{
	t_read_buf	*stash;
	t_read_buf	*cur;

	cur = node->head;
	while (cur && !cur->br_flag)
		cur = cur->next;
	if (cur != NULL)
		set_rd_buf(node, cur);
	while (node->head)
	{
		stash = node->head;
		node->head = node->head->next;
		free(stash);
	}
}
