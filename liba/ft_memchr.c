/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:01:46 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 17:18:30 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const char	*ptr;

	ptr = (const char*)arr;
	while (n > 0)
	{
		if ((*ptr) == (char)c)
			return ((void*)ptr);
		++ptr;
		--n;
	}
	return (0);
}
