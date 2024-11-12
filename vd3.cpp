#include <stdio.h>

int main()
{
	int a,b;
	printf ("Nhap 2 so nguyen: "); scanf ("%d %d",&a,&b);
	if (a>b)
		printf ("so be hon la %d",b);
	else
		printf ("so be hon la %d",a);
	return 0;
}
