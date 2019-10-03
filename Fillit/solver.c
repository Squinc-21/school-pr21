/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:32:14 by squinc            #+#    #+#             */
/*   Updated: 2019/10/03 17:33:50 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void    to_free(char **s)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
}

char **make_map(int size)
{
    int i;
    int j;
    char **map;
    
    i = 0;
    if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
        return (NULL);
    while (i < size)
    {
        j = 0;
        if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
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
    return (map);
}

void print_map(char **map)
{
    int i;
    
    i = 0;
    while(map[i])
    {
        write(1, map[i], get_n(map));
        i++;
    }
}

int solver(char ***parts, int size)
{
    char **map;
    
    if(!(map = make_map(size)))
        return (0);
    if (!(dance_like_sudoku(parts, map)))
    {
        to_free(map);
        solver(parts, size + 1);
    }
    else
        print_map(map);
    return (1);
}
