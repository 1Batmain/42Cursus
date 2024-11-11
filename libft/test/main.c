#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include <ctype.h>
#include <string.h>

int	fctIs(char *fct, char *model)
{
	int i;

	i = 0;
	while (fct[i] && fct[i] == model[i])
		i++;
	if (fct[i] == '\0')
		return (1);
	return (0);
}

void	printMem(void *tab, size_t len, char *msg)
{
	unsigned char	*p_tab = (unsigned char *) tab;
	size_t			i;

	i = 0;
	printf("%s\n", msg);
	while (i < len)
		printf("%02X ", p_tab[i++]);
	printf("\n");

}

int	main(int ac, char **av)
{
	char	*fct;
	int integer;
	char *str;
	
	fct = av[1];
	if (ac > 1)
	{
		if (fctIs(fct, "srcs/ft_isalpha.c"))
		{
			integer = av[2][0];
			printf("___\tTEST isalpha\t___\n");
			printf(	"\tisalpha('%c') = %d\n"\
			"\tft_isalpha('%c') = %d\n", \
			integer, isalpha(integer), integer, ft_isalpha(integer));
		}
		if (fctIs(fct, "srcs/ft_isdigit.c"))
		{
			integer = av[2][0];
			printf("___\tTEST isdigit\t___\n");
			printf(	"\tisdigit('%c') = %d\n"\
			"\tft_isdigit('%c') = %d\n", \
			integer, isdigit(integer), integer, ft_isdigit(integer));
		}
		if (fctIs(fct, "srcs/ft_isalnum.c"))
		{
			integer = av[2][0];
			printf("___\tTEST isalnum\t___\n");
			printf(	"\tisalnum('%c') = %d\n"\
			"\tft_isalnum('%c') = %d\n", \
			integer, isalnum(integer), integer, ft_isalnum(integer));
		}
		if (fctIs(fct, "srcs/ft_isascii.c"))
		{
			integer = atoi(av[2]);
			printf("___\tTEST isascii\t___\n");
			printf(	"\tisascii('%c') = %d\n"\
			"\tft_isascii('%c') = %d\n", \
			integer, isascii(integer), integer, ft_isascii(integer));
		}
		if (fctIs(fct, "srcs/ft_isprint.c"))
		{
			integer = atoi(av[2]);
			printf("___\tTEST isprint\t___\n");
			printf(	"\tisprint('%c') = %d\n"\
			"\tft_isprint('%c') = %d\n", \
			integer, isprint(integer), integer, ft_isprint(integer));
		}
		if (fctIs(fct, "srcs/ft_strlen.c"))
		{
		str = av[2];
			printf("___\tTEST strlen\t___\n");
			printf(	"\tstrlen('%s') = %lu\n"\
			"\tft_strlen('%s') = %lu\n", \
			str, strlen(str), str, ft_strlen(str));
		}
		if (fctIs(fct, "srcs/ft_memset.c"))
		{
			// ./[..] ft_memset.c [int to fill tab] [base of int]
			int	base = atoi(av[3]);
			integer = strtol(av[2], NULL, base);
			char tabc[10] = "OUAICGREG";
			printf("___\tTEST memset char tab[10] = %s\t___\n", tabc);
			memset(tabc, integer, 10);
			printMem(tabc, 10, "memset :");
			ft_memset(tabc, integer, 10);
			printMem(tabc, 10, "ft_memset :");
		}
		if (fctIs(fct, "srcs/ft_bzero.c"))
		{
			char tabc[10] = "OUAICGREG";
			printf("___\tTEST bzero char tab[10] = %s\t___\n", tabc);
			bzero(tabc, 10);
			printMem(tabc, 10, "bzero :");
			ft_bzero(tabc, 10);
			printMem(tabc, 10, "ft_bzero :");
		}
		if (fctIs(fct, "srcs/ft_memcpy.c"))
		{
			char	tabcdst1[10];
			char	tabcdst2[10];
			char	tabcsrc[10];

			int		tabisrc[10] = \
				{0, 16, 32, 64, 128, 255, \
					1024, 1024, 2048, 2048};
			int		tabidst1[10];
			int		tabidst2[10];

			memset(tabcsrc, 0xFF, 10);
			memset(tabcdst1, 0, 10);
			memset(tabcdst2, 0, 10);
			memset(tabidst1, 0, 10 * sizeof(int));
			memset(tabidst2, 0, 10 * sizeof(int));

			printMem(tabcsrc, 10, "OG tabcsrc :");
			printMem(tabisrc, 10 * sizeof(int), "OG tabisrc :");
			printf("___\tTEST memcpy\t___\n");
			printMem(tabcdst1, 10, "OG tabcdst :");
			printMem(tabidst1, 10 * sizeof(int), "OG tabidst :");
			memcpy(tabcdst1, tabcsrc, 10);
			memcpy(tabidst1, tabisrc, 10 * sizeof(int));
			printMem(tabcdst1, 10, "Final tabcdst :");
			printMem(tabidst1, 10 * sizeof(int), "Final tabidst :");
			printf("___\tTEST ft_memcpy\t___\n");
			printMem(tabcdst2, 10, "OG tabcdst :");
			printMem(tabidst2, 10 * sizeof(int), "OG tabidst :");
			ft_memcpy(tabcdst2, tabcsrc, 10);
			ft_memcpy(tabidst2, tabisrc, 10 * sizeof(int));
			printMem(tabcdst2, 10, "Final tabcdst :");
			printMem(tabidst2, 10 * sizeof(int), "Final tabidst :");
		}
		if (fctIs(fct, "srcs/ft_memmove.c"))
		{
			char	src[20];
			char	fsrc[20];
			char	*dst1 = &src[0];
			char	*fdst1 = &fsrc[0];
			char	*dst2 = &src[5];
			char	*fdst2 = &fsrc[5];
			char 	dst3[20];
			char 	fdst3[20];

			ft_bzero(src, 20);
			ft_memset(&src[5], 255, 5);
			ft_bzero(fsrc, 20);
			ft_memset(&fsrc[5], 255, 5);
			printMem(src, 20, "Source tab");
			printf(	"---------------------------------------------------------\n"\
					"copy 1 bytes from src[5] on overlapping tab dst = &src[0]\n"\
					"---------------------------------------------------------\n");
			memmove(dst1, &src[5], 1);
			ft_memmove(fdst1, &fsrc[5], 1);
			printMem(src, 20, "memmove :");
			printMem(fsrc, 20, "ft_memmove :");
			printf(	"---------------------------------------------------------\n"\
					"copy 15bytes from src[0] on overlapping tab dst = &src[5]\n"\
					"---------------------------------------------------------\n");
			memmove(dst2, &src[0], 15);
			ft_memmove(fdst2, &fsrc[0], 15);
			printMem(src, 20, "memmove :");
			printMem(fsrc, 20, "ft_memmove :");
			printf(	"---------------------------------------------------------\n"\
					"copy 20bytes from src[0] to Non overlapping tab \n"\
					"---------------------------------------------------------\n");
			memmove(dst3, &src[0], 20);
			ft_memmove(fdst3, &fsrc[0], 20);
			printMem(dst3, 20, "memmove :");
			printMem(fdst3, 20, "ft_memmove :");
		}
		if (fctIs(fct, "srcs/ft_strlcpy.c"))
		{
			str = av[2];
			char dst[20];
			char fdst[20];
			size_t rtrn;

			printf("Copy argv[2] to dst[20]\n");
			strncpy(dst, str, 20);
			rtrn = ft_strlcpy(fdst, str, 20);
			printf("strncpy : dst[20] = %s\n", dst);
			printf("ft_strlcpy : dst[20] = %s\n return %lu\n", fdst, rtrn);
			printMem(str, 20, "av[2] (20 bytes):");
			printMem(dst, 20, "strncpy dest :");
			printMem(fdst, 20, "ft_strlcpy dest :");
		}
	}
}

