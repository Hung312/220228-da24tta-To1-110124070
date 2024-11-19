#include <stdio.h>

void cauA(int n);
void cauB(int n);
void cauC(int n); int kiemtrasoNguyenTo(int m);
void cauD(int n);
void cauE(int n);
void cauF(int n);


int main()
{
	int n;
	do
	{
		printf ("Nhap vao mot so nguyen duong (100<= n < 10000): "); scanf ("%d",&n);
	}while (n<100|| n>=10000);
	cauA(n);
	printf ("\n");
	cauB(n);
	printf ("\n");
	cauC(n);
	printf ("\n");
	cauD(n);
	printf ("\n");
	cauE(n);
	printf ("\n");
	cauF(n);
	printf ("\n");
	
	return 0;	
}

void cauA(int n)
{
	printf ("Cau A:\n");
	int cs=0,S=0;
	do
	{
		cs=n%10;
		n=n/10;
		S+=cs;
		cs=0;
	}while (n>0);
	printf ("Tong cac chu so = %d",S);
}

void cauB(int n)
{
	printf ("Cau B:\n");
	int cs=0,S=0;
	do
	{
		cs=n%10;
		n=n/10;
		if (cs%2!=0)
			S+=cs;
		cs=0;
	}while (n>0);
	printf ("Tong cac chu so le = %d",S);
}

int kiemtrasoNguyenTo(int m)
{
	int dem=0;
	if (m<2)
		return 0;
	for (int i=1; i<=m; i++)
	{
		if (m%i==0)
			dem++;
	}
	if (dem==2)
		return 1;
	return 0;
}

void cauC(int n)
{
	printf ("Cau C:\n");
	int cs=0,S=0;
	do
	{
		cs=n%10;
		n=n/10;
		if (kiemtrasoNguyenTo(cs)==1)
			S+=cs;
		cs=0;
	}while (n>0);
	printf ("Tong cac chu so la so nguyen to = %d",S);	
}

void cauD(int n)
{
	printf ("Cau D:\n");
	int dem=0,cs=0;
	do
	{
		cs=n%10;
		n=n/10;
		if (cs==0)
			dem++;
		cs=0;
	}while (n>0);
	printf ("So chu so 0= %d",dem);
}

void cauE(int n)
{
	printf ("Cau E:\n");
	int dem=0,cs=0;
	do
	{
		cs=n%10;
		n=n/10;
		if (cs%3==0)
			dem++;
		cs=0;
	}while (n>0);
	printf ("So chu so chia het cho 3= %d",dem);
}

void cauF(int n)
{
	printf ("Cau F:\n");
	int dem=0,cs=0;
	do
	{
		cs=n%10;
		n=n/10;
		if (cs%5==0)
			dem++;
		cs=0;
	}while (n>0);
	printf ("So chu so chia het cho 5= %d",dem);
}










