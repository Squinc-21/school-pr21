#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"



static	int				check_tab(char c)
{
	return (c == '\n' || c == '\t' || c == ' '
			|| c == '\v' || c == '\f' || c == '\r');
}

int						ft_atoi(char *str)
{
	long int	q;
	int			i;
	int			n;

	q = 0;
	i = 0;
	n = 1;
	while (check_tab(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i += 1;
		n = (str[i - 1] == '-') ? n * (-1) : n;
	}
	while (str[i] >= '0' && (str[i] <= '9'))
	{
		q = q * 10 + (str[i] - '0');
		if (q < 0 && n == 1)
			return (-1);
		if (q < 0 && n == -1)
			return (0);
		i = i + 1;
	}
	return (q * n);
}

int main ()
{
	/*printf("% 010d\n",3200);
	
	printf("%010.5d\n",3200);
	printf("%010.3d\n",32);
	printf("%-10.3d\n",32);
	
	*/
	//printf("%010.6d\n",32);
	/*t_printf *s = malloc(sizeof(t_printf));
	s->precision = 5;
	s->fill_zero = 0;
	s->width = 10;
	s->l_align = 0;
	s->buf = pf_itoa(32, s);
	//printf("%s", s->buf);
	s->plus_sign = 0;
	cr_output(s);*/
	//printf("%jd\n",18446744073709551620);
	//printf("%s\n",pf_itoa(3200, s));
	//printf("% 06dl\n",3200);
	//long int a = atoi("2147483649");
	//char *s = ft_itoa(1844674407370);
	//printf("%lu", 1844674407370);
	ft_printf("aaaa %d%-10.4d\n",3,4);
	printf("aaaa %d%-10.4d",3,4);
}
