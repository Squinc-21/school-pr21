/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:15:01 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/09 18:02:42 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_printf *st, int sp, int zero)
{
	if (st->plus_sign && (*st->source == 'd' || *st->source == 'i'))
		plus_d_i(sp, zero, st);
	else if (st->l_align && !st->prefix)
	{
		if (st->space_sign)
		{
			st->t_len += (!st->width) ? 1 : 0;
			write(1, " ", 1);
			sp--;
		}
		ft_putstr(st->buf, st->buf_len);
		print_cycle(sp, zero, ' ');
	}
	else if (!st->prefix)
		non_prefix(sp, zero, st);
	else
		left_align(sp, zero, st);
}

void	plus_d_i(int sp, int zero, t_printf *st)
{
	if (!st->l_align && zero <= 0)
	{
		print_cycle(sp, zero, ' ');
		write(1, "+", 1);
	}
	else if (zero >= 0 || st->l_align)
	{
		write(1, "+", 1);
		print_cycle(sp, zero - 1, '0');
	}
	st->t_len += (st->plus_sign && !st->width) ? 1 : 0;
	ft_putstr(st->buf, st->buf_len);
	if (st->width > st->buf_len && st->l_align)
		print_cycle(st->width - st->buf_len - 1, zero, ' ');
}

void	non_prefix(int sp, int zero, t_printf *st)
{
	if (sp == 0 && st->space_sign)
	{
		write(1, " ", 1);
		st->t_len += (!st->width) ? 1 : 0;
	}
	else if (sp > 0)
		print_cycle(sp, zero, ' ');
	else if (zero > 0)
		print_cycle(sp, zero, '0');
	ft_putstr(st->buf, st->buf_len);
}

void	left_align(int sp, int zero, t_printf *st)
{
	if (st->l_align)
	{
		sp = form_pref(st, sp);
		ft_putstr(st->buf, st->buf_len);
		print_cycle(sp, zero, ' ');
	}
	else
	{
		if (st->fill_zero && st->buf_len + 1 < st->precision)
		{
			zero = form_pref(st, zero);
			print_cycle(sp, zero, '0');
		}
		else
		{
			if (*st->source == 'o')
				print_cycle(sp - 1, zero, ' ');
			else
				print_cycle(sp - 2, zero, ' ');
			form_pref(st, sp);
		}
		if (!(*st->source == 'p' && st->precision == 0))
			ft_putstr(st->buf, st->buf_len);
	}
}
