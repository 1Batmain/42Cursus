#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "ft_printf.h"

int	main()
{
//	ft_printf("\n\n");
	int ftp = ft_printf(NULL);
	printf("ftp = %d\n", ftp);
//	int fftp =ft_printf("FT :___%.s___\n", "168");
//	int pp =   	 printf("OG :___%.s___\n", "168");
//	printf("ftp = %d\np = %d\n", fftp, pp);
	return (0);
}
