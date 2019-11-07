/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:49:51 by squinc            #+#    #+#             */
/*   Updated: 2019/11/07 19:04:19 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_abs(intmax_t n)
{
	return ((n < 0) ? -n : n);
}

static int	len_w(intmax_t n)
{
	int	len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static int	len_uw(uintmax_t n, int base)
{
	int	len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		++len;
	}
	return (len);
}

char				*ft_itoa(intmax_t n, int len)
{
	char	*c;
	int		sign;

	sign = (n < 0) ? 1 : 0;
	c = (char*)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (NULL);
	c[len] = '\0';
	--len;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		--len;
	}
	if (sign == 1)
		c[0] = '-';
	return (c);
}

char		*ft_uitoa(uintmax_t n, int len, int base, t_printf *st)
{
	char	*hex;
	char	*hexb;

	hex = "0123456789abcdef";
	hexb = "0123456789ABCDEF";
	st->prefix = (n == 0 && *st->source != 'p') ? 0 : st->prefix;
	if (*st->source == 'X')
		hex = hexb;
	st->buf = (char*)malloc(sizeof(char) * len + 1);
	if (st->buf == NULL)
		return (NULL);
	st->buf[len] = '\0';
	--len;
	while (len >= 0)
	{
		st->buf[len] = hex[n % base];
		n = n / base;
		--len;
	}
	return (st->buf);
}

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
	len -= (st->plus_sign && st->fill_zero &&
					len == st->width && n >= 0) ? 1 : 0;
	len += (n < 0 && len == st->precision) ? 1 : 0;
	st->space_sign = (n < 0) ? 0 : st->space_sign;
	st->buf_len = len;
	return (ft_itoa(n, len));
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
	st->buf_len = len;
	if (st->prefix)
	{
		if (*st->source == 'o' && (len < st->precision \
			|| len != st->precision) && len != len_uw(n, base))
			len--;
		else if (n > 0 && len <= st->width && (len < st->precision \
			|| len != st->precision) && len != len_uw(n, base))
			len -= 2;
		st->buf_len = len;
	}
	return (ft_uitoa(n, len, base, st));
}
