/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:33:26 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/03 17:02:10 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out = NULL;
	if ((s1 != NULL) && (s2 != NULL) &&
			(out = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		while (s1[i])
		{
			out[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			out[i] = s2[j];
			i++;
			j++;
		}
		out[i] = '\0';
	}
	return (out);
}
