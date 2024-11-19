#include <stdio.h>

int main()
{
	int n;
	do
	{
		printf ("Nhap vao mot so nguyen (0<n<10): "); scanf ("%d",&n);
	}	while (n>=10||n<=0);
	int i=1;
	while (i<=n)
	{
		printf ("%d",i);
		i++;
	}
	return 0;
}
