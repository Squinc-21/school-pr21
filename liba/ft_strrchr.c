/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:04:06 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:22:56 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*ptr;

	ptr = NULL;
	while (*str != '\0')
	{
		if (*str == ch)
			ptr = (char*)str;
		++str;
	}
	if (ch == '\0')
		return ((char*)str);
	return (ptr);
}
