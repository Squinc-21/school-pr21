/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:36:28 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:50:30 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*c;

	c = malloc(ft_strlen(src) + 1);
	if (c == NULL)
		return (NULL);
	ft_strcpy(c, src);
	return (c);
}
