/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:30:42 by squinc            #+#    #+#             */
/*   Updated: 2019/10/03 17:33:46 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void remove_tetr(char **part, char **map, int i, int j)
{
    int row;
    int col;
    row = 0;
    col = 0;
    while (part[row])
    {
        while (part[row][col])
        {
            if (map[i + row][j + col] != '.' && part[row][col] != '.')
                map[i + row][j + col] = '.';
            col++;
        }
        row++;
    }
}
void paste_tetr(char **part, char **map, int i, int j)
{
    int row;
    int col;
    row = 0;
    col = 0;
    while (part[row])
    {
        while (part[row][col])
        {
            if (part[row][col] == '#')
                map[i + row][j + col] = get_letter(map);
            col++;
        }
        row++;
    }
}
int is_safe(char **part, char **map, int i, int j)
{
    int row;
    int col;
    if (i + get_height(part) >= get_n(map)
        || j + get_width(part) >= get_n(map))
        return (0);
    row = 0;
    col = 0;
    while (part[row])
    {
        while (part[row][col])
        {
            if (map[i + row][j + col] != '.' && part[row][col] == '#')
                return (0);
            col++;
        }
        row++;
    }
    return (1);
}
int dance_like_sudoku(char ***parts, char **map)
{
    int i;
    int j;
    if (!*parts)
        return (1);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (is_safe(*parts, map, i, j))
            {
                paste_tetr(*parts, map, i, j);
                if (dance_like_sudoku(parts++, map))
                    return (1);
                else//vozmozhno udalenie else
                    remove_tetr(*parts, map, i, j);
            }
            j++;
        }
        i++;
    }
    return (0);
}
