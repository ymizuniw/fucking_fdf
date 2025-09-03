/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:57:11 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/09/01 19:56:14 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_d_i(t_format *f, va_list ap)
{
	int	arg;

	arg = va_arg(ap, int);
	if (arg == 0 && f->precision_on && f->precision == 0)
		return (ft_strdup(""));
	if (arg < 0)
		f->is_negative = true;
	return (ft_itoa_abs(arg));
}

static char	*parse_u_x(t_format *f, va_list ap)
{
	unsigned int	uarg;
	unsigned int	xarg;

	if (f->spec == 'u')
	{
		uarg = va_arg(ap, unsigned int);
		if (uarg == 0 && f->precision_on && f->precision == 0)
			return (ft_strdup(""));
		return (ft_utoa(uarg));
	}
	else
	{
		xarg = va_arg(ap, unsigned int);
		if (xarg == 0 && f->precision_on && f->precision == 0)
			return (ft_strdup(""));
		return (ft_xtoa(xarg, ft_is_upper(f->spec)));
	}
}

static char	*parse_s(t_format *f, va_list ap, bool *arg_is_null)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		*arg_is_null = true;
		if ((f->precision_on && f->precision < 6))
			return (ft_strdup(""));
		else
			return (ft_strdup("(null)"));
	}
	else if (f->precision_on)
		return (ft_strndup(str, f->precision));
	return (ft_strdup(str));
}

static char	*parse_p(t_format *f, va_list ap)
{
	void	*ptr;

	f->flag_hash = false;
	ptr = va_arg(ap, void *);
	if (ptr)
		return (ft_ptoa(ptr));
	else
		return (ft_strndup("(nil)", 5));
	return (NULL);
}

char	*arg_to_spec(t_format *f, va_list ap, bool *arg_is_null)
{
	if (!f)
		return (NULL);
	if (f->spec == 'd' || f->spec == 'i')
		return (parse_d_i(f, ap));
	if (f->spec == 'u' || f->spec == 'x' || f->spec == 'X')
		return (parse_u_x(f, ap));
	if (f->spec == 'c')
		return (ft_ctoa(va_arg(ap, int)));
	if (f->spec == 's')
		return (parse_s(f, ap, arg_is_null));
	if (f->spec == 'p')
		return (parse_p(f, ap));
	if (f->spec == '%')
		return (ft_strdup("%"));
	if (f->spec == 0)
		return (ft_strdup(""));
	return (NULL);
}
