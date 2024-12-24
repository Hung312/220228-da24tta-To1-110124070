#include <stdio.h>
#include <stdlib.h>

#define max 50


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

typedef struct LOP_HOC
{
	char malop[11],tenlop[30];
	int siso;
	SV DSSV[max];
}LOP;

void nhapSV(SV *a);
void nhapDSSV(SV *a[], int n);	void nhapMon(Mon a[],int n);	void nhapNgay(Ngay *a);

void xuatSV(SV a);
void xuatDSSV(SV a[], int n);	void xuatMon(Mon a[],int n);	void xuatNgay(Ngay a);

void nhapLop(LOP *a, int n);
void nhapDSLop(LOP a[], int n);

void xuatLop(LOP a);
void xuatDSLop(LOP a[], int n);





int main()
{
	LOP *A;
	int n;
	printf ("Nhap vao so lop hoc: "); scanf ("%d",&n);
	A=(LOP*) calloc(n,sizeof(LOP));
	nhapDSLop(A,n);
	xuatDSLop(A,n);
	
	return 0;
}

void nhapSV(SV *a)
{
	printf ("Nhap vao ma so sinh vien: "); fflush(stdin); scanf ("%s",&a->mssv);
	printf ("Nhap vao ho ten: "); fflush(stdin); gets(a->hoten);
	printf ("Nhap vao gioi tinh: "); fflush(stdin); scanf ("%s",&a->gioitinh);
	printf ("Nhap dia chi: "); fflush(stdin); gets(a->diachi);
	nhapNgay(&a->ngaysinh);
	printf ("Nhap vao so mon: "); scanf ("%d",&a->somon);
	nhapMon(a->mon,a->somon);
}

void nhapNgay(Ngay *a)
{	
	printf ("Nhap vao ngay: "); scanf ("%d",&a->ngay);
	printf ("Nhap vao thang: "); scanf ("%d",&a->thang);
	printf ("Nhap vao nam: "); scanf("%d",&a->nam);
	if (a->thang==1||a->thang==3||a->thang==5||a->thang==7||a->thang==8||a->thang==10||a->thang==12)
    {
        if (a->ngay >31 ||a->ngay <=0)
        {
            do
            {
                printf ("Nhap lai ngay trong thang %d co 31 ngay: ",a->thang);scanf ("%d",&a->ngay);    
            } while (a->ngay>31||a->ngay<=0);
        }
    }
    else
    {
        if(a->thang==2)
        {
            if (a->ngay>28)
            {
                do
                {
                    printf ("Nhap lai ngay trong thang %d co 28 ngay: ",a->thang); scanf("%d",&a->ngay);
                } while (a->ngay>28||a->ngay<=0);
            }
        }
        else
        {
            if (a->ngay>30)
            {
                do
                {
                    printf ("Nhap lai ngay trong thang %d co 30 ngay: ",a->thang); scanf("%d",&a->ngay);
                } while (a->ngay>30||a->ngay<=0);
            }
            
        }
	}
}

void nhapMon(Mon a[], int n)
{
	a=(Mon*) calloc(n,sizeof(Mon));
	for (int i=0; i<n; i++)
	{
		printf ("Ma mon %d: ",i+1); scanf ("%d",&a[i].mamon);
		printf ("Diem mon %d: ",i+1); scanf ("%f",&a[i].diem);
	}
}

void nhapDSSV(SV a[], int n)
{
	for (int i=0; i<n; i++)
	{
		nhapSV(&a[i]);	printf("\n");
	}
}

void nhapLop(LOP *a)
{
	printf ("Nhap vao ma lop: "); fflush(stdin); gets(a->malop);
	printf ("Nhap vao ten lop: "); fflush(stdin); gets(a->tenlop);
	printf ("Nhap vao si so lop: "); scanf("%d",&a->siso);
	printf ("Danh sach sinh vien:\n");
	nhapDSSV(a->DSSV,a->siso);	
}

void nhapDSLop(LOP a[], int n)
{
	for (int i=0; i<n; i++)
		nhapLop(&a[i]);
}

void xuatNgay(Ngay a)
{
	printf ("%d/%d/%d\t",a.ngay,a.thang,a.nam);
}


void xuatSV(SV a)
{
	printf ("%s\t%s\t%s\t%s\t",a.mssv,a.hoten,a.gioitinh,a.diachi);
	xuatNgay(a.ngaysinh);
	printf ("%d\n",a.somon);
	xuatMon(a.mon,a.somon);	printf ("\n");
}

void xuatMon(Mon a[],int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("Mon %d: ",i+1);
		printf (" %d\t%.1f\n",a[i].mamon,a[i].diem);
	}	
}

void xuatDSSV(SV a[],int n)
{
	printf ("MSSV\tHo ten\tGioi tinh\tDia chi\tNgay sinh\tSo mon\n");
	for (int i=0; i<n; i++)
		xuatSV(a[i]);
}

void xuatLop(LOP a)
{
	printf ("Ma lop: %s\n",a.malop);
	printf ("Ten lop: %s\n",a.tenlop);
	printf ("Si so lop: %d\n",a.siso);
	printf ("Danh sach sinh vien:\n");
	xuatDSSV(a.DSSV,a.siso);
}

void xuatDSLop(LOP a[],int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("Lop %d\n",i+1);
		xuatLop(a[i]);
	}
}


