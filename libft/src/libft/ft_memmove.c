/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:41:04 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/09 21:41:06 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s)
		return (d);
	else if (d > s)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(d, s, n);
	return (dest);
}

// #include <stdio.h>
// int	main (void)
// {
// 	char src[] = "1234567";
// 	char dest[] = "abcdefg";

// 	ft_memmove(dest, src, 3);
// 	printf("%s", dest);
// 	return (0);
// }
// DESCRIPTION
//  The memmove() function copies n bytes
// 	from memory area src to memory area dest.
// 	The memory areas may overlap: copying takes place as
//  though the bytes in src are first copied into a temporary array
// 	that does not overlap src or dest, and the bytes are then  copied  from
//  the temporary array to dest.

// RETURN VALUE
//        The memmove() function returns a pointer to dest.
