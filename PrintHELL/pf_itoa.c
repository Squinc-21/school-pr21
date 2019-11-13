/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:50:26 by squinc            #+#    #+#             */
/*   Updated: 2019/11/12 20:09:40 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_itoa(intmax_t n, t_printf *st)
{
	int	len;

	len = len_w(n);
	if (!st->precision && !n)
	{
		st->prefix = 0;
		return (NULL);
	}
	if (n < 0 && len == st->precision)
		len++;
	len = handle_len(st, n, len);
	len -= (st->plus_sign && st->fill_zero &&
					len == st->width && n >= 0) ? 1 : 0;
	len += (n < 0 && len == st->precision) ? 1 : 0;
	st->space_sign = (n < 0) ? 0 : st->space_sign;
	st->buf_len = len;
	return (ft_itoa(n, len, st));
}

char		*pf_uitoa(uintmax_t n, t_printf *st, int base)
{
	int	len;

	if (!st->precision && !n && *st->source != 'p')
	{
		if (base != 8)
			st->prefix = 0;
		return (NULL);
	}
	len = len_uw(n, base);
	len = handle_ulen(st, n, len, base);
	st->buf_len = len;
	if (st->prefix)
	{
		if (*st->source == 'o' && st->precision >= 0 && \
				len_uw(n, base) < st->precision && n > 0)
			len--;
		else if (!(*st->source == 'o') && n > 0 &&
				len <= st->width && (len < st->precision \
			|| len != st->precision) && len != len_uw(n, base))
			len -= 2;
		st->buf_len = len;
	}
	return (ft_uitoa(n, len, base, st));
}

int			handle_len(t_printf *st, intmax_t n, int len)
{
	if (len < st->precision)
		len = st->precision;
	if (!st->l_align && st->fill_zero && st->width > len)
	{
		if (st->precision >= len)
			len = st->precision;
		else if (st->precision < 0)
			len = (st->space_sign && n >= 0) ? st->width - 1 : st->width;
		else
			len = len_w(n);
	}
	return (len);
}

int			handle_ulen(t_printf *st, uintmax_t n, int len, int base)
{
	if (len < st->precision)
		len = st->precision;
	if (!st->l_align && st->fill_zero && st->width > len)
	{
		if (st->precision >= len)
			len = st->precision;
		else if (st->precision < 0)
			len = st->width;
		else
			len = len_uw(n, base);
	}
	else if (len >= st->width)
		st->width = len;
	return (len);
}
