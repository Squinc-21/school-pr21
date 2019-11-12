/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:07:45 by squinc            #+#    #+#             */
/*   Updated: 2019/11/09 19:17:13 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		define_conv(t_printf *st)
{
	if (*st->source == 'd' || *st->source == 'i')
		cr_int(st);
	if (*st->source == 'u' || *st->source == 'o'
			|| *st->source == 'x' || *st->source == 'X' || *st->source == 'p')
		cr_unsigned(st);
	if (*st->source == 'f' || *st->source == 'F')
		handle_double(st);
	if (*st->source == 'c' || *st->source == 's')
		handle_sym(st);
}

void		cr_unsigned(t_printf *st)
{
	int base;

	if (*st->source == 'p')
	{
		st->size = 4;
		st->prefix = 1;
	}
	base = (*st->source == 'x' || *st->source == 'X'
			|| *st->source == 'p') ? 16 : 0;
	base = (*st->source == 'o') ? 8 : base;
	base = (*st->source == 'u') ? 10 : base;
	if (st->size == 1)
		st->buf =
			pf_uitoa((unsigned char)va_arg(st->ap, unsigned int), st, base);
	else if (st->size == 2)
		st->buf =
			pf_uitoa((unsigned short int)va_arg(st->ap, unsigned int), st, base);
	else if (st->size == 3)
		st->buf = pf_uitoa(va_arg(st->ap, unsigned long int), st, base);
	else if (st->size == 4)
		st->buf = pf_uitoa(va_arg(st->ap, unsigned long long int), st, base);
	else
		st->buf = pf_uitoa(va_arg(st->ap, unsigned int), st, base);
	cr_output(st);
}

void		cr_int(t_printf *st)
{
	if (st->size == 1)
		st->buf = pf_itoa((signed char)va_arg(st->ap, int), st);
	else if (st->size == 2)
		st->buf = pf_itoa((short int)va_arg(st->ap, int), st);
	else if (st->size == 3)
		st->buf = pf_itoa(va_arg(st->ap, long int), st);
	else if (st->size == 4)
		st->buf = pf_itoa(va_arg(st->ap, long long int), st);
	else
		st->buf = pf_itoa(va_arg(st->ap, int), st);
	if (st->buf)
		st->plus_sign = (st->buf[0] == '-') ? 0 : st->plus_sign;
	cr_output(st);
}

void			print_cycle(int sp, int zero, char c)
{
	if (c == ' ')
	{
		while (sp > 0)
		{
			write(1, &c, 1);
			sp--;
		}
	}
	else
	{
		while (zero > 0)
		{
			write(1, &c, 1);
			zero--;
		}
	}
}

int				form_pref(t_printf *st, int sp)
{
	if (*st->source == 'o')
	{
        if (!st->width || (st->buf && st->width >= st->buf_len && st->buf[0] != '0') || (st->precision >= st->buf_len))
        {
            write(1, "0", 1);
            st->t_len++;
        }
        sp--;
	}
	if (*st->source == 'x' || *st->source == 'p')
	{
		write(1, "0x", 2);
		st->t_len += 2;
		sp -= 2;
	}
	if (*st->source == 'X')
	{
		write(1, "0X", 2);
		st->t_len += 2;
		sp -= 2;
	}
	return (sp);
}
