/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:30:42 by squinc            #+#    #+#             */
/*   Updated: 2019/10/11 19:47:56 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void remove_tetr(char **part, char **map, int i, int j)
{
    int row;
    int col;

    row = 0;
    while (part[row])
    {
        col = 0;
        while (part[row][col] && i + row < get_n(map)  && j + col < get_n(map))
        {
            if (map[i + row][j + col] != '.' && part[row][col] == '#')
                map[i + row][j + col] = '.';
            col++;
        }
        row++;
    }
}

void paste_tetr(char **part, char **map, int i, int j)
{
    int row;
    char q;
    int col;
    
    row = 0;
    q = get_letter(map);
    while (part[row])
    {
        col = 0;
        while (part[row][col])
        {
            if (part[row][col] == '#')
                map[i + row][j + col] = q;
            col++;
        }
        row++;
    }
}

int is_safe(char **part, char **map, int i, int j)
{
    int row;
    int col;
    
    if (i + get_height(part) > get_n(map)
        || j + get_width(part) > get_n(map))
        return (0);
    row = 0;
    while (part[row])
    {
        col = 0;
        while (part[row][col] != '\0' && i + row < get_n(map)  && j + col < get_n(map))
        {
            if (map[i + row][j + col] != '.' && part[row][col] == '#')
                return (0);
            col++;
        }
        row++;
    }
    paste_tetr(part, map, i, j);
    return (1);
}

int dance_like_sudoku(char ***parts, char **map, int i, int j)
{
    if(!*(parts + 1))
        return (1);
    while (map[i])
    {
        while (map[i][j])
        {
            if (is_safe(*parts, map, i, j)) 
            {
                if (dance_like_sudoku((parts + 1), map, 0, 0))
                    return (1);
                else
                    remove_tetr(*parts, map, i, j);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}