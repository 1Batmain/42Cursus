#include "stdio.h"
#include "pthread.h"

void call(void *arg)
{
	char *str = (char *)arg;
	printf("%s", str);
}
int main()
{
	pthread_t one;
	pthread_attr_t	attr;

	pthread_create(&one, &attr, &call, "SIIISI");
}
