/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_array_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:58 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/02 23:11:22 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

// function to create node and set the int_array
static int	add_int_array_tail(t_parse_list *head, int *int_array)
{
	t_parse_list	*new;

	if (!head || !int_array)
		return (-1);
	new = malloc(sizeof(t_parse_list));
	if (!new)
		return (-1);
	while (head && head->next)
		head = head->next;
	new->int_array = int_array;
	new->next = NULL;
	head->next = new;
	return (0);
}

// get the list whose member have each line of map, int_array.
t_parse_list	*get_int_array_list(t_parse_list *head, int fd)
{
	char	*line;
	int		*int_array;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		int_array = ft_split_map(line);
		free(line);
		if (!int_array)
			return (NULL);
		if (add_int_array_tail(head, int_array) < 0)
			return (NULL);
	}
	return (head);
}
