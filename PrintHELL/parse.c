/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:07:45 by squinc            #+#    #+#             */
/*   Updated: 2019/10/29 18:57:10 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_printf *st)
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

void	parse_length_flags(t_printf *st)
{
	if (*st->source == 'h' && *(st + 1)->source == 'h')
	{
		st->size = 1;
		st->source++;
	}
	else if (*st->source == 'l' && *(st + 1)->source == 'l')
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
	return (st);
}

void	ft_parse(t_printf *st, char *buf)
{
	while (!is_conv(*st->source))
	{
		if (*st->source == '%')
		{	
			buf = '%';
			buf++;		
			return  ;
		}
		else if (is_flag(*st->source))
			parse_flags(st);
		else if (is_digit(*st->source))
		{
			st->width = ft_atoi(*st->source);
			while(is_digit(*st->source))
				st->source++;
		}
		else if (*st->source == '.')
		{
			if (is_digit(++st->source))
				{
					st->precision = ft_atoi(*st->source);
					while(is_digit(*st->source))
						st->source++;
				}
			else
				st->precision = 0;
		}
		else if (is_len_fl(*st->source))
			parse_length_flags(st);
		st->source++;	
	}
	//обращение к va_arg s uchetom length_flag	
}

void		int_to_buf(t_printf *st)
{
	int a;

	a = va_arg(st->ap, int);
	ft_putnbr(a);
}