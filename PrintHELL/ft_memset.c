/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:28:43 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/03 17:02:15 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *q;

	q = (unsigned char *)s;
	while (n-- > 0)
		*(q++) = (unsigned char)c;
	return (s);
}
