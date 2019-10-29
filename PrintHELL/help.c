/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:44:59 by squinc            #+#    #+#             */
/*   Updated: 2019/10/29 18:35:59 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void reset_st(t_printf *st)
{
	st->fill_zero = 0;
	st->prefix = 0;
	st->width = 0;
	st->plus_sign = 0;
	st->space_sign = 0;
	st->precision = -1; //important
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int is_flag(char c)
{
	return (c == ' ' ||
			c == '+' ||
			c == '0' ||
			c == '#' ||
			c == '-');
}

int is_conv(char c)
{
	return (c == 'd' ||
			c == 'i' ||
			c == 'o' ||
			c == 'u' ||
			c == 'x' ||
			c == 'X' ||
			c == 'f');
}

int is_len_fl(char c)
{
	return (c == 'l' ||
			c == 'll' ||
			c == 'L' ||
			c == 'h' ||
			c == 'hh');
}