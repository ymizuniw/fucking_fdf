/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:47:59 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 17:30:22 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*d;

	len = ft_strlen(s);
	if (len + 1 < len)
		return (NULL);
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	*(d + len) = '\0';
	return (d);
}
