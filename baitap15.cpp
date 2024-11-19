#include <stdio.h>

int main()
{
	int n,S=0,du;
	do
	{
		printf ("Nhap vao mot so nguyen (0<n<10000): "); scanf ("%d",&n);
	}	while (n>=10000||n<=0);
	//tinh
	do
	{
		du= n%10;
		n = n/10;
		S+=du;
		du=0; 
	} while (n>0);
	printf ("Tong cac chu so cua %d= %d",n,S);
	return 0;
}
