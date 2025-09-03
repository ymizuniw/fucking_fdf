/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:29:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/01 19:56:14 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*base_is(bool is_upper)
{
	const char	*base;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (base);
}

char	*ft_xtoa(unsigned long n, bool is_upper)
{
	char		buf[17];
	const char	*base;
	int			i;
	char		*str;
	int			j;

	base = base_is(is_upper);
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	while (n > 0)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	j = 0;
	while (i-- > 0)
		str[j++] = buf[i];
	return (str);
}
