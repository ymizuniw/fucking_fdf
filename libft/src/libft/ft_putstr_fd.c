/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:51:42 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/08/31 23:54:01 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write (fd, s, len);
}

// int main(void)
// {
// 	char *res;

// 	res = malloc(sizeof(char) * INT_MAX);
// 	ft_memset(res, 'a', INT_MAX);
// 	ft_putstr_fd(res, 1);
// 	return 0;
// }
