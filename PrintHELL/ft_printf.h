/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:48:59 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/11/11 21:54:46 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ABS(Value) (Value < 0) ? (-1)*Value : Value

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct	s_printf
{
	int			t_len;
	int			fd;
	va_list		ap;
	char		*source;
	char		*buf;
	int			buf_len;
	int			prefix;
	int			fill_zero;
	int			l_align;
	int			plus_sign;
	int			space_sign;
	int			precision;
	int			width;
	int			size;
}				t_printf;

int				ft_printf(const char *format, ...);
void			ft_parse(t_printf *st);
void			handle_percent(t_printf *st);
void			handle_presicion(t_printf *st);
int				ft_atoi(char *str);
void			cr_int(t_printf *st);
void			cr_unsigned(t_printf *st);
int				is_digit(char c);
int				is_flag(char c);
int				is_conv(char c);
int				is_len_fl(char *c);
void			reset_st(t_printf *st);

char			*pf_itoa(intmax_t n, t_printf *st);
char			*pf_uitoa(uintmax_t n, t_printf *st, int base);
void			ft_putstr(char *s, size_t len);
void			cr_output(t_printf *st);
void			flags_for_output(int sp, int zero, t_printf *st);
void			print_str(t_printf *st, int sp, int zero);
void			plus_d_i(int sp, int zero, t_printf *st);
void			non_prefix(int sp, int zero, t_printf *st);
void			left_align(int sp, int zero, t_printf *st);
void			print_cycle(int sp, int zero, char c);
void			define_conv(t_printf *st);

void			*ft_memalloc(size_t size);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_stj(char const *s1, char const *s2);
void			handle_double(t_printf *st);
void			make_correct_output_d(long double num, t_printf *st);
char			*doub_to_int(long double num, int presicion, t_printf *st, char *post);
void			concatenate(char *pre_dot, char *post_dot, t_printf *st);
void			pf_ditoa(long double num, t_printf *st);
void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				form_pref(t_printf *st, int sp);
char			*handle_sym(t_printf *st);
void			make_correct_output_s(t_printf *st, int flag);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_uitoa(uintmax_t n, int len, int base, t_printf *st);
char			*ft_itoa(intmax_t n, int len, t_printf *st);
char			*ft_strncpy(char *dest, const char *src, size_t n);

#endif
