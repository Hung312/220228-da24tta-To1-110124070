#include <stdio.h>
#include <stdlib.h>

typedef struct NGAY_THANG
{
	int ngay,thang,nam;
}DAY;

typedef struct SAN_PHAM
{
	char maSP[10], ten[50];
	float dongia, hanSD;
	DAY ngaySX;
}SP;

void nhapSP(SP *a);
void nhapNgay(DAY *a);
void nhapDSSP(SP a[],int n);

void xuatNgay(DAY );
void xuatSP(SP );
void xuatDSSP(SP ,int );

int main()
{
	FILE *fp;
	char path[100];
	int n=1;
	SP *A= (SP*)calloc(n,sizeof(SP));	
	printf ("Nhap duong dan dua danh sach san pham: "); fflush(stdin); gets(path);
	fp=fopen(path,"rb");
	if (fp==NULL)
		printf ("Loi file");
	else
	{
		int i=0;
		while(feof(fp)==0)
			{
				A=(SP*)realloc(A,sizeof(SP)*(i+1));
				n++;
				fread(A+i,sizeof(SP),1,fp);
				i++;
			}
		fclose(fp);
		xuatDSSP(*A,n);
	}
	free(A);
	return 0;
}

void nhapSP(SP *a)
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

void xuatNgay(DAY a)
{
	printf ("%d/%d/%d",a.ngay,a.thang,a.nam);
}

void nhapDSSP(SP a[],int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("San pham thu %d\n",i+1);
		nhapSP(&a[i]);
	}
}

void xuatDSSP(SP a[],int n)
{
	printf ("Ma\tTen\nDon Gia\tHan SD\tNgay SX\n");
	for (int i=0; i<n; i++)
	{
		xuatSP(a[i]);	xuatNgay(a[i].ngaySX);	printf ("\n");
	}
}

void xuatSP(SP a)
{
	printf ("%s\t%s\t%.1f\t%.1f",a.maSP,a.ten,a.dongia,a.hanSD);
}














