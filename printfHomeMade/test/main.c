#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "printf.h"

#define BUFFER	42

char	**ft_emptyTest()
{
		 char	*dataset[]
}

void	ft_free(char **res)
{
	while (*res)
		free(*res++)
	free(res);
}

void	check(char **res, nb)
{
	char	real;
	char	myfunc;
	size_t	i;

	i = 0;
	while (real[i] && res[i])
	{
		real = res[i];
		myfunc = res[i+1];
		if (!ft_memcmp(real, myfunc, BUFFER))
			printf("%d.[OK] ")
		else 
			printf(
					" [KO] \n"
					"Expected 	: '%s'\n"
					"Yours		: '%s\n'",
					i, real, myfunc
					);
		i++;
	}
	ft_free(res);
}
void 	test(char	*test,(char **)(*f)(void))
{
	static int nb;
	nb++;
	printf(
			"==TEST %d== (%s)\n"
			, nb, test);
	check(f, nb);
}

int	main(int ac, char **av)
{
	if (ac != 0)
	{
		test("empty", ft_emptyTest);	
	}
	return (0);
}
