/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:55:10 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/08/31 21:35:06 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int c;
// 	int res;

// 	c = '\n';
// 	res = ft_isascii(c);
// 	printf("%d\n", c);
// 	printf("%d", res);
// 	return (0);
// }
