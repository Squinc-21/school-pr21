/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:31:40 by squinc            #+#    #+#             */
/*   Updated: 2019/10/12 12:31:32 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_height(char **part)
{
	int i;
	int j;
	int height;

	i = 0;
	height = 0;
	if (!part)
		return (0);
	while (part[i])
	{
		j = 0;
		while (part[i][j])
		{
			if (part[i][j] == '#' && i > height)
				height = i;
			j++;
		}
		i++;
	}
	return (height + 1);
}

int		get_width(char **part)
{
	int i;
	int j;
	int width;

	i = 0;
	width = 0;
	if (!part)
		return (0);
	while (part[i])
	{
		j = 0;
		while (part[i][j])
		{
			if (part[i][j] == '#' && j > width)
				width = j;
			j++;
		}
		i++;
	}
	return (width + 1);
}

char	get_letter(char **map)
{
	int		i;
	int		j;
	char	let;

	i = 0;
	let = 'A' - 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] >= 'A' && map[i][j] <= 'Z' && map[i][j] > let)
			{
				let = map[i][j];
			}
			j++;
		}
		i++;
	}
	return (let + 1);
}

int		get_n(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int		get_nearest_square(int num)
{
	int i;

	i = 0;
	while ((i * i) < num)
		i++;
	return (i);
}
