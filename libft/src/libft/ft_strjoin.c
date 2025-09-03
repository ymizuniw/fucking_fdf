/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:24:58 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/09 21:42:18 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*result;
	size_t		s1_len;
	size_t		s2_len;
	long long	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((const char *)s1);
	s2_len = ft_strlen((const char *)s2);
	total_len = (t_uint64)s1_len + (t_uint64)s2_len;
	if (total_len > (size_t)-1)
		return (NULL);
	result = malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}
