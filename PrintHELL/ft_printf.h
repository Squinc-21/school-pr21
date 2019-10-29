#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>

typedef struct  s_printf
{
	int 		t_len;
	int			fd;
	va_list 	ap;
	char 		*source;
	char		buf[100];
	int			prefix;
	int			fill_zero;
	int			l_align;
	int			plus_sign;
	int			space_sign;
	int			precision;
	int			width;
	int			size;	// h - 1 hh - 2 l - 3 ll - 4 L - 5
}				t_printf;

int				ft_printf(const char *format, ...);
void			ft_parse(t_printf *st, char *buf);



int				is_digit(char c);
int				is_flag(char c);
int				is_conv(char c);
int				is_len_fl(char c);


#endif