#include <stdio.h>

int main()
{
	int n;
	do
	{
	printf ("Nhap vao so nguyen: "); scanf ("%d",&n);
	} while (n>7 || n<=0);
	switch (n)
	{
		case 1: printf ("Chu nhat"); break;
		case 2: printf ("Thu hai"); break;
		case 3: printf ("Thu ba"); break;
		case 4: printf ("Thu tu"); break;
		case 5: printf ("Thu nam"); break;
		case 6: printf ("Thu sau"); break;
		case 7: printf ("Thu bay"); break;
	}
	return 0;
}
