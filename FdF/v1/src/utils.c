#include "fdf.h"

void	swap(double *a, double *b)
{
	double c;
	c = a[0];
	a[0] = b[0];
	b[0] = c;
	c = a[1];
	a[1] = b[1];
	b[1] = c;
}
