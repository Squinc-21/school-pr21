/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:59:38 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:32:50 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned const char	*c1;
	unsigned const char	*c2;

	i = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (s1[i] && s2[i] && i < n)
	{
		if (c1[i] == c2[i])
			++i;
		else
			return (c1[i] - c2[i]);
	}
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
}
