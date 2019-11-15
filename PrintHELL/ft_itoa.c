/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:49:51 by squinc            #+#    #+#             */
/*   Updated: 2019/11/13 19:35:46 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		ft_abs(intmax_t n)
{
	return ((n < 0) ? -n : n);
}

int					len_w(intmax_t n)
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

int					len_uw(uintmax_t n, int base)
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

char				*ft_itoa(intmax_t n, int len, t_printf *st)
{
	int		sign;

	sign = (n < 0) ? 1 : 0;
	st->buf = (char*)malloc(sizeof(char) * len + 1);
	if (st->buf == NULL)
		return (NULL);
	st->buf[len] = '\0';
	--len;
	while (len >= 0)
	{
		st->buf[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		--len;
	}
	if (sign == 1)
		st->buf[0] = '-';
	return (st->buf);
}

char				*ft_uitoa(uintmax_t n, int len, int base, t_printf *st)
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
