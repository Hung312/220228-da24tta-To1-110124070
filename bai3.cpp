#include <stdio.h>

int main()
{
	int n,du,S;
	printf ("Nhap vao mot so nguyen "); scanf ("%d",&n);
	S=0;
	do
	{
		du= n%10;
		S += du;
		n= n/10;
	} while (n>0);
	printf ("Tong cac chu so: %d",S);
	return 0;
}
