/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:25:57 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(const char *fmt, t_format *f, size_t *place)
{
	if (fmt[*place] == '.')
	{
		f->precision_on = true;
		(*place)++;
		if (fmt[*place] == '*')
		{
			f->prec_from_arg = true;
			(*place)++;
		}
		else if (ft_isdigit(fmt[*place]))
		{
			f->precision = ft_atoi(fmt + *place);
			while (ft_isdigit(fmt[*place]))
				(*place)++;
		}
		else
			f->precision = 0;
	}
}
