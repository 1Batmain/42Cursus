#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int	ft(char *s)
{
	int l;
	s = 0;
	if (!s)
		return (0);
	while (s[l])
		l++;
	return (l);
}
int	main(void)
{
	printf("%d", ft(NULL));	
	return (0);
}
