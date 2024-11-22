#define SIZE 100
#include <stdio.h>

void nhapmang(int a[],int n);
void xuatmang(int a[],int n);
int tongmang(int a[],int n);
int tongphantuduong(int a[],int n);
int tongvitrile(int a[],int n);
int demphantuam(int a[],int n);
int demphantule(int a[],int n);
int demnguyento(int a[],int n); int kiemtranguyento(int n);
void timnguyentoI(int a[],int n);
void induongle(int a[],int n);
int tontaiAm(int a[],int n);
int tontaiX(int a[],int n,int x);

int main()
{
	int n,A[SIZE],X;
	do
	{
	printf ("Nhap vao mot so phan tu: "); scanf ("%d",&n);
	}while (n<=0||n>100);

	nhapmang(A,n);
	printf ("\n");
	xuatmang(A,n);
	printf ("\n");
	printf ("Tong cac phan tu trong mang= %d",tongmang(A,n));
	printf ("\n");
	printf ("Tong cac phan tu duong trong mang= %d",tongphantuduong(A,n));
	printf ("\n");
	printf ("Tong cac phan tu tai vi tri le trong mang= %d",tongvitrile(A,n));
	printf ("\n");
	printf ("So cac phan tu am trong mang= %d",demphantuam(A,n));
	printf ("\n");
	printf ("So cac phan tu le trong mang= %d",demphantule(A,n));
	printf ("\n");
	printf ("So cac phan tu nguyen to trong mang= %d",demnguyento(A,n));
	printf ("\n");
	timnguyentoI(A,n);
	printf ("\n");
	if (tontaiAm(A,n)==1)
		printf ("Co ton tai so am trong mang");
	else
		printf ("Khong ton tai so am trong mang");
	printf ("\n");
	induongle(A,n);
	printf ("\n");
	printf ("Nhap mot so X: "); scanf ("%d",&X);
	if (tontaiX(A,n,X)==1)
		printf ("Co ton tai gia tri X trong mang");
	else
		printf ("Khong ton tai gia tri X trong mang");
	return 0;
}


void nhapmang(int a[],int n) //cau A
{
	for (int i=0;i<n;i++)
	{
		printf ("Phan tu [%d]= ",i+1); scanf ("%d",&a[i]);
	}
}

void xuatmang(int a[],int n) //cau B
{
	printf ("Cac phan tu trong mang:\n");
	for (int i=0; i<n;i++)
	{
		printf ("%4d",a[i]);
	}
}

int tongmang(int a[],int n) //cau C
{
	int S=0;
	for (int i=0; i<n; i++)
	{
		S+=a[i];
	}
	return S;
}

int tongphantuduong(int a[],int n) //cau D
{
	int S=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]>0)
			S+=a[i]; //S= S+a[i];
	}
	return S;
}

int tongvitrile(int a[],int n) //cau E
{
	int S=0;
	for (int i=0; i<n; i++)
	{
		if ((i+1) % 2 != 0)
			S+=a[i];
	}
	return S;
}

int demphantuam(int a[],int n) //cau F
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]<0)
			dem++;
	}
	return dem;
}

int demphantule(int a[],int n) //cau G
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]%2!=0)
			dem++;
	}
	return dem;
}

int kiemtranguyento(int n) 
{
	if (n<2)
		return 0;
	int dem=0;
	for (int i=1; i<=n; i++)
	{
		if (n%i==0)
			dem++;
	}
	if (dem==2)
		return 1;
	return 0;
}

int demnguyento(int a[],int n) //cau H
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (kiemtranguyento(a[i])==1)
			dem++;
	}
	return dem;
}

void timnguyentoI(int a[],int n) //cah I
{
	int x,y;
	for (int i=0; i<n; i++)
	{
		if (kiemtranguyento(a[i])==1)
		{
			x= a[i];
			y= i+1;
			break;
		}
	}
	printf ("So nguyen to dau tien trong mang co gia tri= %d, vi tri: %d",x,y);
}

void induongle(int a[],int n) //cau J
{
	printf ("Cac phan tu duong le trong mang: \n");
	for (int i=0; i<n; i++)
	{
		if (a[i]%2!=0&&a[i]>0)
			printf ("%3d", a[i]);
	}
}

int tontaiAm(int a[],int n) //cau K
{
	for (int i=0; i<n; i++)
	{
		if (a[i]<0)
			return 1;
	}
	return 0;
}

int tontaiX(int a[], int n, int x) //cau L
{
	for (int i=0; i<n; i++)
	{
		if (a[i]==x)
			return 1;
	}
	return 0;
}
