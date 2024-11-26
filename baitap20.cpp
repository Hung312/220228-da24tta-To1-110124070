#include <stdio.h>
#define SIZE 1000

void nhapmang (float a[], int n);
void xuatmang (float a[],int n);
float tongmang (float a[],int n);
float trungbinhvitrile (float a[], int n);
int demphantuduong (float a[],int n);
void sapxeptangdan (float a[], int n);
void ingiatrivitrile (float a[], int n);
void invitrigiatri0 (float a[], int n);
float giatrilonnhat (float a[], int n);
void vitrigiatrimaxI (float a[], int n);
void invitrigiatrimax (float a[], int n);
void kiemtratoansoam (float a[], int n);


int main()
{
	int n;
	float A[SIZE];
	//Nhap
	do
	{
		printf ("Nhap vao so phan tu cho mang(0<n<=1000): "); scanf ("%d",&n);
	}while (n<=0||n>1000);
	
	//Ham
	nhapmang (A,n);
	printf ("\n");
	xuatmang(A,n);
	printf ("\n");
	printf ("Tong cac phan tu trong mang= %.1f",tongmang(A,n));
	printf ("\n");
	printf ("Trung binh cong cac phan tu tai vi tri le= %.1f",trungbinhvitrile(A,n));
	printf ("\n");
	printf ("So phan tu duong trong mang= %d",demphantuduong(A,n));
	printf ("\n");
	ingiatrivitrile (A,n);
	printf ("\n");
	invitrigiatri0(A,n);
	printf ("\n");
	vitrigiatrimaxI(A,n);
	printf ("\n");
	invitrigiatrimax(A,n);
	printf ("\n");
	sapxeptangdan(A,n);
	printf ("\n");
	printf ("Gia tri lon nhat trong mang= %.1f",giatrilonnhat(A,n));
	printf ("\n");
	kiemtratoansoam(A,n);
	printf ("\n");
	
	return 0;
}

void nhapmang (float a[], int n) //cau A
{
	for (int i=0; i<n; i++)
	{
		printf ("Phan tu [%d]= ",i+1); scanf ("%f",&a[i]);
	}
}

void xuatmang (float a[], int n) //cau B
{
	printf ("Xuat mang:\n");
	for (int i=0; i<n; i++)
		printf ("%.1f ",a[i]);
}

float tongmang(float a[], int n) //cau C
{
	float S=0;
	for (int i=0; i<n; i++)
		S+=a[i];
	return S;
}

float trungbinhvitrile(float a[], int n) //cau D
{
	float TB=0; int dem=0;
	for (int i=0; i<n; i++)
	{
		if ((i+1)%2 != 0)
		{
			TB+=a[i];
			dem++;
		}
	}
	return TB/dem;
}

int demphantuduong(float a[], int n) //cau E
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]>0)
			dem++;
	}
	return dem;
}

void sapxeptangdan(float a[], int n) //cau F
{
	float temp;
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for (int i=0; i<n ;i++)
	{
		printf ("%.1f ",a[i]);
	}
}

void ingiatrivitrile (float a[], int n)
{
	printf ("Gia tri tai vi tri le:\n");
	for (int i=0; i<n; i++)
	{
		if ((i+1)%2 != 0)
			printf ("%.1f ",a[i]);
	}
}

void invitrigiatri0 (float a[], int n)
{
	printf ("Cac vi tri co gia tri = 0:\n");
	for (int i=0; i<n ; i++)
	{
		if (a[i]==0)
			printf ("a[%d] ",i+1);
	}
}

float giatrilonnhat(float a[],int n)
{
	float ln=a[0];
	for (int i=0; i<n; i++)
	{
		if (ln<=a[i])
			ln = a[i];
	}
	return ln;
}

void vitrigiatrimaxI (float a[], int n)
{
	float ln=a[0]; int y;
	for (int i=0; i<n; i++)
	{
		if (ln<=a[i])
			ln = a[i]; 
	}
	for (int i=0; i<n; i++)
		{
			if (ln==a[i])
			{
				y=i+1;
				break;
			}
		}
	printf ("Gia tri lon nhat dau tien trong mang= %.1f, vi tri: %d",ln,y);
}

void invitrigiatrimax (float a[], int n)
{
	float ln=a[0];
	for (int i=0; i<n; i++)
	{
		if (ln <= a[i])
			ln =a[i];
	}
	printf ("Cac vi tri co gia tri lon nhat trong mang:\n");
	for (int i=0; i<n; i++)
	{
		if (ln == a[i])
			printf ("a[%d] ",i+1);
	}
}

void kiemtratoansoam (float a[], int n)
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]<0)
			dem++;
	}
	if (dem==n)
		printf ("Mang toan so am");
	else
		printf ("Mang khong toan so am");
}


