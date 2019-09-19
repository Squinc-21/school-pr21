/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:41:46 by squinc            #+#    #+#             */
/*   Updated: 2019/09/16 20:52:10 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int		len1;
	unsigned int		len2;
	char	*new;
	int		i;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen((char*)s1);
	len2 = ft_strlen((char*)s2);
	if (len1 + len2 + 1 == 0)
		return (0);
	new = (char*)malloc(len1 + len2 + 1);
	if (!new)
		return (0);
	i = 0;
	while (*s1)
		new[i++] = *(s1++);
	while (*s2)
		new[i++] = *(s2++);
	new[i] = 0;
	return (new);
}
