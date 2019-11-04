/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:44:59 by squinc            #+#    #+#             */
/*   Updated: 2019/11/04 22:32:02 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void reset_st(t_printf *st)
{
	//free(st->buf);
	st->fill_zero = 0;
	st->prefix = 0;
	st->width = 0;
	st->l_align = 0;
	st->plus_sign = 0;
	st->space_sign = 0;
	st->size = 0;
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
            c == 'c' ||
            c == 's' ||
            c == 'p' ||
            c == 'f');
}

int is_len_fl(char *c)
{
	if (ft_strncmp(c, "ll", 2) == 0)
		return (0);
	if (ft_strncmp(c, "l", 1) == 0)
		return(0);
	if (!ft_strncmp(c, "h", 1))
		return(0);
	if (!ft_strncmp(c, "hh", 2))
		return(0);
	if (!ft_strncmp(c, "L", 1))
		return(0);
	return(1);
}