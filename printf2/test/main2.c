#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "ft_printf.h"

int	main()
{

	ft_printf("%%d = '%#x'\n",5456);
	printf("%%d = '%.2s'\n", "SIIISI");
	return (0);
}
