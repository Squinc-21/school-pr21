/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:42:15 by squinc            #+#    #+#             */
/*   Updated: 2019/10/02 18:13:14 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char ***init_mas(char ***s)
{
    int i;
    int j;

    if (!(s = (char***)malloc(sizeof(char **) * 26)))
        return(NULL);
    i = 0;
    while (i++ < 26)
    {
        if(!(s[i] = (char**)malloc(sizeof(char*) * 4)))
        {
            to_free(s[i]);
            return(NULL);
        }
        j = 0;
        while (j++ < 4)
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
    int j;
    static char     ***parts;
    static t_size   max[26];

    if (argc == 2)
    {
        i = 0;
        parts = NULL;
        parts = init_mas(parts);
        if (!(n = read_file(argv[1], parts, max, 0)))  
            ft_putstr("error");
        else
        {
            while(i < n)
            {
                j = 0;
                while (j < 4)
                {
                    ft_putstr(parts[i][j]);
                    ++j;
                }
                ++i;
            }
        }
        
    }
    return (0);
}
//gcc -Wextra -Wall -Werror main.c memory.c read.c ft_bzero.c ft_memdel.c ft_putstr.c ft_strnew.c 
//ft_strsplit.c ft_putchar.c ft_memset.c