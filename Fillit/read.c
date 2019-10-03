/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:18:01 by squinc            #+#    #+#             */
/*   Updated: 2019/10/03 17:33:37 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char        **shift(char ***parts, int num, t_size min, t_size *max)
{
    int i;
    int j;

    max[num].x = 0;
    max[num].y = 0;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (parts[num][i][j] == '#')
                {
                    parts[num][i][j] = '.';
                    max[num].x = (j - min.x > max[num].x) ? j - min.x : max[num].x;
                    max[num].y = (i - min.y > max[num].y) ? i - min.y : max[num].y;
                    parts[num][i - min.y][j - min.x] = '#';
                }
                ++j;
        }
        ++i;
    }
    return(parts[num]);
}

char        **get_pos(char *buf, char ***parts, int num, t_size *max)
{
    int i;
    int j;
    t_size min;

    i = 0;
    min.x = 4;
    min.y = 4;
    buf[20] = '\0';
    parts[num] = ft_strsplit(buf, '\n');
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
    parts[num] = shift(parts, num, min, max);
    return (parts[num]);
}



static int  check_tetr(char *buf)
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

static int  check(char *buf, int count)
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
    if (count == 21 && buf[20] != '\n')
        return (4);
    if (!(check_tetr(buf)))
        return (5);
    return(0);
}

int             read_file(char *name, char ***parts, t_size *max, int k)
{
    int     fd;
    int     n;
    char    *buf;
    int     num;

  
    buf = ft_strnew(21);
    fd = open(name, O_RDWR);
    if (fd < 0)
        return(0);
    num = 0;
    while ((n = read(fd, buf, BUFF_SIZE)) >= 20)
    {
        if (check(buf, n) != 0)
            {
                free_all(buf, parts, k);  
                return(0);
            }
        else
            parts[num] = get_pos(buf, parts, num, max);
        ++num;
    }
  //  ft_memdel((void**)buf);как_то пофиксить надо, пока хз
    close(fd);
    return (num);
}