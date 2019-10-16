/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:22:11 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/10/16 13:09:23 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFF_SIZE 21

typedef struct		s_size
{
	int x;
	int y;
}					t_size;

int					read_file(char *name, char ***parts);
int					free_all(char *buf, char ***parts);
void				free_alls(char ***parts);
void				to_free(char **s);
void				ft_strsplit(char const *s, char c, char **part);
int					ft_memdel(void **ap);
void				ft_putstr(char const *s);
char				*ft_strnew(size_t size);
void				ft_bzero(void *dest, size_t n);
void				ft_putchar(char c);
void				*ft_memset(void *dest, int c, size_t n);
void				remove_tetr(char **part, char **map, int i, int j);
void				paste_tetr(char **part, char **map, int i, int j);
int					is_safe(char **part, char **map, int i, int j);
int					dance_like_sudoku(char ***parts, char **map, int i, int j);
int					get_height(char **part);
int					get_width(char **part);
char				get_letter(char **map);
int					get_n(char **map);
int					get_nearest_square(int num);
char				**make_map(int size);
void				print_map(char **map);
int					solver(char ***parts, int size);
char				*ft_strcpy(char *dest, const char *src);
char				***init_mas(char ***s);

#endif
