/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:10:57 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:06:10 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		while (str[j] && str[i + j] && str[i + j] == to_find[j])
			++j;
		if (j == ft_strlen(to_find) || to_find[j] == '\0')
			return ((char*)(str + i));
		++i;
	}
	return (NULL);
}
