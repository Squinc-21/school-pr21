/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:54:54 by squinc            #+#    #+#             */
/*   Updated: 2019/11/14 14:34:45 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	paint(char *to_paint, int len)
{
	to_paint = ft_stj("\033[36;43m\033[1m", to_paint);
	to_paint = ft_stj(to_paint, "\033[0m");
	write(1, to_paint, len + 20);
}
