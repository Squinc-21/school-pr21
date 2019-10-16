/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:14:41 by squinc            #+#    #+#             */
/*   Updated: 2019/10/12 19:01:32 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_strsplit(char const *s, char c, char **part)
{
	char	**arr;
	int		j;
	int		i;
	int		k;

	i = 0;
	if (!s || !(arr = (char **)malloc(5 * sizeof(char *))))
		return ;
	j = 0;
	while (j < 4)
	{
		while (s[i] == c)
			++i;
		if ((arr[j] = (char *)malloc(4 * sizeof(char))) == NULL)
			to_free(arr);
		k = 0;
		while (s[i] != c && s[i])
		{
			arr[j][k++] = s[i++];
			ft_strcpy(part[j], arr[j]);
		}
		arr[j++][k] = '\0';
	}
	arr[j] = NULL;
	to_free(arr);
}
