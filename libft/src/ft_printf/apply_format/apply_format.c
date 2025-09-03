/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:35 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:27:29 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	set_lens(t_lens *lens, t_token *token, t_format *f,
				t_parts_out *parts);
static char	*apply_precision(t_format *f, char *arg, t_lens *lens);
static void	initialize_len_and_parts(t_lens *lens, t_parts_out *parts);

char	*apply_format(t_token *token, t_format *f)
{
	t_parts_out	parts;
	t_lens		lens;
	char		*output_str;

	token->lens = malloc(sizeof(t_lens));
	if (!token->lens)
		return (NULL);
	initialize_len_and_parts(&lens, &parts);
	set_lens(&lens, token, f, &parts);
	parts.precised_arg = apply_precision(f, token->parsed_arg, &lens);
	if (!parts.precised_arg)
		return (NULL);
	output_str = malloc(lens.total + lens.pad + 1);
	if (!output_str)
		return (free(parts.precised_arg), NULL);
	set_output_str(output_str, &parts, &lens);
	free(parts.precised_arg);
	*(token->lens) = lens;
	return (output_str);
}

static void	initialize_len_and_parts(t_lens *lens, t_parts_out *parts)
{
	lens->prefix = 0;
	lens->sign = 0;
	lens->arg = 0;
	lens->precised = lens->arg;
	lens->total = 0;
	lens->pad = 0;
	parts->prefix_len = 0;
	parts->sign_len = 0;
	parts->prec_len = lens->arg;
	parts->pad_len = 0;
}

static bool	set_lens(t_lens *lens, t_token *token, t_format *f,
		t_parts_out *parts)
{
	lens->prefix = set_count_prefix(f, parts->prefix, token->parsed_arg);
	lens->sign = set_count_sign(f, parts->sign);
	if (f->spec == 'c' && token->parsed_arg[0] == '\0')
	{
		lens->arg = 1;
		lens->precised = 1;
	}
	else
		lens->arg = ft_strlen((const char *)token->parsed_arg);
	lens->precised = set_count_precision(f, lens->arg);
	lens->total = lens->prefix + lens->sign + lens->precised;
	lens->pad = set_count_pad(f, lens);
	parts->prefix_len = lens->prefix;
	parts->sign_len = lens->sign;
	parts->prec_len = lens->precised;
	parts->pad_len = lens->pad;
	return (true);
}

static char	*apply_precision(t_format *f, char *arg, t_lens *lens)
{
	char	*res;
	int		num_zeros;
	size_t	len;

	if (f->spec == 's')
	{
		len = ft_strlen(arg);
		if (f->precision_on && len > f->precision)
			return (ft_strndup((const char *)arg, f->precision));
		else if (f->precision_on && len <= f->precision)
			return (ft_strndup((const char *)arg, len));
		return (ft_strdup((const char *)arg));
	}
	else
	{
		num_zeros = lens->precised - lens->arg;
		res = malloc(lens->precised + 1);
		if (!res)
			return (NULL);
		ft_memset(res, '0', num_zeros);
		ft_strlcpy(res + num_zeros, arg, lens->arg + 1);
		res[lens->precised] = '\0';
		return (res);
	}
}
