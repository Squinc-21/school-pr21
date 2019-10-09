/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:30:42 by squinc            #+#    #+#             */
/*   Updated: 2019/10/09 16:40:56 by squinc           ###   ########.fr       */
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
    int n;

    n = get_n(map);
    if (!*parts)
        return (1);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (is_safe(*parts, map, i, j)) 
            {
                print_map(map);
                if (dance_like_sudoku(++parts, map, 0, 0))
                    return (1);
                else
                    {
                        remove_tetr(*parts, map, i, j);
                        //if (j < n)
                        //    dance_like_sudoku(parts, map, i, j + 1);
                        //else 
                         //   dance_like_sudoku(parts,map, i + 1, 0);
                        //от следующей клетки
                        //сдвинуть фигуру в массиве в конец
                        //подставить следующую фигуру 
                    }
            }
            j++;
        }
        i++;
    }
    return (0);
}