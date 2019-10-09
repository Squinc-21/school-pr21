/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:58:26 by squinc            #+#    #+#             */
/*   Updated: 2019/10/09 16:40:54 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		to_free(char **s)
{
    free(s);
}

void free_all(char *buf, char ***parts, int k)
{
 	ft_memdel((void**)&buf);
    while (k < 26)
		{
			to_free(parts[k]);
			++k;
		}
    free(parts);
	parts = NULL;
}
	//int	i;

	//i = 0;
	//while (s[i])
      //      {
		//		free(s[i]);
		//		++i;
		//	}