#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"





int main ()
{
	/*printf("% 010d\n",3200);
	
	printf("%010.5d\n",3200);
	printf("%010.3d\n",32);
	printf("%-10.3d\n",32);
	
	*/
	//printf("%010.6d\n",32);
	t_printf *s = malloc(sizeof(t_printf));
	s->precision = -1;
	s->fill_zero = 1;
	s->width = 10;
	s->l_align = 0;
	s->buf = pf_itoa(32, s);
	s->plus_sign = 1;
	cr_output(s);
	//printf("%jd\n",18446744073709551620);
	//printf("%s\n",pf_itoa(3200, s));
	//printf("% 06dl\n",3200);
	//long int a = atoi("2147483649");
	//char *s = ft_itoa(1844674407370);
	//printf("%lu", 1844674407370);
}
