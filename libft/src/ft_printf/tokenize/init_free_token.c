/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:06:57 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_token	*initialize_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->format = NULL;
	token->block = NULL;
	token->parsed_arg = NULL;
	token->lens = NULL;
	token->format = malloc(sizeof(t_format));
	if (!token->format)
		return (NULL);
	token->type = CONV;
	initialize_format(token->format);
	return (token);
}

void	initialize_format(t_format *f)
{
	f->flag_minus = false;
	f->flag_zero = false;
	f->flag_hash = false;
	f->flag_plus = false;
	f->flag_space = false;
	f->width = 0;
	f->width_from_arg = false;
	f->precision = 0;
	f->prec_from_arg = false;
	f->precision_on = false;
	f->is_negative = false;
	f->spec = 0;
}

void	free_token(void *tk_ptr)
{
	t_token	*token;

	token = tk_ptr;
	if (!token)
		return ;
	if (token->block)
		free(token->block);
	if (token->parsed_arg)
		free(token->parsed_arg);
	if (token->lens)
		free(token->lens);
	if (token->format)
		free(token->format);
	if (token)
		free(token);
}
