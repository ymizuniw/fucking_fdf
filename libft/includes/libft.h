/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:44:54 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/04 22:20:50 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef unsigned long long	t_uint64;
int							ft_isalpha(char c);
int							ft_isdigit(char c);
int							ft_isalnum(char c);
int							ft_isascii(char c);
int							ft_isprint(char c);
size_t						ft_strlen(const char *s);
void						*ft_memset(void *b, int c, size_t len);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dst, const void *src, size_t n);
void						*ft_memmove(void *dst, const void *src, size_t len);
size_t						ft_strlcpy(char *dst, const char *src, size_t size);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
int							ft_toupper(int c);
int							ft_tolower(int c);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
char						*ft_strnstr(const char *big, const char *little,
								size_t len);
int							ft_atoi(const char *str);
int							ft_atoi_base(const char *str, size_t base);
void						*ft_calloc(size_t count, size_t size);
char						*ft_strdup(const char *s1);
char						*ft_strndup(const char *s1, size_t n);

char						*ft_substr(char const *s, unsigned int start,
								size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s1, char const *set);
char						**ft_split(char const *s, char c);
char						*ft_itoa(int n);
char						*ft_strmapi(char const *s, char (*f)(unsigned int,
									char));
void						ft_striteri(char *s, void (*f)(unsigned int,
									char *));
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(const char *s, int fd);
void						ft_putendl_fd(char *s, int fd);
void						ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

t_list						*ft_lstnew(void *content);
void						ft_lstadd_front(t_list **lst, t_list *new_elem);
int							ft_lstsize(t_list *lst);
t_list						*ft_lstlast(t_list *lst);
void						ft_lstadd_back(t_list **lst, t_list *new_elem);
void						ft_lstdelone(t_list *lst, void (*del)(void *));
void						ft_lstclear(t_list **lst, void (*del)(void *));
void						ft_lstiter(t_list *lst, void (*f)(void *));
t_list						*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));

#endif
