/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hande_sym.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:53:10 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/06 17:52:20 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *handle_sym(t_printf *st)
{
   char q;
   char *help;
   st->buf = (char *)malloc(sizeof(char) * 1);
   if (*st->source == 'c')
   {
       q = (char)va_arg(st->ap, int);
       st->buf[0] = q;
       st->buf_len = 1;
       cr_output(st);
       return(st->buf);
   }
   else if (*st->source == 's')
       if((st->buf = ft_strcpy(st->buf, va_arg(st->ap, char *))) == NULL)
           st->buf = "(null)";
   st->buf_len = ft_strlen(st->buf);
   if (st->buf_len > st->precision && st->precision >= 0)
       {
           help = ft_strnew(st->precision);
           help = ft_strncpy(help, st->buf, st->precision);
           st->buf = help;
       }
   st->buf_len = ft_strlen(st->buf);
   cr_output(st);
   return ("a");
}