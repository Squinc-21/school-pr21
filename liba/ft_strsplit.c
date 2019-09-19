/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:14:41 by squinc            #+#    #+#             */
/*   Updated: 2019/09/16 21:44:36 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_c(char const *s, char f)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == f)
			i += 1;
		if (s[i] != f && s[i] != '\0')
		{
			c += 1;
			while (s[i] != f && s[i])
				i += 1;
		}
		if (s[i])
			i += 1;
	}
	return (c);
}

static int	ft_w_len(char const *a, int i, char c)
{
	int	n;

	n = 0;
	while (a[i] != c && a[i] != '\0')
	{
		i += 1;
		n += 1;
	}
	return (n);
}

void		to_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		j;
	int		i;
	int		k;

	i = 0;
	if (!s || !(arr = (char **)malloc((ft_word_c(s, c) + 1) * sizeof(char *))))
		return (NULL);
	j = 0;
	while (j < ft_word_c(s, c))
	{
		while (s[i] == c)
			++i;
		if ((arr[j] = malloc((ft_w_len(s, i, c) + 1) * sizeof(char))) == NULL)
		{
			to_free(arr);
			return (NULL);
		}
		k = 0;
		while (s[i] != c && s[i])
			arr[j][k++] = s[i++];
		arr[j++][k] = '\0';
	}
	arr[j] = NULL;
	return (arr);
}
