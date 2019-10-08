/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:32:14 by squinc            #+#    #+#             */
/*   Updated: 2019/10/08 20:54:41 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char **make_map(int size)
{
    int i;
    int j;
    char **map;
    
    i = 0;
    if (!(map = (char **)malloc(sizeof(char *) * (size ))))
        return (NULL);
    while (i < size)
    {
        j = 0;
        if (!(map[i] = (char *)malloc(sizeof(char) * (size ))))
        {
            to_free(map);
            return (NULL);
        }
        while (j < size)
        {
            map[i][j] = '.';
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
    map[i] = NULL;
    printf("%d   size\n", size);
    return (map);
}

void print_map(char **map)
{
    int i;
    
    i = 0;
    while(map[i])
    {
        ft_putstr(map[i]);
        ft_putstr("\n");
        i++;
    }
    ft_putchar('\n');
}

char ***ex_change(char*** parts, int n)
{
    int     i;
    char    **c;

    i = 0;
    c = *parts;
    while (i < n)
    {
        *parts = *(parts + 1);
        ++parts;
        ++i;
    }
    parts[n] = c;
    return (parts);
}

int solver(char ***parts, int size, int n)
{
    char **map;
    int i;

    i = 0;
    if (!(map = make_map(size)))
        return (0);
    if (!(dance_like_sudoku(parts, map, i)))
    {
        //parts = ex_change(parts, n);
        //solver(parts, size, n); //vot zdes modernisorovat
        to_free(map);
        solver(parts, size + 1, n);
    }
    else
    {
        print_map(map);
        to_free(map);
    }
    return (1);
}