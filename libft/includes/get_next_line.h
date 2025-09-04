/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 00:46:04 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 08:26:01 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_MAX 1024

# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef struct s_read_buf
{
	char				buffer[BUFFER_SIZE + 1];
	t_bool				br_flag;
	struct s_read_buf	*next;
}						t_read_buf;

typedef struct s_fd
{
	int					fd;
	char				remain[BUFFER_SIZE + 1];
	size_t				remain_len;
	t_read_buf			*head;
}						t_fd;

// main
char					*get_next_line(int fd);
void					set_fd_node(t_fd *fd_node, int fd);
t_bool					read_until_newline(t_fd *node, int fd);
char					*extract_line(t_read_buf *head);
void					append_read_buf(t_read_buf **head, t_read_buf *new);

// utils
// void					set_fd_node_buf(t_fd *node);
void					cleanup_node(t_fd *node);
size_t					ft_find_br(const char *str);
size_t					get_ext_len(t_read_buf *head);
void					copy_line(char *dest, t_read_buf *head);

#endif
