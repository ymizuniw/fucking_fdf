/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 06:58:04 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/05 17:50:37 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_points_array(t_point **p)
{
	size_t	k;

	k = 0;
	while (p[k])
		free(p[k++]);
	free(p);
}

void	free_char_ptr_array(char **s)
{
	size_t	k;

	k = 0;
	while (s[k])
		free(s[k++]);
	free(s);
}
