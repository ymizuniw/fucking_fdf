/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:17 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 10:30:34 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign_of_int(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	count_digit(int n, int sign)
{
	int	count;

	if (n == 0)
		return (1);
	if (sign == -1)
		count = 1;
	else
		count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	set_digit(char *res, int i, int n)
{
	res[i] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		--i;
		res[i] = '0' + (n % 10);
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = sign_of_int(n);
	n = n * sign;
	i = count_digit(n, sign);
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	if (sign == -1)
		res[0] = '-';
	set_digit(res, i, n);
	return (res);
}
