/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:50:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zero_min_n(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("2147483648"));
}

static unsigned int	process_sign(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa_abs(int n)
{
	char			buf[12];
	unsigned int	num;
	int				buf_index;
	int				rev_index;
	char			*str;

	if (n == 0 || n == -2147483648)
		return (zero_min_n(n));
	buf_index = 0;
	num = process_sign(n);
	while (num > 0)
	{
		buf[buf_index++] = '0' + (num % 10);
		num /= 10;
	}
	str = malloc(buf_index + 1);
	if (!str)
		return (NULL);
	str[buf_index] = '\0';
	rev_index = 0;
	while (buf_index-- > 0)
		str[rev_index++] = buf[buf_index];
	return (str);
}
