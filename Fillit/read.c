/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:18:01 by squinc            #+#    #+#             */
/*   Updated: 2019/09/28 19:30:13 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_tetr(char *buf)
{
    int i;
    int grid;

    i = 0;
    grid = 0;
    while (i < 20)
    {
        if (buf[i] == "#")
        {
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
    return (grid == 6 || grid == 8);
}

int check(char *buf, int count)
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
                return (1);//далее 1,2... коды ошибок
            if (buf[i] == '#' && ++grid > 4)
                return (2);//если больше 4 решеток
        }
        else if (buf[i] != '\n')
            return (3);//не конец строки на 5,10,15,20 символе
        ++i;
    }
    if (count == 21 && buf[20] != '\n')
        return (4);//в конце файла
    if (!(check_tetr(buf)))
        return (5);//проверка фигурки на касания
    return(0);
}

int read_file(char *name)
{
    int fd;
    int n;
    char *buf;
    int c_symb;

    buf = ft_strnew(21);
    fd = open(name, O_RDWR);
    if (fd < 0)
        return(0);
    while ((n = read(fd, buf, BUFF_SIZE)) >= 20)
    {
        if (check(buf, n) != 0)
        {
            //очистка ранее выделенной памяти
        }
    }
    ft_memdel(buf);
}