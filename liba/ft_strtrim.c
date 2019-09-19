/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:43:08 by squinc            #+#    #+#             */
/*   Updated: 2019/09/16 20:53:57 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_cpy(char *src, int i, int len)
{
	char	*new;
	int		j;
	int		k;

	if (i == len)
	{
		new = (char*)malloc(1);
		new[0] = 0;
		return (new);
	}
	j = len - 1;
	while (src[j] == ' ' || src[j] == '\n' || src[j] == '\t')
		j--;
	new = (char*)malloc(j - i + 1 + 1);
	if (!new)
		return (0);
	k = 0;
	while (i <= j)
		new[k++] = src[i++];
	new[k] = 0;
	return (new);
}

char		*ft_strtrim(char const *s)
{
	size_t		j;
	size_t		i;
	size_t		len;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen((char*)s);
	j = len - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	return (str_cpy((char*)s, i, len));
}
