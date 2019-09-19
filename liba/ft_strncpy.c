/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:46:18 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:31:03 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (src[i] && n > (unsigned int)i)
	{
		dest[i] = src[i];
		++i;
	}
	while (n > i)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}
