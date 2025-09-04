/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:45:44 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 05:38:35 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_is_digit(char n)
{
	return (n >= '0' && n <= '9');
}

// ensure that base is 2 <= base <= 16.
int	ft_atoi_base(const char *s, size_t base)
{
	int		res;
	int		n;
	size_t	i;

	res = 0;
	n = 0;
	i = 0;
	while (s[i])
	{
		if ('a' <= s[i] && s[i] <= 'f')
			n = s[i] - 'a' + 10;
		else if ('A' <= s[i] && s[i] <= 'F')
			n = s[i] - 'A' + 10;
		else if (ft_is_digit(s[i]))
			n = s[i] - '0';
		else
			break ;
		res = res * base + n;
		i++;
	}
	return (res);
}

// int	main(int ac, char **av)
// {
// 	int	res;

// 	res = ft_atoi_base((char const *)av[1], 16);
// 	printf("%d\n", res);
// 	return (0);
// }
