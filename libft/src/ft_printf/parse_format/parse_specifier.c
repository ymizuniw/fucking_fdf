/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:31:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/01 19:56:14 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	parse_specifier(const char *fmt, t_format *f, size_t *place)
{
	if (is_specifier(fmt[*place]))
	{
		f->spec = fmt[*place];
		(*place)++;
		return (true);
	}
	else
	{
		return (false);
	}
}
