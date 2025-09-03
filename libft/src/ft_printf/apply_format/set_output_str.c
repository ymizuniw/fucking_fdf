/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:03:38 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prefix_output(char *output_str, size_t *buf_index,
				t_parts_out *parts, t_lens *lens);
static void	args_output(char *output_str, size_t *buf_index, t_parts_out *parts,
				t_lens *lens);

void	set_output_str(char *output_str, t_parts_out *parts, t_lens *lens)
{
	size_t	buf_index;

	buf_index = 0;
	prefix_output(output_str, &buf_index, parts, lens);
	args_output(output_str, &buf_index, parts, lens);
	output_str[buf_index] = '\0';
	lens->total = buf_index;
}

static void	prefix_output(char *output_str, size_t *buf_index,
		t_parts_out *parts, t_lens *lens)
{
	if (lens->pad_pos == FRONT)
	{
		ft_memset(output_str + *buf_index, ' ', lens->pad);
		*buf_index += lens->pad;
	}
	if (lens->prefix)
	{
		ft_memcpy(output_str + *buf_index, parts->prefix, lens->prefix);
		*buf_index += lens->prefix;
	}
	if (lens->sign)
	{
		ft_memcpy(output_str + *buf_index, parts->sign, lens->sign);
		*buf_index += lens->sign;
	}
}

static void	args_output(char *output_str, size_t *buf_index, t_parts_out *parts,
		t_lens *lens)
{
	if (lens->pad_pos == MIDDLE)
	{
		ft_memset(output_str + *buf_index, '0', lens->pad);
		*buf_index += lens->pad;
	}
	if (parts->precised_arg)
	{
		ft_memcpy(output_str + *buf_index, parts->precised_arg, lens->precised);
		*buf_index += lens->precised;
	}
	if (lens->pad_pos == BACK)
	{
		ft_memset(output_str + *buf_index, ' ', lens->pad);
		*buf_index += lens->pad;
	}
}
