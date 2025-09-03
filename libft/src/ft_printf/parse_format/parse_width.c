/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:12:26 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(const char *fmt, t_format *f, size_t *place)
{
	if (fmt[*place] == '*')
	{
		f->width_from_arg = 1;
		(*place)++;
	}
	else if (ft_isdigit(fmt[*place]))
	{
		f->width = ft_atoi(fmt + *place);
		while (ft_isdigit(fmt[*place]))
			(*place)++;
	}
}
