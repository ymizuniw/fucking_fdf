/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:39:38 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/08/31 21:35:00 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// #include <stdio.h>
// int	main (void)
// {
// 	char c;
// 	int res;

// 	c = 'g';
// 	res = ft_isalpha(c);

// 	printf("%d", res);
// 	return (0);
// }
