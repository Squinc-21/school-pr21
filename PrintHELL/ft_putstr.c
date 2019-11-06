/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:58:39 by squinc            #+#    #+#             */
/*   Updated: 2019/11/06 17:36:03 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s, size_t len)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (i < len)
			ft_putchar(s[i++]);
	}
}
