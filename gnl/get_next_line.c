/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:38:46 by squinc            #+#    #+#             */
/*   Updated: 2019/09/19 14:59:44 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
    static char *s[256];
    char        buf[BUFF_SIZE + 1];
    char        *tmp;
    int         n_symb;
    
    if (fd < 0 || !line)
        return (-1);
    while (n_symb = read(fd, buf, BUFF_SIZE) > 0)
    {
	   	buf[n_symb] = '\0';
	   	if (s[fd] == 0)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break;
    }
    if (n_symb < 0)
        return (-1);
    
}
