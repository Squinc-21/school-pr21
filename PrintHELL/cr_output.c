/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:40:17 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/13 18:17:41 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cr_output(t_printf *st)
{
	int sp;
	int zero;

	sp = 0;
	zero = 0;
	if (st->space_sign && !st->plus_sign && ft_atoi(st->buf) >= 0)
		sp = 1;
	if (st->width > st->buf_len)
		sp = st->width - st->buf_len;
	if (st->fill_zero && st->precision < 0 && !st->l_align)
		zero = sp;
	flags_for_output(sp, zero, st);
}

void	flags_for_output(int sp, int zero, t_printf *st)
{
	if (st->plus_sign && (*st->source == 'd' || *st->source == 'i'))
	{
		sp = (sp > 0) ? sp - 1 : 0;
		zero = (zero > 0) ? zero - 1 : 0;
	}
	if (st->prefix)
	{
		if (st->width > st->buf_len)
			st->t_len += (*st->source == 'o') ? st->width - 1 : st->width - 2;
		else if (!(st->width > st->buf_len) && st->width != 0)
			st->t_len += (*st->source == 'o') ? st->buf_len - 1 :
				st->buf_len - 2;
		else if (!(st->width > st->buf_len) && st->width == 0)
			st->t_len += st->buf_len;
	}
	else
	{
		if (st->width > st->buf_len)
			st->t_len += st->width;
		else
			st->t_len += st->buf_len;
	}
	print_str(st, sp, zero);
	if (st->buf != NULL && *st->source != 's')
		free(st->buf);
}
