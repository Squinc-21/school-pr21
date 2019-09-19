/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:58:38 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 17:19:26 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	unsigned char		*to;
	const unsigned char *from;

	to = (unsigned char*)dest;
	from = (const unsigned char*)src;
	while (num > 0)
	{
		*to = *from;
		if (*from == (unsigned char)c)
			return ((void *)(to + 1));
		++to;
		++from;
		--num;
	}
	return (0);
}
