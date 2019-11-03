/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinc <squinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:07:45 by squinc            #+#    #+#             */
/*   Updated: 2019/11/03 20:29:14 by squinc           ###   ########.fr       */
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
	if (*st->source == 'h' && *(st + 1)->source == 'h')
	{
		st->size = 1;
		st->source++;
	}
	else if (*st->source == 'l' && *(st + 1)->source == 'l')
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

void	ft_parse(t_printf *st, char *buf)
{
	while (!is_conv(*st->source))
	{
		if (*st->source == '%')
		{	
			*buf = '%';
			buf++;		
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
			if (is_digit(*(++st->source)))
				{
					st->precision = ft_atoi(st->source);
					while(is_digit(*st->source))
						st->source++;
					st->source--;
				}
			else
				st->precision = 0;
		}
		else if (is_len_fl(*st->source))
			parse_length_flags(st);
		st->source++;	
	}
	define_conv(st);
}

void		define_conv(t_printf *st)
{
	
	if (*st->source == 'd' || *st->source == 'i')
		cr_int(st);
	if (*st->source == 'u'|| *st->source == 'o' || *st->source == 'x')
		cr_unsigned(st);
	//if (*st->source == 'f' || *st->source == 'F')
		//handle_double(st, st->buf);

}

void		cr_unsigned(t_printf *st)
{
	int base;
	
	base = (*st->source == 'x' || *st->source == 'X') ? 16 : 0;
	base = (*st->source == 'o') ? 8 : base;
	base = (*st->source == 'u') ? 10 : base;
	if (st->size == 1)
		st->buf = pf_uitoa(va_arg(st->ap, unsigned int), st, base);
	else if (st->size == 2)
		st->buf = pf_uitoa(va_arg(st->ap, unsigned int), st, base);
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
	{
		st->buf = pf_itoa(va_arg(st->ap, int), st);
	}
	else if (st->size == 2)
		st->buf = pf_itoa(va_arg(st->ap, int), st);
	else if (st->size == 3)
		st->buf = pf_itoa(va_arg(st->ap, long int), st);
	else if (st->size == 4)
		st->buf = pf_itoa(va_arg(st->ap, long long int), st);
	else
		st->buf = pf_itoa(va_arg(st->ap, int), st);
	cr_output(st);
}

void			cr_output(t_printf *st)
{
	int sp;
	int zero;
	
	sp = 0;
	zero = 0;
	if (st->space_sign && !st->plus_sign)
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
	print_str(st, sp, zero);
}

void			print_str(t_printf *st, int sp, int zero)
{
	if (st->plus_sign && (*st->source == 'd' || *st->source == 'i'))
	{
		if (zero > 0)
		{
			write(1, "+", 1);
			print_cycle(sp, zero, '0');
		}
		else
		{
			print_cycle(sp, zero, ' ');
			write(1, "+", 1);
		}
		ft_putstr(st->buf);
	}
	else if (st->l_align)
	{
		if (st->space_sign)
			write(1," ",1);
		ft_putstr(st->buf);
		print_cycle(sp, zero, ' ');
	}
	else
	{
		if (sp == 1)
			write(1, " ", 1);
		else if (zero > 0)
			print_cycle(sp, zero, '0');
		else if (sp > 0)
			print_cycle(sp, zero, ' ');
		ft_putstr(st->buf);
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