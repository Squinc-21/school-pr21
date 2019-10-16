/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:41:16 by squinc            #+#    #+#             */
/*   Updated: 2019/10/13 15:07:43 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)dest;
	while (n > 0)
	{
		*ptr = c;
		++ptr;
		--n;
	}
	return (dest);
}
