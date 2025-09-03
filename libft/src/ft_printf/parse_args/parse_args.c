/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 05:11:00 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/01 19:56:14 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	parse_args(t_list *head, va_list ap)
{
	t_token		*token;
	char		*stash;
	t_format	*f;
	bool		arg_is_null;

	while (head)
	{
		arg_is_null = false;
		token = head->content;
		if (token->type == CONV)
		{
			f = token->format;
			if (f->width_from_arg)
				f->width = va_arg(ap, int);
			if (f->prec_from_arg)
				f->precision = va_arg(ap, int);
			stash = arg_to_spec(f, ap, &arg_is_null);
			if (!stash)
				return (false);
			token->parsed_arg = stash;
		}
		head = head->next;
	}
	return (true);
}
