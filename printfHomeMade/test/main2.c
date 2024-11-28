#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int	var = 0;

	ft_printf(	"HELLOOO\n"
				"%%c = %c\n"
				"%%s = %s\n"
				"%%20d = %20d\n"
				"%%i = %i\n"
				"%%-20uTEM = %-20uTEM\n"
				"%%x = %x\n"
				"%%X = %X\n"
				"%%p = %p\n"
				, 52, 
				"MON GROS",
				-2147483647,
				0xff,
				0xffffffff,
				0xffffffff,
				0xffffffff,
				&var
				);
	printf(	"HELLOOO\n"
				"%%c = %c\n"
				"%%s = %s\n"
				"%%5d = %5d\n"
				"%%i = %i\n"
				"%%u = %u\n"
				"%%x = %x\n"
				"%%X = %X\n"
				"%%p = %p\n"
				, 52, 
				"MON GROS",
				-2147483647,
				0xff,
				0xffffffff,
				0xffffffff,
				0xffffffff,
				&var
				);
}
