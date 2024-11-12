#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include <ctype.h>
#include <string.h>

int	strIs(char *fct, char *model)
{
	int i;

	if (fct[0] == '\0')
		return (0);
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
	printf("%s add[0] = %p\t-> ", msg, (void *)tab);
	while (i < len)
		printf("0x%02X ", p_tab[i++]);
	printf("\n");

}

int	main(int ac, char **av)
{
	char	*fct;
	int 	integer;
	int 	integer2;
	char 	*str;
	char	buff[255];
	
	fct = av[1];
	if (ac > 1)
	{
		if (strIs(fct, "srcs/ft_isalpha.c"))
		{
			integer = av[2][0];
			printf("___\tTEST isalpha\t___\n");
			printf(	"\tisalpha('%c') = %d\n"\
			"\tft_isalpha('%c') = %d\n", \
			integer, isalpha(integer), integer, ft_isalpha(integer));
		}
		if (strIs(fct, "srcs/ft_isdigit.c"))
		{
			integer = av[2][0];
			printf("___\tTEST isdigit\t___\n");
			printf(	"\tisdigit('%c') = %d\n"\
			"\tft_isdigit('%c') = %d\n", \
			integer, isdigit(integer), integer, ft_isdigit(integer));
		}
		if (strIs(fct, "srcs/ft_isalnum.c"))
		{
			integer = av[2][0];
			printf("___\tTEST isalnum\t___\n");
			printf(	"\tisalnum('%c') = %d\n"\
			"\tft_isalnum('%c') = %d\n", \
			integer, isalnum(integer), integer, ft_isalnum(integer));
		}
		if (strIs(fct, "srcs/ft_isascii.c"))
		{
			integer = atoi(av[2]);
			printf("___\tTEST isascii\t___\n");
			printf(	"\tisascii('%c') = %d\n"\
			"\tft_isascii('%c') = %d\n", \
			integer, isascii(integer), integer, ft_isascii(integer));
		}
		if (strIs(fct, "srcs/ft_isprint.c"))
		{
			integer = atoi(av[2]);
			printf("___\tTEST isprint\t___\n");
			printf(	"\tisprint('%c') = %d\n"\
			"\tft_isprint('%c') = %d\n", \
			integer, isprint(integer), integer, ft_isprint(integer));
		}
		if (strIs(fct, "srcs/ft_strlen.c"))
		{
		str = av[2];
			printf("___\tTEST strlen\t___\n");
			printf(	"\tstrlen('%s') = %lu\n"\
			"\tft_strlen('%s') = %lu\n", \
			str, strlen(str), str, ft_strlen(str));
		}
		if (strIs(fct, "srcs/ft_memset.c"))
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
		if (strIs(fct, "srcs/ft_bzero.c"))
		{
			char tabc[10] = "OUAICGREG";
			printf("___\tTEST bzero char tab[10] = %s\t___\n", tabc);
			bzero(tabc, 10);
			printMem(tabc, 10, "bzero :");
			ft_bzero(tabc, 10);
			printMem(tabc, 10, "ft_bzero :");
		}
		if (strIs(fct, "srcs/ft_memcpy.c"))
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
		if (strIs(fct, "srcs/ft_memmove.c"))
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
		if (strIs(fct, "srcs/ft_strlcpy.c"))
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
		if (strIs(fct, "srcs/ft_strlcat.c"))
		{
			str = av[2];
			char fdst[30] = {"______(10)"};
			size_t frtrn;

			printf("Cat argv[2] to dst[30]\n");
			frtrn = ft_strlcat(fdst, str, 30);
			printf("ft_strlcat : dst[30] = %s return %lu\n", fdst, frtrn);
			printMem(fdst, 30, "ft_strlcat dest :");
		}
		if (strIs(fct, "srcs/ft_toupper.c"))
		{
			integer = atoi(av[2]);
			while (integer != 0)
			{
				printf("%c to upper -> %c \n", integer, ft_toupper(integer));
				scanf("%d", &integer);
			}
		}
		if (strIs(fct, "srcs/ft_tolower.c"))
		{
			integer = atoi(av[2]);
			while (integer >= 0)
			{
				printf("%c to lower -> %c \n", integer, ft_tolower(integer));
				scanf("%d", &integer);
			}
		}
		if (strIs(fct, "srcs/ft_tolower.c"))
		{
			integer = atoi(av[2]);
			while (integer >= 0)
			{
				printf("%c to lower -> %c \n", integer, ft_tolower(integer));
				scanf("%d", &integer);
			}
		}
		if (strIs(fct, "srcs/ft_strchr.c"))
		{
			char	tab[30] = "quel character tu veux ?\n";
			printf("SOURCE : %s", tab);
			printMem(tab, 30, "in Memory :");
			integer = 1;
			while (integer >= 0)
			{
				printf("First occurence(%c) here : %p -> %s\n", \
				integer, ft_strchr(tab, integer), ft_strchr(tab, integer));
				scanf("%d", &integer);
			}
		}
		if (strIs(fct, "srcs/ft_strrchr.c"))
		{
			char	tab[30] = "quel character tu veux ?\n";
			printf("SOURCE : %s", tab);
			printMem(tab, 30, "in Memory :");
			integer = 1;
			while (integer >= 0)
			{
				printf("Last occurence(%c) here : %p -> %s\n", \
				integer, ft_strrchr(tab, integer), ft_strrchr(tab, integer));
				scanf("%d", &integer);
			}
		}
		if (strIs(fct, "srcs/ft_strncmp.c"))
		{
			char t1[15] = "la Peche";
			char t2[15] = "la Banane";
			printf("%s\n%s\n-> %d\n", t1, t2, ft_strncmp(t1, t2, 15));
			printf("%s\n%s\n-> %d\n", t1, t1, ft_strncmp(t1, t1, 15));
			char t3[3];
			printf("Test char/char, enter 1 ascii and another (<-100 to exit)\n");
			while (integer >= -100)
			{
				scanf("%d", &integer);
				t3[0] = integer;
				scanf("%d", &integer);
				t3[1] = integer;
				printf("strncmp(%c, %c, 1) = %d\n", \
				t3[0], t3[1], strncmp(&t3[0], &t3[1], 1));
				printf("ft_strncmp(%c, %c, 1) = %d\n", \
				t3[0], t3[1], ft_strncmp(&t3[0], &t3[1], 1));
				printf("memcmp(%c, %c, 1) = %d\n", \
				t3[0], t3[1], memcmp(&t3[0], &t3[1], 1));
			}
		}
		if (strIs(fct, "srcs/ft_memchr.c"))
		{
			char tab[20];
			ft_bzero(tab, 20);
			ft_memset(&tab[5], 16, 10);
			tab[7] = 32;
			tab[10] = 64;
			tab[13] = 32;
			printMem(tab, 20,"Find in this tab :");
			while (integer >= 0)
			{
				printf("Enter [tofind] [size_t n] : ");
				scanf("%d %d", &integer, &integer2);
				char *r = ft_memchr(tab, integer, integer2);
				printf("return = %p that is &tab[%ld]\n", r, r - tab);

			}
		}
		if (strIs(fct, "srcs/ft_memcmp.c"))
		{
			char t1[15] = "la Peche";
			char t2[15] = "la Banane";
			printf("memcmp :\t%s & %s\t-> %d\n", t1, t2, memcmp(t1, t2, 15));
			printf("ft_memcmp :\t%s & %s\t-> %d\n", t1, t2, ft_memcmp(t1, t2, 15));
			printf("memcmp :\t%s & %s\t-> %d\n", t1, t1, memcmp(t1, t1, 15));
			printf("ft_memcmp :\t%s & %s\t-> %d\n", t1, t1, ft_memcmp(t1, t1, 15));
			char t3[3];
			printf("Test char/char, enter 1 ascii and another (<-100 to exit)\n");
			while (integer >= -100)
			{
				scanf("%d", &integer);
				t3[0] = integer;
				scanf("%d", &integer);
				t3[1] = integer;
				printf("memcmp(%c, %c, 1) = %d\n", \
				t3[0], t3[1], memcmp(&t3[0], &t3[1], 1));
				printf("ft_memcmp(%c, %c, 1) = %d\n", \
				t3[0], t3[1], ft_memcmp(&t3[0], &t3[1], 1));
			}
		}
		if (strIs(fct, "srcs/ft_strnstr.c"))
		{
			char t1[] = "Provide a string to find into this sentence or '0'"\
					   "to search an empty string and "\
					   " a length of the string to find('X' to quit)\n";
			char *fres;
			while (t1[0] != 'X')
			{
				printf("%s", t1);
				scanf("%s %d", buff, &integer);
				if (buff[0] == '0')
				{
					char empty = '\0';
					fres = ft_strnstr(t1, &empty, integer);
				}
				else
					fres = ft_strnstr(t1, buff, integer);
				printf("ft_strnstr : %p\t-> %s\n", (void *)fres, fres);
			}
		}
		if (strIs(fct, "srcs/ft_atoi.c"))
		{
				char t1[] = "\t\t456";
				printf("   atoi(%s)\t-> %d\nft_atoi(%s)\t-> %d\n", \
						t1, atoi(t1), t1, ft_atoi(t1));
				char t3[] = "  21474_83648  ";
				printf("   atoi(%s)\t-> %d\nft_atoi(%s)\t-> %d\n", \
						t3, atoi(t3), t3, ft_atoi(t3));
				char t2[] = "\t\r\n\v\f\r   -2147483648";
				printf("   atoi(%s)\t-> %d\nft_atoi(%s)\t-> %d\n", \
						t2, atoi(t2), t2, ft_atoi(t2));

		}
		if (strIs(fct, "srcs/ft_calloc.c"))
		{
			void	*res;
			long 	nmemb = 2;

			printf("TEST 1 : nmemb = %ld sizeof(char)\n", nmemb);
			res	= calloc(nmemb, sizeof(char));
			printMem(res, nmemb * sizeof(char), "   calloc");
			printf("free(%p)\n", res);
			free(res);
			res	= ft_calloc(nmemb, sizeof(char));
			printMem(res, nmemb * sizeof(char), "ft_calloc");
			printf("free(%p)\n", res);
			free(res);

			nmemb = 4294967295;
			printf("TEST 2 : nmemb = %ld sizeof(int)\n", nmemb);
			res	= calloc(nmemb, sizeof(char));
			printMem(res, 16, "   calloc (16firsts)");
			printf("free(%p)\n", res);
			free(res);
			//res	= ft_calloc(nmemb, sizeof(int));
			//printMem(res, 16, "ft_calloc (16firsts)");
			//printf("free(%p)\n", res);
			//free(res);

			nmemb = 0;
			printf("TEST 3 : nmemb = %ld sizeof(int)\n", nmemb);
			res	= calloc(nmemb, sizeof(int));
			printMem(res, nmemb * sizeof(int), "   calloc");
			printf("free(%p)\n", res);
			free(res);
			res	= ft_calloc(nmemb, sizeof(int));
			printMem(res, nmemb * sizeof(int), "ft_calloc");
			printf("free(%p)\n", res);
			free(res);
		}
	}
}
