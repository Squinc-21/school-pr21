/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:15:26 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/11 22:22:02 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_double(t_printf *st)
{
	char		*s;
	long double	num;

	s = (char *)malloc(sizeof(char) * 1);
	if (st->size == 5)
	{
		num = va_arg(st->ap, long double);
		pf_ditoa((double)num, st);
	}
	else
	{
		num = va_arg(st->ap, double);
		pf_ditoa((double)num, st);
	}
	st->buf_len = (int)ft_strlen(st->buf);
	if (st->fill_zero && st->buf_len < st->width && !st->l_align)
	{
		if (num < 0 || st->plus_sign || st->space_sign)
			s = ft_memset(s, '0', st->width - st->buf_len - 1);
		else
			s = ft_memset(s, '0', st->width - st->buf_len);
		st->buf = ft_stj(s, st->buf);
		st->buf_len = (int)ft_strlen(st->buf);
	}
	free(s);
	make_correct_output_d(num, st);
}

void		make_correct_output_d(long double num, t_printf *st)
{
	if (st->plus_sign)
	{
		st->buf = (num < 0) ? ft_stj("-", st->buf) : ft_stj("+", st->buf);
		st->buf_len++;
	}
	if (num < 0 && !st->plus_sign)
	{
		st->buf = ft_stj("-", st->buf);
		st->buf_len = (int)ft_strlen(st->buf);
	}
	if (num < 0 && st->space_sign)
		st->space_sign = 0;
	if (st->prefix && st->l_align && st->space_sign)
		st->prefix = 0;
	if (st->space_sign && st->plus_sign)
		st->space_sign = 0;
	cr_output(st);
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

char		*doub_to_int(long double num, int presicion, t_printf *st, char *post)
{
	int		i;
	char	*out;
	char	*itoa;

	i = 0;
	out = (char *)malloc(sizeof(char) * 1);
	itoa = "";
	while (i < presicion && (int)num == 0)
	{
		num = num * 10;
		out = ft_stj(out, "0");
		i++;
		if (num - (intmax_t)num >= 0.5)
			break ;
	}
	if (i == presicion)
	{
		post = ft_strcpy(post, out);
		if (out)
			free(out);
		return (post);
	}
	while (i < presicion - 1)
	{
		num = num * 10;
		i++;
	}
	if (num - (intmax_t)num > 0.5)
	{
		itoa = ft_itoa((intmax_t)num + 1, len_w((intmax_t)num + 1), st);
		out = ft_stj(out, itoa);
	}
	else if ((intmax_t)num > 0 && i < presicion)
	{
		itoa = ft_itoa((intmax_t)num, len_w((intmax_t)num), st);
		out = ft_stj(out, itoa);
	}
	post = ft_strcpy(post, out);
	free(out);
	free(itoa);
	return (post);
}

void pf_ditoa(long double num, t_printf *st)
{
	char		*pre_dot;
	char		*post_dot;
	intmax_t	a;

	a = (intmax_t)num;
	post_dot = (char *)malloc(sizeof(char) * 1);
	if (st->precision == -1)
		st->precision = 6;
	post_dot = (num < 0) ? doub_to_int((-10) * (num - a), st->precision, st, post_dot)
		: doub_to_int(10 * (num - a), st->precision, st, post_dot);
	if ((int)ft_strlen(post_dot) > st->precision)
	{
		post_dot = ft_itoa(0, st->precision, st);
		a = (num < 0) ? a - 1 : a + 1;
	}
	if (num - a > 0.5 && st->precision == 0 && num > 0)
		pre_dot = ft_itoa(a + 1, len_w(a + 1), st);
	else if (num - a < -0.5 && st->precision == 0 && num < 0)
		pre_dot = ft_itoa(ABS(a + 1), len_w(ABS(a + 1)), st);
	else
		pre_dot = ft_itoa(ABS(a), len_w(ABS(a)), st);
	concatenate(pre_dot, post_dot, st);
	free(post_dot);
	free(pre_dot);
}

void concatenate(char *pre_dot, char *post_dot, t_printf *st)
{
	char *pe_d;
	char *po_d;
	
	st->buf = (char *)malloc(sizeof(char) * 1);
	pe_d = (char *)malloc(sizeof(char) * 1);
	po_d = (char *)malloc(sizeof(char) * 1);
	if (st->precision != 0)
	{
		po_d = ft_stj(".", post_dot);
		pe_d = ft_stj(pre_dot, po_d);
		st->buf = ft_strcpy(st->buf, pe_d);
		free(pe_d);
		free(po_d);
		return ;
	}
	if (st->prefix != 0)
	{
		pe_d = ft_stj(pre_dot, ".");
		st->buf = ft_strcpy(st->buf, pe_d);
		free(pe_d);
		free(po_d);
		return ;
	}
	st->buf = ft_strcpy(st->buf, pre_dot);
	free(pe_d);
	free(po_d);
}
