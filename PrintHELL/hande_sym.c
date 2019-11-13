/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hande_sym.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:53:10 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/13 18:26:59 by squinc           ###   ########.fr       */
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
		if (help == NULL)
			st->buf = ft_strcpy(st->buf, "(null)");
		else
			st->buf = ft_strcpy(st->buf, help);
	}
	st->buf_len = ft_strlen(st->buf);
	make_correct_output_s(st);
	return ("a");
}

void	make_correct_output_s(t_printf *st)
{
	char *help;

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
