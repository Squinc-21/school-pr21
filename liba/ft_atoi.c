/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:39:04 by squinc            #+#    #+#             */
/*   Updated: 2019/09/16 22:18:52 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int          check_tab(char c)
{
	return (c == '\n' || c == '\t' || c == ' '
			|| c == '\v' || c == '\f' || c == '\r');
}
static long int     make_int(const char *str, long long q, int i, int neg)
{
	while (str[i] >= '0' && (str[i] <= '9'))
	{
		q = q * 10 + (str[i] - '0');
		i++;
	}
	if (i >= 19)
		return (neg == -1 ? 0 : -1);
	if (q > 9223372036854775807)
		return (neg == -1 ? 0 : -1);
	else
		return (q * neg);
	return (q);
}
int                 ft_atoi(const char *str)
{
	long long   q;
	int         i;
	int         neg;
	q = 0;
	i = 0;
	while (check_tab(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = str[i] == '-' ? -1 : 1;
		i++;
		q = make_int(str, q, i, neg);
	}
	else
		q = make_int(str, q, i, 1);
	return (q);
}
