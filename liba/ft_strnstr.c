/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:52:03 by squinc            #+#    #+#             */
/*   Updated: 2019/09/16 22:00:32 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	if (!(to_find[0]))
		return ((char*)str);
	i = 1;
	while (*str && ft_strlen(to_find) <= len &&
			(i = (size_t)ft_strncmp(str, to_find, ft_strlen(to_find))))
	{
		++str;
		--len;
	}
	if (i)
		return (NULL);
	return ((char*)str);
}
