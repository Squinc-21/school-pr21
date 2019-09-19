/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:05:44 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 17:06:19 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_str(int nb)
{
	int		i;
	char	s[11];

	i = 0;
	while (nb != 0)
	{
		s[i] = nb % 10 + '0';
		++i;
		nb = nb / 10;
	}
	--i;
	while (i >= 0)
	{
		ft_putchar(s[i]);
		--i;
	}
}

void		ft_putnbr(int n)
{
	int	nb;

	nb = n % 10;
	if (nb < 0 || n < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	n = n / 10;
	if (n < 0)
	{
		n = -n;
	}
	print_str(n);
	ft_putchar(nb + '0');
}
