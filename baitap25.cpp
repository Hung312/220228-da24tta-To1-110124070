#include <stdio.h>
#include <stdlib.h>

#define max 35

typedef struct NgaySinh
{
	int ngay,thang,nam;
}Ngay;

typedef struct MonHoc
{
	int mamon;
	float diem;
}Mon;

typedef struct SinhVien
{
	char mssv[15],hoten[150],gioitinh[4],diachi[250];
	int somon;
	Ngay ngaysinh;
	Mon mon[];
}SV;

void nhap(SV *a);
void nhapSV(SV a[], int n);
void nhapNgay(Ngay *a);
void nhapMon(Mon *a[],int n);
void xuat(SV a);
void xuatSV(SV a[], int n);


int main()
{
	SV a[max];
	int n;
	printf ("Nhap vao so sinh vien: "); scanf ("%d",&n);
	while (n<=0)
	{
		printf ("Nhap lai: "); scanf("%d",&n);
	}
	nhapSV(a,n);
	xuatSV(a,n);
	
	
	return 0;
}

void nhap(SV *a)
{
	printf ("Nhap vao ma so sinh vien: "); fflush(stdin); scanf ("%s",&a->mssv);
	printf ("Nhap vao ho ten: "); fflush(stdin); gets(a->hoten);
	printf ("Nhap vao gioi tinh: "); fflush(stdin); scanf ("%s",&a->gioitinh);
	printf ("Nhap dia chi: "); fflush(stdin); gets(a->diachi);
	nhapNgay(&a->ngaysinh);
	printf ("Nhap vao so mon: "); scanf ("%d",&a->somon);
	nhapMon(&a->mon,a->somon);
}

void nhapSV(SV a[], int n)
{
	for (int i=0; i<n; i++)
		nhap(&a[i]);
}

void nhapNgay(Ngay *a)
{	
	do
	{
		printf ("Nhap ngay sinh: "); scanf ("%d",&a->ngay);
	}while (a->ngay<=0||a->ngay>31);
	do
	{
		printf ("Nhap thang sinh: "); scanf ("%d",&a->thang);
	}while (a->thang<=0||a->thang>12);
	printf ("Nhap nam sinh: "); scanf ("%d",&a->nam);
}

void nhapMon(Mon *a[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("Ma mon %d: ",i+1); scanf ("%d",&a[i]->mamon);
		printf ("Diem mon %d: ",i+1); scanf ("%f",&a[i]->diem);
	}
}

void xuat(SV a)
{
	printf ("MSSV: %s\n",a.mssv);
	printf ("Ho ten: %s\n",a.hoten);
	printf ("Gioi tinh: %s\n",a.gioitinh);
	printf ("Ngay sinh: %d/%d/%d\n",a.ngaysinh.ngay,a.ngaysinh.thang,a.ngaysinh.nam);
	printf ("Dia chi: %s\n",a.diachi);
	printf ("So mon: %d\n",a.somon);
	for (int i=0; i<a.somon; i++)
	{
		printf ("Ma mon %d: %.1f\n",a.mon[i].mamon,a.mon[i].diem);
	}
}

void xuatSV(SV a[],int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("Sinh vien thu %d\n",i+1);
		xuat(a[i]);	printf ("\n");
	}
}
















