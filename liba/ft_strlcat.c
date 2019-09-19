/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:03:54 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:42:12 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;

	res = 0;
	while (*dst != '\0')
	{
		if (size > 0)
		{
			++res;
			--size;
		}
		++dst;
	}
	while (*src != '\0')
	{
		if (size > 1)
		{
			*dst = *src;
			++dst;
			--size;
		}
		++src;
		++res;
	}
	*dst = '\0';
	return (res);
}
