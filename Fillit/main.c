/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:42:15 by squinc            #+#    #+#             */
/*   Updated: 2019/10/11 19:47:54 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char ***init_mas(char ***s)
{
    int i;
    int j;

    if (!(s = (char***)malloc(sizeof(char **) * 27)))
        return(NULL);
    i = -1;
    while (++i < 26)
    {
        if(!(s[i] = (char**)malloc(sizeof(char*) * 5)))
        {
            to_free(s[i]);
            return(NULL);
        }
        j = -1;
        while (++j < 4)
        {
            if (!(s[i][j] = (char*)malloc(sizeof(char) * 5)))
            {
                to_free(s[i]);
                return(NULL);
            }
            ft_bzero(s[i][j], 5);
        }
    }
    return(s);
}

int main(int argc, char **argv)
{
    int i;
    int n;
    static char     ***parts;

    if (argc == 2)
    {
        i = 0;
        parts = NULL;
        parts = init_mas(parts);
        if (!(n = read_file(argv[1], parts)))  
            {
                ft_putstr("error");
                return (1);
            }
        else
        {
            solver(parts, get_nearest_square(n * 4));
        }
    }
    return (0);
}
//gcc -Wextra -Wall -Werror -g main.c memory.c read.c ft_bzero.c ft_memdel.c ft_putstr.c ft_strnew.c ft_strsplit.c ft_putchar.c ft_memset.c fill_map.c getters.c solver.c