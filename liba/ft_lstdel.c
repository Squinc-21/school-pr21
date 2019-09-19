/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:35:59 by squinc            #+#    #+#             */
/*   Updated: 2019/09/16 20:57:41 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;
	t_list	*buf;

	next = *alst;
	while (next)
	{
		buf = next->next;
		del(next->content, next->content_size);
		free(next);
		next = buf;
	}
	*alst = 0;
}
