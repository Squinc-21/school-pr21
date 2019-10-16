/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:35:45 by squinc            #+#    #+#             */
/*   Updated: 2019/10/13 15:06:41 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char	*c;

	if (size + 1 == 0)
		return (NULL);
	c = (char*)malloc(sizeof(char) * (size + 1));
	if (c == NULL)
		return (NULL);
	c = ft_memset(c, '\0', size + 1);
	return (c);
}
