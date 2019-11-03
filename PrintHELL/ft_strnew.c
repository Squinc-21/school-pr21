/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:57:20 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/03 17:02:07 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *out;

	if (size > size + 1)
		return (NULL);
	out = (char *)ft_memalloc(size + 1);
	if (out == NULL)
		return (NULL);
	ft_memset(out, (int)'\0', size + 1);
	return (out);
}
