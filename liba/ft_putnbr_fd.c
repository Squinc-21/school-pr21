/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:15:24 by squinc            #+#    #+#             */
/*   Updated: 2019/09/13 17:53:01 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_str_fd(int nb, int fd)
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
		ft_putchar_fd(s[i], fd);
		--i;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int	nb;

	nb = n % 10;
	if (nb < 0 || n < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	n = n / 10;
	if (n < 0)
	{
		n = -n;
	}
	print_str_fd(n, fd);
	ft_putchar_fd(nb + '0', fd);
}
