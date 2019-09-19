/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:40:46 by squinc            #+#    #+#             */
/*   Updated: 2019/09/16 20:41:29 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (0);
	if (!content)
	{
		new->content_size = 0;
		new->content = 0;
	}
	else
	{
		new->content_size = content_size;
		new->content = (void*)malloc(content_size);
		if (!new->content)
		{
			free(new);
			return (0);
		}
		ft_memcpy(new->content, content, content_size);
	}
	new->next = 0;
	return (new);
}
