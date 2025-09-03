/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:44:16 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/07/23 06:24:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_list	*head;
	int		len;
	va_list	ap;

	va_start(ap, format);
	head = tokenize_format(format);
	if (!head)
	{
		va_end(ap);
		return (-1);
	}
	if (!parse_args(head, ap))
	{
		va_end(ap);
		return (-1);
	}
	len = output_list(head);
	ft_lstclear(&head, free_token);
	va_end(ap);
	if (len < 0)
		return (-1);
	return (len);
}
