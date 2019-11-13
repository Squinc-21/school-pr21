/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 21:54:45 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/13 18:21:51 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int j;

	i = 0;
	j = ft_strlen(src);
	if (dest == NULL || src == NULL)
		return (NULL);
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
