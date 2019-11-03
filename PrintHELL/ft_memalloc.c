/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:44:04 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/03 17:02:15 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void *out;

	if (!(out = malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(out, size);
	return (out);
}
