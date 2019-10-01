/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:42:15 by squinc            #+#    #+#             */
/*   Updated: 2019/10/01 16:37:33 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		to_free(char **s)
{
	int	i;

	i = 0;
	while (i < 26)
		free(s[i++]);
	free(s);
}


int **init_mas(int **s)
{
    int i;

    if (!(s = (int**)malloc(sizeof(int *) * 26)))
        return(NULL);
    i = 0;
    while (i < 26)
    {
        if(!(s[i] = (int*)malloc(sizeof(int) * 4)))
        {
            to_free(s);
            return(NULL);
        }
        ft_bzero(s[i], 4);
        ++i;
    }
    return(s);
}

int main(int argc, char **argv)
{
    size_t i;
    static int **parts;

    if (argc == 2)
    {
        parts = init_mas(parts);
        read_file(argv[1], parts);
        
    }
}