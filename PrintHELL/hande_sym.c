/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hande_sym.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:53:10 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/13 19:45:55 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_sym(t_printf *st)
{
	char q;
	char *help;

	help = "";
	if (*st->source == 'c')
	{
		q = (char)va_arg(st->ap, int);
		if (q == 0)
			st->space_sign = 0;
		st->buf = (char *)malloc(sizeof(char) * 1);
		st->buf[0] = q;
		st->buf_len = 1;
		cr_output(st);
		return ("a");
	}
	else if (*st->source == 's')
	{
		st->buf = (char *)malloc(sizeof(char) * 6);
		help = ft_strcpy(st->buf, va_arg(st->ap, char *));
		st->buf = (help == NULL) ? ft_strcpy(st->buf, "(null)") :
			ft_strcpy(st->buf, help);
	}
	make_correct_output_s(st);
	return ("a");
}

void	make_correct_output_d(long double num, t_printf *st)
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

void	make_correct_output_s(t_printf *st)
{
	char *help;

	st->buf_len = ft_strlen(st->buf);
	if (st->buf_len > st->precision && st->precision >= 0)
	{
		help = ft_strnew(st->precision);
		help = ft_strncpy(help, st->buf, st->precision);
		st->buf = ft_strcpy(st->buf, help);
		free(help);
	}
	st->buf_len = ft_strlen(st->buf);
	cr_output(st);
	if (st->buf)
		free(st->buf);
}
