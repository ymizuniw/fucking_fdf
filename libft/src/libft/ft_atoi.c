/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:21:38 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/08 13:24:22 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_max_min(long long res, int sign)
{
	if (sign == 1 && res > INT_MAX)
		return (INT_MAX);
	if (sign == -1 && - res < INT_MIN)
		return (INT_MIN);
	return (0);
}

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (is_space(*nptr))
		nptr++;
	if (is_sign(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = 10 * res + (*nptr - '0');
		if (res == INT_MAX || res == INT_MIN)
			return ((int)is_max_min(res, sign));
		nptr++;
	}
	return (sign * (int)res);
}

// int	main(void)
// {
// 	const char	str[] = "12345";
// 	int	result = ft_atoi(str);
// 	printf("%d", result);
// 	return (0);
// }
