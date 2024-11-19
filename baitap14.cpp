#include <stdio.h>

int main()
{
	int n,S;
	do
	{
		printf ("Nhap vao mot so nguyen (0<n<=20): "); scanf ("%d",&n);
	}	while (n>20||n<=0);
	int i=1;
	S=0;
	while (i<=n)
	{
		S += i;
		i++;
	}
	printf ("Tong la: %d",S);
	return 0;
}
