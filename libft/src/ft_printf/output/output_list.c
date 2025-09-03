/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 05:07:17 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/01 19:57:28 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	output_token_conv(t_token *token, bool *fmt_err_flag)
{
	char	*out_str;
	int		out_len;

	if (token->format->spec == 0)
		*fmt_err_flag = true;
	out_str = apply_format(token, token->format);
	if (!out_str)
		return (-1);
	out_len = output_token((const char *)out_str, token->lens->total,
			token->format->spec);
	free(out_str);
	return (out_len);
}

static int	output_token_txt(t_token *token)
{
	return (write(1, token->block, ft_strlen(token->block)));
}

int	output_list(t_list *node)
{
	t_token	*token;
	int		out_len;
	int		total_len;
	bool	fmt_err_flag;

	total_len = 0;
	fmt_err_flag = false;
	while (node)
	{
		token = (t_token *)node->content;
		if (token->type == TXT)
			out_len = output_token_txt(token);
		else if (token->type == CONV && token->format)
			out_len = output_token_conv(token, &fmt_err_flag);
		if (out_len < 0)
			return (-1);
		total_len += out_len;
		node = node->next;
	}
	if (fmt_err_flag)
		return (-1);
	return (total_len);
}
