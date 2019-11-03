/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:15:26 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/03 20:20:58 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void handle_double(t_printf *st)
{
    char *s;
    
    if (st->size == 5)
        st->buf = pf_ditoa(va_arg(st->ap, long double), st);
    else
        st->buf = pf_ditoa(va_arg(st->ap, double), st);
    st->buf_len = (int)ft_strlen(st->buf);
    if (st->fill_zero)
    {
        s = ft_itoa(0, (st->width - st->buf_len)); 
        st->buf = ft_strjoin(s, st->buf);
        st->buf_len = (int)ft_strlen(st->buf);
    }
    cr_output(st);
}

intmax_t doub_to_int(long double num, int presicion)
{
    intmax_t q;
    int i;
    
    q = 0;
    i = 0;
    while (i < presicion)
    {
        num = num * 10;
        i++;
    }
    if (num - (intmax_t)num > 0.5)
        q = (intmax_t)num + 1;
    else
        q = (intmax_t)num;
    return (q);
}

static int	len_w(intmax_t n)
{
	int	len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char *pf_ditoa(long double num, t_printf *st)
{
    char *pre_dot;
    char *post_dot;
    intmax_t a;
    intmax_t b;

    a = (intmax_t)num;
    if (st->precision == -1)
        st->precision = 6;
    b =  doub_to_int(num - a, st->precision);
    pre_dot = ft_itoa(a, len_w(a));
    post_dot = ft_itoa(b, len_w(b));
    post_dot = ft_strjoin(".", post_dot);
    return (ft_strjoin(pre_dot, post_dot));
}