#include <stdio.h>

int main()
{
	//nhap gia tri
	int a; float b; char c;
	printf ("Nhap so nguyen: "); scanf ("%d",&a);
	printf ("Nhap so thuc: "); scanf ("%f",&b);
	printf ("Nhap ki tu: "); fflush(stdin); scanf ("%c",&c);
	//xuat
	printf ("\nSo nguyen: %d\n",a);
	printf ("So thuc: %.1f\n",b);
	printf ("Ky tu: '%c'\n",c);
	return 0;
}
