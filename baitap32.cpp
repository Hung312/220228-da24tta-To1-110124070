#include <stdio.h>
#include <stdlib.h>

typedef struct NGAY_THANG
{
	int ngay,thang,nam;
}DAY;

typedef struct SINH_VIEN
{
	char maSP[10], ten[50];
	float dongia, hanSD;
	DAY ngaySX;
}SV;

void nhapSP(SV *a);
void nhapNgay(DAY *a);
void nhapDSSP(SV a[],int n);



int main()
{
	FILE *fp;
	char path[100];
	int n;
	do
	{
		printf ("\nNhap vao so san pham(n>0): "); scanf ("%d",&n);
	}while(n<=0);
	SV *A= (SV*)calloc(n,sizeof(SV));
	nhapDSSP(A,n);
	
	printf ("Nhap duong dan dua danh sach san pham: "); fflush(stdin); gets(path);
	fp=fopen(path,"wb");
	if (fp==NULL)
		printf ("Loi file");
	else
	{
		fwrite(A,sizeof(SV),n,fp);
		fclose(fp);
	}
	free(A);
	return 0;
}

void nhapSP(SV *a)
{
	printf ("Nhap ma san pham: "); fflush(stdin); scanf("%s",&a->maSP);
	printf ("Nhap ten san pham: "); fflush(stdin); gets(a->ten);
	printf ("Nhap don gia: "); scanf("%f",&a->dongia);
	printf ("Nhap han su dung: "); scanf("%f",&a->hanSD);
	printf ("Nhap ngay san xuat:\n");
	nhapNgay(&a->ngaySX);
}

void nhapNgay(DAY *a)
{
	printf ("Nhap ngay: "); scanf ("%d",&a->ngay);
	printf ("Nhap thang: "); scanf ("%d",&a->thang);		//dinh dang
	printf ("Nhap nam: "); scanf ("%d",&a->nam);
}

void nhapDSSP(SV a[],int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("San pham thu %d\n",i+1);
		nhapSP(&a[i]);
	}
}
















