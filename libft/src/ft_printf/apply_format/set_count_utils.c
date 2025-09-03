/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_count_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:37:56 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/01 20:05:40 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_num_spec(char spec)
{
	return (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x'
		|| spec == 'X');
}

size_t	set_count_sign(t_format *f, char *sign)
{
	if (f->flag_plus || f->flag_space || f->is_negative)
	{
		if (f->flag_plus && !f->is_negative)
			*sign = '+';
		else if (f->flag_plus && f->is_negative)
			*sign = '-';
		else if (f->flag_space && !f->is_negative)
			*sign = ' ';
		else if (f->flag_space && f->is_negative)
			*sign = '-';
		else if (f->is_negative)
			*sign = '-';
		return (1);
	}
	return (0);
}

size_t	set_count_precision(t_format *f, size_t arg_len)
{
	size_t	num_zero;

	num_zero = 0;
	if (f->spec == 'd' || f->spec == 'i' || f->spec == 'x' || f->spec == 'X'
		|| f->spec == 'u')
	{
		if (f->precision_on && f->precision > arg_len)
			num_zero = f->precision - arg_len;
		return (num_zero + arg_len);
	}
	else if (f->spec == 's')
	{
		if (!f->precision_on)
			return (arg_len);
		if (f->precision == 0)
			return (0);
		if (f->precision < arg_len)
			return (f->precision);
		return (arg_len);
	}
	return (arg_len);
}

size_t	set_count_prefix(t_format *f, char *prefix, char *parsed_arg)
{
	if ((f->spec == 'x' || f->spec == 'X') && f->flag_hash
		&& *parsed_arg != '0')
	{
		if (f->spec == 'x')
		{
			prefix[0] = '0';
			prefix[1] = 'x';
		}
		else if (f->spec == 'X')
		{
			prefix[0] = '0';
			prefix[1] = 'X';
		}
		return (2);
	}
	else
		return (0);
}

size_t	set_count_pad(t_format *f, t_lens *lens)
{
	if ((size_t)f->width > lens->total)
	{
		if (f->flag_minus)
			lens->pad_pos = BACK;
		else if (f->flag_zero && !f->precision_on && is_num_spec(f->spec))
			lens->pad_pos = MIDDLE;
		else
			lens->pad_pos = FRONT;
		lens->pad = f->width - lens->total;
		return (lens->pad);
	}
	lens->pad_pos = NONE;
	return (0);
}
