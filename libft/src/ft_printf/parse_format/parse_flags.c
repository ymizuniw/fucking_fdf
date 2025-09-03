/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:02:36 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char *fmt, t_format *f, size_t *place)
{
	while (is_flag(fmt[*place]))
	{
		if (fmt[*place] == '-')
			f->flag_minus = true;
		else if (fmt[*place] == '+')
			f->flag_plus = true;
		else if (fmt[*place] == ' ')
			f->flag_space = true;
		else if (fmt[*place] == '0')
			f->flag_zero = true;
		else if (fmt[*place] == '#')
			f->flag_hash = true;
		(*place)++;
	}
}
