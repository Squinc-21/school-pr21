/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:18:01 by squinc            #+#    #+#             */
/*   Updated: 2019/10/01 16:37:39 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"




int **get_pos(char *buf, int **parts, int num)//так не пойдет, надо перевести в двумерный!
{
    int i;
    int q;

    i = 0;
    q = 0;
    while (buf[i] != "#")
        i++;
    parts[num][q++] = i;
    while (i++ < 20)
    {
        if (buf[i] == "#")
            parts[num][q++] = i; 
    }

    return (parts);
}



static int  check_tetr(char *buf, int num, int **parts)
{
    int i;
    int grid;
    int n;

    i = 0;
    grid = 0;
    while (i < 20)
    {
        if (buf[i] == "#")
        {
            n = i;
            if ((i - 1) >= 0 && buf[i - 1] == '#')
                ++grid;
            else if ((i - 5) >= 0 && buf[i - 5] == '#')
                ++grid;
            else if ((i + 1) < 20 && buf[i + 1] == '#')
                ++grid;
            else if ((i + 5) < 20 && buf[i + 5] == '#')
                ++grid;
        }
        ++i;
    }
    if (grid == 6 || grid == 8)
        parts = get_pos(buf, parts, num);
    return (grid == 6 || grid == 8);
}

static int  check(char *buf, int count, int num, int **parts)
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
    if (!(check_tetr(buf, num, parts)))
        return (5);
    return(0);
}

int             read_file(char *name, int **parts)
{
    int fd;
    int n;
    char *buf;
    int num;

    buf = ft_strnew(21);
    fd = open(name, O_RDWR);
    if (fd < 0)
        return(0);
    num = 0;
    while ((n = read(fd, buf, BUFF_SIZE)) >= 20)
    {
        if (check(buf, n, num, parts) != 0)
        {
            //очистка ранее выделенной памяти
        }
        ++num;
    }
    ft_memdel(buf);
}