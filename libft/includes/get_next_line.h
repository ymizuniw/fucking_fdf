/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 00:46:04 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/03 19:01:30 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1000

# define HASH_SIZE 10

# include "libft.h"

// # if BUFFER_SIZE > 100000
// #  error "BUFFER_SIZE too large; risk of overflow or excessive memory usage"
// # endif

// # if BUFFER_SIZE <= 0
// #  error "BUFFER_SIZE must be greater than 0"
// # endif

typedef struct s_read_buf
{
	char				buffer[BUFFER_SIZE + 1];
	bool				br_flag;
	struct s_read_buf	*next;
}						t_read_buf;

typedef struct s_fd
{
	int					fd;
	char				remain[BUFFER_SIZE + 1];
	size_t				remain_len;
	t_read_buf			*head;
	struct s_fd			*next;
}						t_fd;

// main
char					*get_next_line(int fd);
int						hash_fd(int fd);
void					set_fd_node(t_fd *fd_node);
t_fd					*get_fd_node(t_fd **table, int fd);
bool					read_until_newline(t_fd *node, int fd);
char					*extract_line(t_read_buf *head);
void					append_read_buf(t_read_buf **head, t_read_buf *new_buf);

// utils
// void					set_fd_node_buf(t_fd *node);
void					cleanup_fd_node(t_fd **table, int fd);
void					cleanup_node(t_fd *node);
size_t					ft_find_br(const char *str);
size_t					get_ext_len(t_read_buf *head);
void					copy_line(char *dest, t_read_buf *head);

// for caller when file is not EOF and program ends.
void					clear_all_fd_nodes(t_fd **table);
void					gnl_clear(void);
#endif
