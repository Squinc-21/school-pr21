/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:56:49 by squinc            #+#    #+#             */
/*   Updated: 2019/09/16 20:50:24 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*to;
	const unsigned char	*from;

	if (dest == src)
		return ((void*)src);
	to = (unsigned char*)dest;
	from = (const unsigned char*)src;
	while (num > 0)
	{
		*(to++) = *(from++);
		--num;
	}
	return (dest);
}
