/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:43:17 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	char	buf[11];
	char	*res;
	int		buf_index;
	int		buf_index_rev;

	if (n == 0)
		return (ft_strdup("0"));
	buf_index = 0;
	while (n > 0)
	{
		buf[buf_index++] = '0' + (n % 10);
		n /= 10;
	}
	res = malloc(buf_index + 1);
	if (!res)
		return (NULL);
	res[buf_index] = '\0';
	buf_index_rev = 0;
	while (--buf_index >= 0)
		res[buf_index_rev++] = buf[buf_index];
	return (res);
}
