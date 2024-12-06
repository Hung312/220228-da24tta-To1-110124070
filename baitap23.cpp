#include <stdio.h>

typedef struct thongtin
{
	char hoten[100],gioitinh[4], diachi[150];
	int tuoi;
	float thunhap;
}TT;

void nhapthongtin(TT *a);
void xuatthongtin(TT a);

int main()
{
	TT a;
	nhapthongtin(&a);
	xuatthongtin(a);
	return 0;
}



void nhapthongtin(TT *a)
{
	printf ("Nhap vao ho va ten: "); fflush(stdin); gets(a->hoten);
	do
	{
		printf ("Nhap tuoi: "); scanf ("%d",&a->tuoi);
	}while(a->tuoi<=0||a->tuoi>110);
	printf ("Nhap vao gioi tinh: "); fflush(stdin); scanf ("%s",&a->gioitinh);
	printf ("Nhap vao dia chi: "); fflush(stdin); gets(a->diachi);
	printf ("Nhap vao thu nhap: "); scanf("%f",&a->thunhap);
}

void xuatthongtin(TT a)
{
	printf ("%s\t%d\t%s\t%s\t%.1f\n",a.hoten,a.tuoi,a.gioitinh,a.diachi,a.thunhap);
}

