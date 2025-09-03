/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:12:20 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/13 13:32:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	count;
	char	*res;

	if (!src)
		return (NULL);
	res = malloc(n + 1);
	count = 0;
	while (src[count] && count < n)
	{
		res[count] = src[count];
		count++;
	}
	res[count] = '\0';
	return (res);
}
