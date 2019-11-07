/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:07:45 by squinc            #+#    #+#             */
/*   Updated: 2019/11/07 18:19:47 by squinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_printf *st)
{
	if (*st->source == '-')
		st->l_align = 1;
	if (*st->source == '0')
		st->fill_zero = 1;
	if (*st->source == '+')
		st->plus_sign = 1;
	if (*st->source == ' ')
		st->space_sign = 1;
	if (*st->source == '#')
		st->prefix = 1;
}

static void	parse_length_flags(t_printf *st)
{
	if (*st->source == 'h' && *(st->source + 1) == 'h')
	{
		st->size = 1;
		st->source++;
	}
	else if (*st->source == 'l' && *(st->source + 1) == 'l')
	{
		st->size = 4;
		st->source++;
	}
	else if (*st->source == 'h' || *st->source == 'l' || *st->source == 'L')
	{
		st->size = (*st->source == 'h') ? 2 : st->size;
		st->size = (*st->source == 'l') ? 3 : st->size;
		st->size = (*st->source == 'L') ? 5 : st->size;
	}
}

void	ft_parse(t_printf *st)
{
	while (!is_conv(*st->source))
	{
		if (*st->source == '%')
		{	
			st->buf = (char *)malloc(sizeof(char) * 1);
            *st->buf = '%';
            st->buf_len = ft_strlen(st->buf);
            cr_output(st);
			return  ;
		}
		else if (is_flag(*st->source))
			parse_flags(st);
		else if (is_digit(*st->source))
		{
			st->width = ft_atoi(st->source);
			while(is_digit(*st->source))
				st->source++;
			st->source--;
		}
		else if (*st->source == '.')
		{
			if (is_digit(*(st->source + 1)))
				{
					st->precision = ft_atoi(++st->source);
					while(is_digit(*st->source))
						st->source++;
					st->source--;
				}
			else
				st->precision = 0;
		}
		else if (is_len_fl(st->source) == 0)
			parse_length_flags(st);	
		st->source++;	
	}
	define_conv(st);
}

void		define_conv(t_printf *st)
{
	
	if (*st->source == 'd' || *st->source == 'i')
		cr_int(st);
	if (*st->source == 'u'|| *st->source == 'o' || 
		*st->source == 'x' || *st->source == 'X' || *st->source == 'p')
		cr_unsigned(st);
	if (*st->source == 'f' || *st->source == 'F')
		handle_double(st);
	if (*st->source == 'c' || *st->source == 's')
    	handle_sym(st);
}

void		cr_unsigned(t_printf *st)
{
	int base;
	
	if (*st->source == 'p')
	{
		st->size = 4;
		st->prefix = 1;	
	}
	base = (*st->source == 'x' || *st->source == 'X' || *st->source == 'p') ? 16 : 0;
	base = (*st->source == 'o') ? 8 : base;
	base = (*st->source == 'u') ? 10 : base;
	if (st->size == 1)
		st->buf = pf_uitoa((unsigned char)va_arg(st->ap, unsigned int), st, base);
	else if (st->size == 2)
		st->buf = pf_uitoa((unsigned short int)va_arg(st->ap, unsigned int), st, base);
	else if (st->size == 3)
		st->buf = pf_uitoa(va_arg(st->ap, unsigned long int), st, base);
	else if (st->size == 4)
		st->buf = pf_uitoa(va_arg(st->ap, unsigned long long int), st, base);
	else
		st->buf = pf_uitoa(va_arg(st->ap, unsigned int), st, base);
	cr_output(st);
}

void		cr_int(t_printf *st)
{
	if (st->size == 1)
		st->buf = pf_itoa((signed char)va_arg(st->ap, int), st);
	else if (st->size == 2)
		st->buf = pf_itoa((short int)va_arg(st->ap, int), st);
	else if (st->size == 3)
		st->buf = pf_itoa(va_arg(st->ap, long int), st);
	else if (st->size == 4)
		st->buf = pf_itoa(va_arg(st->ap, long long int), st);
	else
		st->buf = pf_itoa(va_arg(st->ap, int), st);
	if (st->buf)
		st->plus_sign = (st->buf[0] == '-') ? 0 : st->plus_sign;
	cr_output(st);
}

void			cr_output(t_printf *st)
{
	int sp;
	int zero;
	
	sp = 0;
	zero = 0;
	if (st->space_sign && !st->plus_sign && ft_atoi(st->buf) >= 0)
		sp = 1;
	if (st->width > st->buf_len)
			sp = st->width - st->buf_len;
	if (st->fill_zero && st->precision < 0 && !st->l_align)
			zero = sp;
	if (st->plus_sign && (*st->source == 'd' || *st->source == 'i'))
	{
		sp = (sp > 0) ? sp - 1 : 0;
		zero = (zero > 0) ? zero - 1 : 0;
	}
	if (st->prefix)
	{
		if (st->width > st->buf_len)
			st->t_len += (*st->source == 'o') ? st->width - 1: st->width - 2;
		else if (!(st->width > st->buf_len) && st->width != 0)
			st->t_len += (*st->source == 'o') ? st->buf_len - 1: st->buf_len - 2;
		else if (!(st->width > st->buf_len) && st->width == 0)
			st->t_len += st->buf_len;
	}
	else
	{
		if (st->width > st->buf_len)
			st->t_len += st->width;
		else
			st->t_len += st->buf_len;
	}
	print_str(st, sp, zero);
}

void			print_str(t_printf *st, int sp, int zero)
{
	if (st->plus_sign && (*st->source == 'd' || *st->source == 'i'))
	{
		if (!st->l_align && zero <= 0)
		{
			print_cycle(sp, zero, ' ');
			write(1, "+", 1);
		}
		else if (zero >= 0 || st->l_align)
		{
			write(1, "+", 1);
			print_cycle(sp, zero - 1, '0');
		}
		st->t_len += (st->plus_sign && !st->width) ? 1 : 0;
		ft_putstr(st->buf, st->buf_len);
		if (st->width > st->buf_len && st->l_align)
			print_cycle(st->width - st->buf_len - 1, zero, ' ');
	}
	else if (st->l_align && !st->prefix)
	{
		if (st->space_sign)
			{
				st->t_len += (!st->width) ? 1 : 0;
				write(1," ",1);
				sp--;
			}
		ft_putstr(st->buf, st->buf_len);
		print_cycle(sp, zero, ' ');
	}
	else if (!st->prefix)
	{
		if (sp == 0 && st->space_sign)
			{
				write(1, " ", 1);
				st->t_len += (!st->width) ? 1 : 0;
			}
		else if (sp > 0)
			print_cycle(sp, zero, ' ');
		else if (zero > 0)
			print_cycle(sp, zero, '0');
		ft_putstr(st->buf, st->buf_len);
	}
	else
	{
		if (st->l_align)
		{
			sp = form_pref(st, sp);
			ft_putstr(st->buf, st->buf_len);
			print_cycle(sp, zero, ' ');
		}
		else
		{
			if (st->fill_zero && st->buf_len + 1 < st->precision)
			{
				zero = form_pref(st, zero);
				print_cycle(sp , zero , '0');
			}
			else
			{
				if (*st->source == 'o')
					print_cycle(sp - 1, zero, ' ');
				else
					print_cycle(sp - 2, zero, ' ');
				form_pref(st, sp);
			}
			if (!(*st->source == 'p' && st->precision == 0))
				ft_putstr(st->buf, st->buf_len);
		}
	}
}

void			print_cycle(int sp, int zero, char c)
{
	if (c == ' ')
	{
		while (sp > 0)
		{
			write(1, &c, 1);
			sp--;
		}
	}
	else
	{
		while (zero > 0)
		{
			write(1, &c, 1);
			zero--;	
		}
	}
}

int				form_pref(t_printf *st, int sp)
{
	if (*st->source == 'o')
		{
			write(1, "0", 1);
			st->t_len++;
			sp--;
		}
	if (*st->source == 'x' || *st->source == 'p')
		{
			write(1, "0x", 2);
			st->t_len += 2;
			sp -= 2;
		}
	if (*st->source == 'X')
		{
			write(1, "0X", 2);
			st->t_len += 2;
			sp -= 2;
		}
	return (sp);
}