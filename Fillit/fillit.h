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

int					read_file(char *name, char ***parts, t_size *max, int k);
void				free_all(char *buf, char ***parts, int k);
void				to_free(char **s);
////
char                **ft_strsplit(char const *s, char c);
void                ft_memdel(void **ap);
void                ft_putstr(char const *s);
char                *ft_strnew(size_t size);
void                ft_bzero(void *dest, size_t n);
void				ft_putchar(char c);
void				*ft_memset(void *dest, int c, size_t n);

#endif
