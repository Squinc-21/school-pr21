/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:07:38 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:29:45 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
			++i;
		else
			return (0);
	}
	if (i == n)
		return (1);
	if (s1[i] != '\0' || s2[i] != '\0')
		return (0);
	return (1);
}
