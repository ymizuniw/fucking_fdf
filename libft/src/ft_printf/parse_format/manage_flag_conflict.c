/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flag_conflict.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:00:57 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_flag_conflict(t_format *f)
{
	if (f->precision_on)
		f->flag_zero = false;
	if (f->flag_plus)
		f->flag_space = false;
	if (f->flag_minus)
		f->flag_zero = false;
	if (!(f->spec == 'x' || f->spec == 'X'))
		f->flag_hash = false;
	if (f->flag_hash)
	{
		f->flag_plus = false;
		f->flag_space = false;
	}
}
