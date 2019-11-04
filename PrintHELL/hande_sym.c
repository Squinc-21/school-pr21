/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hande_sym.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:53:10 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/04 19:55:54 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void handle_sym(t_printf *st)
{
    char q;
    char *help;
    
    if (*st->source == 'c')
    {
       q = (char)va_arg(st->ap, int);
       st->buf = (char *)malloc(sizeof(char) * 1);
       *st->buf = q;
    }
    else if (*st->source == 's')
        st->buf = ft_strcpy(st->buf, va_arg(st->ap, char *));
    st->buf_len = ft_strlen(st->buf);
    if (st->buf_len > st->precision)
        {
            help = ft_strnew(st->precision);
            help = ft_strncpy(help, st->buf, st->precision);
            st->buf = help;
        }
    st->buf_len = ft_strlen(st->buf);
    cr_output(st);
}