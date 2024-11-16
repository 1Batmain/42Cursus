#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include <ctype.h>
#include <string.h>

static char ft_capevenidx(unsigned int idx, char c)
{
	if(idx % 2 == 0 && ft_isalpha(c))
		return (ft_toupper(c));
	return (c);
}

static void *ft_capevenidxvoid(void *vc)
{
	char 	*c = (char *)vc;
	unsigned int idx = 0;
	while (c[idx])
	{
		if(idx % 2 == 0 && ft_isalpha(c[idx]))
			c[idx] = (ft_toupper(c[idx]));
		idx++;
	}
	return (c);
}
static void ft_deletestr(void * str)
{
	str = str + 0;
	return ;
}

static char ft_capevenidxinplace(unsigned int idx, char c)
{
	if(idx % 2 == 0 && ft_isalpha(c))
		return (ft_toupper(c));
	return (c);
}

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
	return ;

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
			char t4[] = "AAAAAAAAAA";
			printf("%s\n%s\n-> %d\n", t1, t2, ft_strncmp(t1, t2, 15));
			printf("%s\n%s\n-> %d\n", t1, t1, ft_strncmp(t1, t1, 15));
			printf("%s\n%s\n-> %d\n", &t4[4], t4, ft_strncmp(&t4[4], t4, 6));
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
			char t1[] = {-128, 0, 127, 0};
			char t1cpy[] = {-128, 0, 127, 0};
			printf("TEST 1: %d\nvrai fct : %d\n", ft_memcmp(t1, t1cpy, 4), memcmp(t1, t1cpy, 4));
			//char t1[15] = "la Peche";
			//char t2[15] = "la Banane";
			//printf("memcmp :\t%s & %s\t-> %d\n", t1, t2, memcmp(t1, t2, 15));
			//printf("ft_memcmp :\t%s & %s\t-> %d\n", t1, t2, ft_memcmp(t1, t2, 15));
			//printf("memcmp :\t%s & %s\t-> %d\n", t1, t1, memcmp(t1, t1, 15));
			//printf("ft_memcmp :\t%s & %s\t-> %d\n", t1, t1, ft_memcmp(t1, t1, 15));
			//char t3[3];
			//printf("Test char/char, enter 1 ascii and another (<-100 to exit)\n");
			//while (integer >= -100)
			//{
			//	scanf("%d", &integer);
			//	t3[0] = integer;
			//	scanf("%d", &integer);
			//	t3[1] = integer;
			//	printf("memcmp(%c, %c, 1) = %d\n", \
			//	t3[0], t3[1], memcmp(&t3[0], &t3[1], 1));
			//	printf("ft_memcmp(%c, %c, 1) = %d\n", \
			//	t3[0], t3[1], ft_memcmp(&t3[0], &t3[1], 1));
			//}
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
				char t4[] = "\t\r\n\v\f\r   -0  ";
				printf("   atoi(%s)\t-> %d\nft_atoi(%s)\t-> %d\n", \
						t4, atoi(t4), t4, ft_atoi(t4));

		}
		if (strIs(fct, "srcs/ft_calloc.c"))
		{
			void	*res;
			void	*fres;
			long 	nmemb = 2;

			printf("TEST 1 : nmemb = %ld sizeof(char)\n", nmemb);
			res	= calloc(nmemb, sizeof(char));
			printMem(res, nmemb * sizeof(char), "   calloc");
			fres	= ft_calloc(nmemb, sizeof(char));
			printMem(res, nmemb * sizeof(char), "ft_calloc");
			printf("free(%p)\n", res);
			free(res);
			printf("free(%p)\n", fres);
			free(fres);

			nmemb = 4294967295;
			printf("TEST 2 : nmemb = %ld sizeof(char)\n", nmemb);
			res	= calloc(nmemb, sizeof(char));
			printMem(res, 16, "   calloc (16firsts)");
			fres	= ft_calloc(nmemb, sizeof(char));
			printMem(res, 16, "ft_calloc (16firsts)");
			printf("free(%p)\n", res);
			free(res);
			printf("free(%p)\n", fres);
			free(fres);

			nmemb = 0;
			printf("TEST 3 : nmemb = %ld sizeof(int)\n", nmemb);
			res	= calloc(nmemb, sizeof(int));
			printMem(res, nmemb * sizeof(int), "   calloc");
			fres	= ft_calloc(nmemb, sizeof(int));
			printMem(res, nmemb * sizeof(int), "ft_calloc");
			printf("free(%p)\n", res);
			free(res);
			printf("free(%p)\n", fres);
			free(fres);

			//nmemb = -10;
			//printf("TEST 4 : nmemb = %ld sizeof(int)\n", nmemb);
			//res	= calloc(nmemb, sizeof(int));
			//printMem(res, nmemb * sizeof(int), "   calloc");
			//printf("free(%p)\n", res);
			//free(res);
			//res	= ft_calloc(nmemb, sizeof(int));
			//printMem(res, nmemb * sizeof(int), "ft_calloc");
			//printf("free(%p)\n", res);
			//free(res);
		}
		if (strIs(fct, "srcs/ft_strdup.c"))
		{
			char *res;
			printf("Test 1 : empty string \n");
			res = ft_strdup("");
			printMem(res, 0, "10 first bytes");
			while (buff[0] != 'Q')
			{
				printf("\nEnter a string to duplicate ('Q' to quit)\n");
				scanf("%s", buff);
				res = ft_strdup(buff);
				printf("Original : %s\nDuplicate : %s'%d'\n", buff, res,\
						*(res + ft_strlen(res)));

			}
		}
		if (strIs(fct, "srcs/ft_substr.c"))
		{
			char t1[] = "This is a string that you can search into";
			char *res;
			printf("%s\n", t1);
			unsigned int	start, len;
			start = len = 1;
			while (start + len)
			{
				printf("Enter startIdx and len :");
				scanf("%u %u", &start, &len);
				res = ft_substr(t1, start, len);
				printf("Resulting : %s\n", res);
			}
		}
		if (strIs(fct, "srcs/ft_strjoin.c"))
		{
			char t1[] = "garde";
			char t2[] = "la PECHE";
			char *res = ft_strjoin(t1, t2);
			printf("TEST 1 : '%s' & '%s'\n"\
					"(%p) -> %s\n", t1, t2, res, res);
			char t3[] = "";
			char t4[] = "la PECHE";
			res = ft_strjoin(t3, t4);
			printf("TEST 4 : '%s' & '%s'\n"\
					"(%p)-> %s\n", t3, t4, res, res);
			char t5[] = "";
			char t6[] = "";
			res = ft_strjoin(t5, t6);
			printf("TEST 3 : '%s' & '%s'\n"\
					"(%p)-> %s\n", t5, t6, res, res);
			res = ft_strjoin(NULL, t6);
			printf("TEST 4 : NULL & '%s'\n"\
					"(%p)-> %s\n", t6, res, res);
		}
		if (strIs(fct, "srcs/ft_strtrim.c"))
		{
			char t1[] = "0123   YES   7654";
			char t2[] = "0123456789 ";
			char *res = ft_strtrim(t1, t2);
			printf("TEST 1 :\n\ts1 : '%s'\n\tset : '%s'\n"\
					"Result : (%p) -> '%s'\n", t1, t2, res, res);
			char t3[] = "";
			char t4[] = "0123456789 ";
			res = ft_strtrim(t3, t4);
			printf("TEST 3 :\n\ts3 : '%s'\n\tset : '%s'\n"\
					"Result : (%p) -> '%s'\n", t3, t4, res, res);
		}
		if (strIs(fct, "srcs/ft_split.c"))
		{
			char	**res;
			char	t1[] = "I am the one suppose to be splitted out ??";
			char 	set1 = ' ';
			int	i;
			printf("TEST 1 : \n\ts1 : '%s'\n\tset : '%c'\n", t1, set1);
			res = ft_split(t1, set1);
			i = -1;
			while (res[++i])
			{
				printf("(%p)-> '%s'\n",res, res[i]);
			}
			printf("(%p)-> '%s'\n",res, res[i]);
			char	t2[] = "  I am the one suppose  ??  ";
			char 	set2 = ' ';
			printf("TEST 2 : \n\ts2 : '%s'\n\tset : '%c'\n", t2, set2);
			res = ft_split(t2, set2);
			i = -1;
			while (res[++i])
				printf("(%p)-> '%s'\n",res, res[i]);
			printf("(%p)-> '%s'\n",res, res[i]);
		}
		if (strIs(fct, "srcs/ft_itoa.c"))
		{
			char	*res;
			printf("Enter an int to convert in string (-333 to quit): \n");
			while (integer != -333)
			{
				printf(" -> ");
				scanf("%d", &integer);
				res = ft_itoa(integer);
				printf("str(%d) : '%s'\n", integer, res);	
				free(res);
			}
		}
		if (strIs(fct, "srcs/ft_strmapi.c"))
		{
			char t1[] = "applying ft_capitalize even indexed characters";
			char *res = ft_strmapi(t1, &ft_capevenidx);
			printf("TEST 1 : '%s'\n -> '%s'\n", t1, res);
		}
		if (strIs(fct, "srcs/ft_striteri.c"))
		{
			char t1[] = "applying ft_capitalize even indexed characters";
			char *res = ft_strmapi(t1, &ft_capevenidxinplace);
			printf("TEST 1 : '%s'\n -> '%s'\n", t1, res);
		}
		if (strIs(fct, "srcs/ft_putchar_fd.c"))
		{
			int fd = open("test.txt", O_WRONLY);
			char t1[] = "Test, my name is test";
			int i = 0;
			while (t1[i])
				ft_putchar_fd(t1[i++], fd);
			printf("Open test.txt to check\n");
		}
		if (strIs(fct, "srcs/ft_putendl_fd.c"))
		{
			int fd = open("test.txt", O_WRONLY);
			char t1[] = "Test, my name is test";
			ft_putendl_fd(t1, fd);
			printf("Open test.txt to check\n");
		}
		if (strIs(fct, "srcs/ft_putnbr_fd.c"))
		{
			int fd = open("test.txt", O_WRONLY);
			scanf("%d", &integer);
			ft_putnbr_fd(integer, fd);
			printf("Open test.txt to check\n");
		}
		if (strIs(fct, "srcs/ft_lstnew.c"))
		{
			char t1[] = "SISIII";
			t_list *l;
			l = ft_lstnew(t1);
			printf("New list created (%p): \n"\
				"l.content(%p) = '%s'\n"\
				"l.next(%p)\n", l, l->content, (char *)l->content, l->next);
		}
		if (strIs(fct, "srcs/ft_lstadd_front.c"))
		{
			char t1[] = "OOHEEE";
			t_list *l1;
			l1 = ft_lstnew(t1);
			printf("New list created (%p): \n"\
				"l1.content(%p) = '%s'\n"\
				"l1.next(%p)\n", l1, l1->content, (char *)l1->content, l1->next);
			char t2[] = "deplus";
			t_list *l2;
			l2 = ft_lstnew(t2);
			printf("New list created (%p): \n"\
				"l2.content(%p) = '%s'\n"\
				"l2.next(%p)\n", l2, l2->content, (char *)l2->content, l2->next);
			ft_lstadd_front(&l1, l2);
			printf("'l1 :%s ->next: %s'\n", (char *)l1->content, (char *)l1->next->content);
		}
		if (strIs(fct, "srcs/ft_lstsize.c"))
		{
			char t1[] = "OOHEEE";
			t_list *l1;
			l1 = ft_lstnew(t1);
			printf("New list created (%p): \n"\
				"l1.content(%p) = '%s'\n"\
				"l1.next(%p)\n", l1, l1->content, (char *)l1->content, l1->next);
			printf("List size : %lu\n", ft_lstsize(l1));
			char t2[] = "deplus";
			t_list *l2;
			l2 = ft_lstnew(t2);
			printf("New list created (%p): \n"\
				"l2.content(%p) = '%s'\n"\
				"l2.next(%p)\n", l2, l2->content, (char *)l2->content, l2->next);
			ft_lstadd_front(&l1, l2);
			printf("'l1 :%s ->next: %s'\n", (char *)l1->content, (char *)l1->next->content);
			printf("List size : %lu\n", ft_lstsize(l1));
			printf("List size list:(null): %lu\n", ft_lstsize(l1->next->next));
		}
		if (strIs(fct, "srcs/ft_lstlast.c"))
		{
			char t1[] = "OOHEEE";
			t_list *l1;
			l1 = ft_lstnew(t1);
			printf("New list created (%p): \n"\
				"l1.content(%p) = '%s'\n"\
				"l1.next(%p)\n", l1, l1->content, (char *)l1->content, l1->next);
			printf("List size : %lu\n", ft_lstsize(l1));
			char t2[] = "deplus";
			t_list *l2;
			l2 = ft_lstnew(t2);
			printf("New list created (%p): \n"\
				"l2.content(%p) = '%s'\n"\
				"l2.next(%p)\n", l2, l2->content, (char *)l2->content, l2->next);
			ft_lstadd_front(&l1, l2);
			printf("'l1 :%s ->next: %s'\n", (char *)l1->content, (char *)l1->next->content);
			printf("Last : %s\n", (char *)ft_lstlast(l1)->content);
		}
		if (strIs(fct, "srcs/ft_lstadd_back.c"))
		{
			char t1[] = "OOHEEE";
			t_list *l1;
			l1 = ft_lstnew(t1);
			printf("New list created (%p): \n"\
				"l1.content(%p) = '%s'\n"\
				"l1.next(%p)\n", l1, l1->content, (char *)l1->content, l1->next);
			char t2[] = "deplus";
			t_list *l2;
			l2 = ft_lstnew(t2);
			printf("New list created (%p): \n"\
				"l2.content(%p) = '%s'\n"\
				"l2.next(%p)\n", l2, l2->content, (char *)l2->content, l2->next);
			ft_lstadd_back(&l1, l2);
			printf("'l1 :%s ->next: %s'\n", (char *)l1->content, (char *)l1->next->content);
		}
		if (strIs(fct, "srcs/ft_lstmap.c"))
		{
			char t1[] = "Cbonoupas";
			t_list	*lst1 = ft_lstnew(t1);
			char t2[] = "HEOO";
			t_list	*lst2 = ft_lstnew(t2);
			ft_lstadd_front(&lst1, lst2);
			lst1 = ft_lstmap(lst1, &ft_capevenidxvoid, &ft_deletestr);
			printf("%s %s", (char *)lst1->content, (char *)lst1->next->content);
		}
	}
}
