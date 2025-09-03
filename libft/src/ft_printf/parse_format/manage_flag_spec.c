/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flag_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:19:41 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	manage_char_spec(t_format *f);

void	manage_flag_spec(t_format *f)
{
	if (f->spec == '%')
	{
		f->width = 0;
		f->precision = 0;
	}
	if (f->spec == 'p')
	{
		f->flag_plus = false;
		f->flag_space = false;
		f->flag_hash = false;
	}
	else if (f->spec == 'c' || f->spec == 's')
		manage_char_spec(f);
	else if (is_num_spec(f->spec))
	{
		if (f->flag_plus && f->flag_space)
			f->flag_space = false;
		if (f->precision_on)
			f->flag_zero = false;
	}
}

static void	manage_char_spec(t_format *f)
{
	if (f->spec == 's' && f->precision_on && f->precision == 0)
		f->flag_minus = false;
	f->flag_plus = false;
	f->flag_space = false;
	f->flag_hash = false;
	f->flag_zero = false;
}
