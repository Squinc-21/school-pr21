/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:28:27 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/11 21:55:06 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_printf *st)
{
	if (*st->source == '-')
		st->l_align = 1;
	if (*st->source == '0')
		st->fill_zero = 1;
	if (*st->source == '+')
		st->plus_sign = 1;
	if (*st->source == ' ')
		st->space_sign = 1;
	if (*st->source == '#')
		st->prefix = 1;
}

static void	parse_length_flags(t_printf *st)
{
	if (*st->source == 'h' && *(st->source + 1) == 'h')
	{
		st->size = 1;
		st->source++;
	}
	else if (*st->source == 'l' && *(st->source + 1) == 'l')
	{
		st->size = 4;
		st->source++;
	}
	else if (*st->source == 'h' || *st->source == 'l' || *st->source == 'L')
	{
		st->size = (*st->source == 'h') ? 2 : st->size;
		st->size = (*st->source == 'l') ? 3 : st->size;
		st->size = (*st->source == 'L') ? 5 : st->size;
	}
}

void		ft_parse(t_printf *st)
{
	while (!is_conv(*st->source))
	{
		if (*st->source == '%')
		{
			handle_percent(st);
			return ;
		}
		else if (is_flag(*st->source))
			parse_flags(st);
		else if (is_digit(*st->source))
		{
			st->width = ft_atoi(st->source);
			while (is_digit(*st->source))
				st->source++;
			st->source--;
		}
		else if (*st->source == '.')
			handle_presicion(st);
		else if (is_len_fl(st->source) == 0)
			parse_length_flags(st);
		st->source++;
	}
	define_conv(st);
}

void		handle_presicion(t_printf *st)
{
	if (is_digit(*(st->source + 1)))
	{
		st->precision = ft_atoi(++st->source);
		while (is_digit(*st->source))
			st->source++;
		st->source--;
	}
	else
		st->precision = 0;
}

void		handle_percent(t_printf *st)
{
	char *s;

	s = (char *)malloc(sizeof(char) * 1);
	st->buf = (char *)malloc(sizeof(char) * 1);
	*st->buf = '%';
	st->space_sign = 0;
	if (st->fill_zero && st->width != 0 && !st->l_align)
	{
		s = ft_memset(s, '0', st->width - 1);
		st->buf = ft_stj(s, st->buf);
	}
	st->buf_len = ft_strlen(st->buf);
	cr_output(st);
}
