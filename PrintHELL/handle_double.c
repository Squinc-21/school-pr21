/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:15:26 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/13 19:45:17 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_double(t_printf *st)
{
	char		*s;
	long double	num;

	s = (char *)malloc(sizeof(char) * 1);
	if (st->size == 5 && (num = va_arg(st->ap, long double)))
		pf_ditoa((double)num, st);
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

char		*doub_to_int(long double num, int presicion, t_printf *st)
{
	int	i;

	i = 0;
	while (i < presicion && (int)num == 0)
	{
		num = num * 10;
		i++;
		if (num - (intmax_t)num >= 0.5)
			break ;
	}
	if (i == presicion)
		return (ft_itoa(0, i, st));
	while (i < presicion - 1)
	{
		num = num * 10;
		i++;
	}
	if (num - (intmax_t)num > 0.5)
		return (pf_uitoa((intmax_t)num + 1, st, 10));
	else if ((intmax_t)num > 0 && i < presicion)
		return (pf_uitoa((intmax_t)num, st, 10));
	return (NULL);
}

void		pf_ditoa(long double num, t_printf *st)
{
	char		*pre_dot;
	char		*post_dot;
	long double	help;
	intmax_t	a;

	a = (intmax_t)num;
	if (st->precision == -1)
		st->precision = 6;
	help = (num < 0) ? (-10) * (num - a) : 10 * (num - a);
	post_dot = doub_to_int(help, st->precision, st);
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
	if (post_dot != NULL)
		free(post_dot);
	free(pre_dot);
}

void		concatenate(char *pre_dot, char *post_dot, t_printf *st)
{
	char	*all;
	int		pu_pa;
	int		lu_pa;
	int		i;

	lu_pa = ft_strlen(pre_dot);
	pu_pa = ft_strlen(post_dot);
	i = 0;
	st->buf = (char *)malloc(sizeof(char) * (lu_pa + pu_pa + 2));
	all = (char *)malloc(sizeof(char) * (lu_pa + pu_pa + 2));
	if (st->precision != 0)
	{
		st->buf = ft_strcpy(st->buf, bug(pre_dot, post_dot, all, 0));
		free(all);
		return ;
	}
	if (st->prefix != 0)
	{
		st->buf = ft_strcpy(st->buf, bug(pre_dot, post_dot, all, 1));
		free(all);
		return ;
	}
	st->buf = ft_strcpy(st->buf, pre_dot);
	free(all);
}

char		*bug(char *pre_dot, char *post_dot, char *all, int pf)
{
	int i;
	int pu_pa;
	int lu_pa;

	lu_pa = ft_strlen(pre_dot);
	pu_pa = ft_strlen(post_dot);
	i = 0;
	while (i < lu_pa && pre_dot[i])
	{
		all[i] = pre_dot[i];
		i++;
	}
	all[i] = '.';
	if (pf == 0)
	{
		i = 0;
		while (i < pu_pa && post_dot[i])
		{
			all[i + lu_pa + 1] = post_dot[i];
			i++;
		}
		all[i + lu_pa + 1] = '\0';
	}
	return (all);
}
