/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:09:55 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 06:59:12 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	count_elems(char **data)
{
	size_t	count;

	count = 0;
	while (data[count])
		count++;
	return (count);
}

int	parse_color(const char *s, size_t *idx, t_point *point)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (*idx + 1));
	if (!tmp)
		return (-1);
	ft_strlcpy(tmp, s, *idx + 1);
	point->height = ft_atoi(tmp);
	free(tmp);
	(*idx)++;
	if ((((ft_strncmp(&s[*idx], "0x", 2) == 0) || ft_strncmp(&s[*idx], "0X",
					2) == 0)) && (s[*idx + 3] && (ft_isdigit(s[*idx + 2])
				|| (('a' <= s[*idx + 2] && s[*idx + 2] <= 'f') || ('A' <= s[*idx
							+ 2] && s[*idx + 2] <= 'F')))))
		point->color = ft_atoi_base(&s[*idx + 2], 16);
	else
	{
		ft_putstr_fd("map format is invalid\n", 2);
		return (-1);
	}
	return (0);
}

t_point	*get_map_info(const char *s)
{
	size_t	i;
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	i = 0;
	if (s[i] && s[i] == '-')
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (!s[i])
	{
		point->height = ft_atoi(s);
		point->color = 0xffffff;
	}
	else if (s[i] == ',')
		if (parse_color(s, &i, point) < 0)
			return (free(point), NULL);
	return (point);
}

int	set_points_array(char **data, t_point **points, size_t count)
{
	size_t	j;

	j = 0;
	while (count > j)
	{
		points[j] = get_map_info((const char *)data[j]);
		if (!points[j])
		{
			ft_putstr_fd("get_map_info failed\n", 2);
			free_points_array(points);
			return (-1);
		}
		j++;
	}
	points[j] = NULL;
	return (0);
}

t_point	**ft_split_map(char *s)
{
	char	**data;
	size_t	count;
	t_point	**points;

	data = ft_split(s, ' ');
	if (!data)
		return (NULL);
	count = count_elems(data);
	if (count == 0)
		return (free_char_ptr_array(data), NULL);
	points = malloc(sizeof(t_point *) * (count + 1));
	if (!points)
		return (free_char_ptr_array(data), NULL);
	if (set_points_array(data, points, count) < 0)
		return (free_char_ptr_array(data), NULL);
	free_char_ptr_array(data);
	return (points);
}
