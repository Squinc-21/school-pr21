/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:11:33 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 16:59:52 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], fd);
	}
}
