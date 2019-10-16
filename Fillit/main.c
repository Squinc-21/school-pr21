/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:42:15 by squinc            #+#    #+#             */
/*   Updated: 2019/10/13 15:57:40 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***init_mas(char ***s)
{
	int i;
	int j;

	if (!(s = (char***)malloc(sizeof(char **) * 27)))
		return (NULL);
	i = -1;
	while (++i < 26)
	{
		if (!(s[i] = (char**)malloc(sizeof(char*) * 5)))
		{
			to_free(s[i]);
			return (NULL);
		}
		j = -1;
		while (++j < 4)
		{
			if (!(s[i][j] = (char*)malloc(sizeof(char) * 5)))
			{
				to_free(s[i]);
				return (NULL);
			}
			ft_bzero(s[i][j], 5);
		}
	}
	return (s);
}

int		main(int argc, char **argv)
{
	int			i;
	int			n;
	static char	***parts;

	if (argc == 2)
	{
		i = 0;
		parts = NULL;
		parts = init_mas(parts);
		if (!(n = read_file(argv[1], parts)))
		{
			ft_putstr("error\n");
			return (1);
		}
		else
			solver(parts, get_nearest_square(n * 4));
		free_alls(parts);
	}
	else
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	return (0);
}
