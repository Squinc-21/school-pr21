/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:58:26 by squinc            #+#    #+#             */
/*   Updated: 2019/10/11 19:47:58 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		to_free(char **s)
{
	int i;

	i = 0;
	while(s[i])
	{
		free(s[i]);
		s[i] = NULL;
		++i;
	}
    free(s);
	s = NULL;
}

int free_all(char *buf, char ***parts)
{
	int k;

	k = 0;
 	ft_memdel((void**)&buf);
    while (parts[k])
		{
			to_free(parts[k]);
			++k;
		}
    free(parts);
	parts = NULL;
	return (1);
}

void free_alls(char ***parts)
{
	int k;

	k = 0;
	while (parts[k])
	{
		to_free(parts[k]);
		++k;
	}
	while (k < 26)
	{
		free(parts[k]);
		++k;
	}
	*parts = NULL;
    free(parts);
	parts = NULL;
}