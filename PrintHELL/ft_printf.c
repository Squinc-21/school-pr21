/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:28:27 by squinc            #+#    #+#             */
/*   Updated: 2019/11/06 14:26:02 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf st;

	st.fd = 1;
	st.source = (char*)format;
	st.t_len = 0;
	va_start(st.ap, format);
	while (*st.source)
	{
		if (*st.source == '%')
		{
			++st.source;
			if (!*st.source)
				break ;
			reset_st(&st);
			ft_parse(&st);
			++st.source;
		}
		else
		{
			write(1, st.source, 1);
			st.t_len++;
			++st.source;
		}
	}
	return (st.t_len);
}
