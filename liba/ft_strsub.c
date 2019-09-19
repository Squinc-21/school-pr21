/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:11:15 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 18:12:30 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = (size_t)start;
	sb = (char*)malloc(sizeof(char) * (len + 1));
	if (sb == NULL)
		return (NULL);
	j = 0;
	while (s[i] && len > 0)
	{
		sb[j] = s[i];
		++j;
		++i;
		--len;
	}
	sb[j] = '\0';
	return (sb);
}
