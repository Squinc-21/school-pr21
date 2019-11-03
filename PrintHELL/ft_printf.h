#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef struct  s_printf
{
	int 		t_len;
	int			fd;
	va_list 	ap;

	char 		*source;
	char		*buf;
	int			buf_len;
	char		*out;
	
	int			prefix;
	int			fill_zero;
	int			l_align;
	int			plus_sign;
	int			space_sign;
	int			precision;
	int			width;
	int			size;	// hh - 1 h - 2 l - 3 ll - 4 L - 5
}				t_printf;

int				ft_printf(const char *format, ...);
void			ft_parse(t_printf *st, char *buf);
int				ft_atoi(char *str);
void			cr_int(t_printf *st);
void			cr_unsigned(t_printf *st);
int				is_digit(char c);
int				is_flag(char c);
int				is_conv(char c);
int				is_len_fl(char c);
void			reset_st(t_printf *st);

char			*pf_itoa(intmax_t n, t_printf *st);
char			*pf_uitoa(uintmax_t n, t_printf *st, int base);
void			ft_putstr(char *s);
void			cr_output(t_printf *st);
void			print_str(t_printf *st, int sp, int zero);
void			print_cycle(int sp, int zero, char c);
void			define_conv(t_printf *st);

void			*ft_memalloc(size_t size);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
void			handle_double(t_printf *st);
intmax_t		doub_to_int(long double num, int presicion);
char			*pf_ditoa(long double num, t_printf *st);
void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);

#endif