/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:21:33 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 17:17:36 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	const unsigned char *st1;
	const unsigned char *st2;

	st1 = (const unsigned char*)arr1;
	st2 = (const unsigned char*)arr2;
	while (n > 0)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		else
		{
			++st1;
			++st2;
		}
		--n;
	}
	return (0);
}
