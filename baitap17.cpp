#include <stdio.h>

void cauA(int n);
void cauB(int n);
void cauC(int n);
void cauD(int n);	int kiemtrasoNguyenTo(int m);
void cauE(int n);
void cauF(int n);
void cauG(int n);
void cauH(int n);
void cauI(int n);

int main()
{
	int n;
	do
	{
		printf ("Nhap vao mot so nguyen duong (n<100): "); scanf ("%d",&n);
	}while (n>=100||n<=0);
	
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
	cauG(n);
	printf ("\n");
	cauH(n);
	printf ("\n");
	cauI(n);
	return 0;
}

void cauA(int n)
{
	printf ("Cau A:\n");
	for (int i=1; i<=n; i++)
		printf ("%d ",i);
}

void cauB(int n)
{
	printf ("Cau B:\n");
	for (int i=1; i<=n; i++)
	{
		if (i%2==0)
			printf ("%d ",i);
	}
}

void cauC(int n)
{
	printf ("Cau C:\n");
	for (int i=1; i<=n; i++)
	{
		if (i%5==0)
			printf ("%d ",i);
	}
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

void cauD(int n)
{
	printf ("Cau D:\n");
	printf ("Cac so nguyen to: ");
	for (int i=1; i<n; i++)
	{
		if (kiemtrasoNguyenTo(i)==1)
			printf ("%d ",i);
	}
}

void cauE(int n)
{
	printf ("Cau E:\n");
	int S=0;
	for (int i=1; i<=n; i++)
	{
		S+=i;
	}
	printf ("Tong= %d",S);
}

void cauF(int n)
{
	printf ("Cau F:\n");
	int S=0;
	for (int i=1; i<=n; i++)
	{
		if (i%2!=0)
			S+=i;
	}
	printf ("Tong cac so le tu 1 -> %d = %d",n,S);
}

void cauG(int n)
{
	int S=0;
	printf ("Cau G:\n");
	for (int i=1; i<n; i++)
	{
		if (kiemtrasoNguyenTo(i)==1)
			S+=i;
	}
	printf ("Tong cac so nguyen to nho hon %d= %d",n,S);
}

void cauH(int n)
{
	int STB=0;
	printf ("Cau H:\n");
	for (int i=1; i<=n; i++)
	{
		if (i%2!=0)
			STB+=i;
	}
	printf ("Trung binh cong cac so le tu 1 -> %d = %.1f",n,(float) STB/n);
}

void cauI(int n)
{
	int STB=0;
	printf ("Cau I:\n");
	for (int i=1;i<n;i++)
	{
		if (kiemtrasoNguyenTo(i)==1)
		{
			STB+=i;
		}
	}
	printf ("Trung binh cong cac so nguyen to nho hon %d = %.1f",n,(float) STB/n);
}


