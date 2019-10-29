/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:28:27 by squinc            #+#    #+#             */
/*   Updated: 2019/10/29 18:20:06 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf st;

	st.fd = 1;
	st.source = (char*)format;
	va_start(st.ap, format);
	while (*st.source)
	{
		if (*st.source == "%")
		{
			++st.source;
			if (!*st.source)
				break ;
			ft_parse(&st, st.buf);
		}
		else
			to_buf(&st);
		++st.source;
	}
	st.t_len = 0;
	return (st.t_len);
}
