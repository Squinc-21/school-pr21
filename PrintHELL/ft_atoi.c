/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:07:17 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/04 19:25:14 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int				check_tab(char c)
{
	return (c == '\n' || c == '\t' || c == ' '
			|| c == '\v' || c == '\f' || c == '\r');
}

int						ft_atoi(char *str)
{
	long int	q;
	int			i;
	int			n;

	q = 0;
	i = 0;
	n = 1;
	
	while (check_tab(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i += 1;
		n = (str[i - 1] == '-') ? n * (-1) : n;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		q = q * 10 + (str[i] - '0');
		if (q < 0 && n == 1)
			return (-1);
		if (q < 0 && n == -1)
			return (0);
		i = i + 1;
	}
	return (q * n);
}
