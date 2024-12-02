#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "ft_printf.h"

int	main()
{
	ft_printf("\n\n");
	int b = 0xfaf;
	int ftp = ft_printf("FT :__%+030d___\n", b);
	int p = 	 printf("OG :__%+030d___\n", b);
	printf("ftp = %d\np = %d\n", ftp, p);
//	int fftp =ft_printf("FT :___%.s___\n", "168");
//	int pp =   	 printf("OG :___%.s___\n", "168");
//	printf("ftp = %d\np = %d\n", fftp, pp);
	return (0);
}
