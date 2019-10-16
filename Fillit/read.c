/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:18:01 by squinc            #+#    #+#             */
/*   Updated: 2019/10/16 13:06:28 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**shift(char ***parts, int num, t_size min)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (parts[num][i][j] == '#')
			{
				parts[num][i][j] = '.';
				parts[num][i - min.y][j - min.x] = '#';
			}
			++j;
		}
		++i;
	}
	return (parts[num]);
}

static char		**get_pos(char *buf, char ***parts, int num)
{
	int		i;
	int		j;
	t_size	min;

	i = 0;
	min.x = 4;
	min.y = 4;
	buf[20] = '\0';
	ft_strsplit(buf, '\n', parts[num]);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (parts[num][i][j] == '#')
			{
				min.y = (i < min.y) ? i : min.y;
				min.x = (j < min.x) ? j : min.x;
			}
			++j;
		}
		++i;
	}
	parts[num] = shift(parts, num, min);
	return (parts[num]);
}

static int		check_tetr(char *buf)
{
	int i;
	int grid;
	int n;

	i = 0;
	grid = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			n = i;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				++grid;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				++grid;
			if ((i + 1) < 20 && buf[i + 1] == '#')
				++grid;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				++grid;
		}
		++i;
	}
	return (grid == 6 || grid == 8);
}

static int		check(char *buf, int count)
{
	int i;
	int grid;

	i = 0;
	grid = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '#' && buf[i] != '.')
				return (1);
			if (buf[i] == '#' && ++grid > 4)
				return (2);
		}
		else if (buf[i] != '\n')
			return (3);
		++i;
	}
	if (grid != 4 || (count == 21 && buf[20] != '\n'))
		return (4);
	if (!(check_tetr(buf)))
		return (5);
	return (0);
}

int				read_file(char *name, char ***parts)
{
	int		fd;
	int		n;
	char	*buf;
	int		num;

	buf = ft_strnew(21);
	if ((fd = open(name, O_RDWR)) < 0)
		return (0);
	num = 0;
	while ((n = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		if (num > 25 || (check(buf, n) != 0 && free_all(buf, parts)))
			return (0);
		else
		{
			parts[num] = get_pos(buf, parts, num);
			buf[20] = (n == 21) ? '.' : buf[20];
		}
		++num;
	}
	if (((n != 0 && n < 20) || buf[20] == '.') && ft_memdel((void**)&buf))
		return (0);
	ft_memdel((void**)&buf);
	close(fd);
	return (num);
}
