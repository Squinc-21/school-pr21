/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:15:26 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/06 17:32:11 by lsedgeki         ###   ########.fr       */
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
        printf("l%sl", s); 
        st->buf = ft_strjoin(s, st->buf);
        st->buf_len = (int)ft_strlen(st->buf);
    }
    cr_output(st);
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

char *doub_to_int(long double num, int presicion, char *post_dot)
{
    int i;
    char *out;
    
    i = 0;
    while (i < presicion && num < 1.0)
        {
            num = num * 10;
            i++;
        }
    out = ft_itoa(0, i - 1); 
    while (i < presicion)
    {
        num = num * 10;
        i++;
    }
    if (num - (intmax_t)num > 0.5)
        out = ft_strjoin(out, ft_itoa((intmax_t)num + 1, len_w((intmax_t)num + 1)));
    else
       out = ft_strjoin(out, ft_itoa((intmax_t)num, len_w((intmax_t)num)));
    post_dot = out;
    return (post_dot);
}

char *pf_ditoa(long double num, t_printf *st)
{
   char *pre_dot;
   char *post_dot;
   intmax_t a;
   
   a = (intmax_t)num;
   pre_dot = ft_itoa(a, len_w(a));
   post_dot = "";
   if (st->precision == -1)
       st->precision = 6;
   post_dot = (num < 0) ? doub_to_int((-1) * (num - a), st->precision, post_dot) 
                        : doub_to_int(num - a, st->precision, post_dot);
   if(num - a >= 0.5  )
   {
       a++;
       pre_dot = ft_itoa(a, len_w(a));
       return (pre_dot);
   }
   if (st->precision != 0)
   {
   post_dot = ft_strjoin(".", post_dot);
   pre_dot = ft_strjoin(pre_dot, post_dot);
   if (num < 0 && a == 0)
       pre_dot = ft_strjoin("-", pre_dot); 
   return (pre_dot);
   }
   if (num < 0 && a == 0)
       pre_dot = ft_strjoin("-", pre_dot);
   return (pre_dot);
}