/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:55 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/02 21:16:54 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static size_t	count_elem(char *s)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] && s[i] != '\n')
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (!s[i] || s[i] == '\n')
			break ;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		while (ft_isdigit((unsigned char)s[i]))
			i++;
		count++;
		if (s[i] && s[i] != '\n' && s[i] != ' ')
			return (0);
	}
	return (count);
}

static void	free_double_array(char **s)
{
	size_t k;

	k = 0;
	while (s[k])
		free(s[k++]);
	free(s);
}

int	*ft_split_map(char *s)
{
	size_t	count;
	size_t	j;
	char	**n;
	int		*res;

	count = count_elem(s);
	res = malloc(sizeof(int) * (count + 1));
	if (!res)
		return (NULL);
	n = ft_split(s, ' ');
	if (!n)
		return (free(res), NULL);
	j = 0;
	while (j < count)
	{
		res[j] = ft_atoi(n[j]);
		j++;
	}
	res[j] = INT_MIN;
	free_double_array(n);
	return (res);
}
