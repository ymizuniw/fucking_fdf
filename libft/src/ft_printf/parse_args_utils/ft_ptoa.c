/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:33:00 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptoa(void *ptr)
{
	size_t	addr;
	size_t	len;
	char	*hex;
	char	*result;

	if (!ptr)
		return (ft_strdup("(nil)"));
	addr = (size_t)ptr;
	hex = ft_xtoa(addr, 0);
	if (!hex)
		return (NULL);
	len = ft_strlen(hex) + 2;
	result = malloc(len + 1);
	if (!result)
		return (free(hex), NULL);
	result[0] = '0';
	result[1] = 'x';
	ft_memcpy(result + 2, hex, len - 2);
	result[len] = '\0';
	free(hex);
	return (result);
}
