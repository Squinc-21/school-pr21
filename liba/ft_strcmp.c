/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:48:48 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:55:28 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;
	unsigned const char	*c1;
	unsigned const char	*c2;

	i = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (c1[i] && c2[i])
	{
		if (c1[i] == c2[i])
			++i;
		else
			return (c1[i] - c2[i]);
	}
	return (c1[i] - c2[i]);
}
