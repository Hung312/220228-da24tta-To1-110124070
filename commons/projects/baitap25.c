#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NgayThang
{
    int ngay,thang,nam;
}Day;

typedef struct Mon
{
    int mamon;
    float diem;
}MonHoc;

typedef struct SINH_VIEN
{
    char mssv[15],hoten[150],gioitinh[4],diachi[200];
    int somon;
    Day ngaysinh;
    MonHoc *mon;
}SV;


void nhapSV(SV *a);
void nhapNgaysinh(Day *a);
void nhapMonhoc(MonHoc *a, int n);
void nhapDSSV(SV a[], int n);

void xuatSV(SV a);
void xuatDSSV(SV a[],int n);

void timtheomaso(SV a[], int n);
void timtheoten(SV a[], int n);
void DSSVthang8(SV a[], int n);
void DSSVtheogioitinh(SV a[],int n);
void DSSVtheodiachi(SV a[], int n);

int main()
{
    SV *A;
    int n;
    printf ("Nhap vao so sinh vien(n>0): "); scanf("%d",&n);
    while (n<=0)
    {
    do
        {
            printf ("Nhap lai: "); scanf("%d",&n);    
        } while (n<=0);
    }
    A= (SV*) calloc(n,sizeof(SV));
    nhapDSSV(A,n);  printf ("\n");
    xuatDSSV(A,n);  printf ("\n");
    timtheomaso(A,n);   printf ("\n");
    timtheoten(A,n);    printf ("\n");
    printf ("Danh sach sinh vien sinh thang 8:\n");
    DSSVthang8(A,n);    printf ("\n");
    DSSVtheogioitinh(A,n);  printf ("\n");
    DSSVtheodiachi(A,n);    printf ("\n");
    return 0;
}


void nhapSV(SV *a)
{
    printf ("Nhap vao ma so sinh vien: "); fflush(stdin); scanf("%s",&a->mssv);
    printf ("Nhap vao ho ten sinh vien: "); fflush(stdin); gets(a->hoten);
    printf ("Nhap ngay sinh:\n");
    nhapNgaysinh(&a->ngaysinh);
    printf ("Nhap vao gioi tinh: "); fflush(stdin); scanf ("%s",&a->gioitinh);
    printf ("Nhap dia chi: "); fflush(stdin); gets (a->diachi);
    printf ("Nhap so mon: "); scanf ("%d",&a->somon);
    a->mon=(MonHoc*)calloc(a->somon,sizeof(MonHoc*));
    nhapMonhoc(a->mon,a->somon);
}

void nhapNgaysinh(Day *a)
{
    printf ("Ngay: "); scanf ("%d",&a->ngay);
    printf ("Thang: "); scanf ("%d",&a->thang);             //dinh dang. lai.
    printf ("Nam: "); scanf("%d",&a->nam);
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
                    printf ("Nhap lai ngay trong thang 2 co 28 ngay: ",a->thang); scanf("%d",&a->ngay);
                } while (a->ngay>28||a->ngay<=0);
            }
        }
        else
        {
            if (a->ngay>30||a->ngay<=0)
            {
                do
                {
                    printf ("Nhap lai ngay trong thang %d co 30 ngay: ",a->thang); scanf("%d",&a->ngay);
                } while (a->ngay>30||a->ngay<=0);
            }
            
        }
    }
}
void nhapMonhoc(MonHoc a[],int n)
{
    for (int i=0; i<n; i++)
    {
        printf("Ma mon %d: ",i+1); scanf ("%d",&a[i].mamon);
        printf ("Diem so: "); scanf ("%f",&a[i].diem);
    }
}

void nhapDSSV(SV a[], int n)
{
    for (int i=0; i<n; i++)
        nhapSV(&a[i]);
}

void xuatDSSV(SV a[],int n)
{
    for (int i=0; i<n; i++)
    {  
        printf ("Sinh vien %d\n",i+1);
        xuatSV(a[i]);   printf ("\n");
    }
}

void xuatSV(SV a)
{
    printf ("Mssv: %s\n",a.mssv);
    printf ("Ho ten: %s\n",a.hoten);
    if (a.ngaysinh.ngay<10&&a.ngaysinh.thang<10)
        printf ("Ngay sinh: 0%d/0%d/%d\n",a.ngaysinh.ngay,a.ngaysinh.thang,a.ngaysinh.nam);
    else
    {
        if (a.ngaysinh.ngay<10)
            printf ("Ngay sinh: 0%d/%d/%d\n",a.ngaysinh.ngay,a.ngaysinh.thang,a.ngaysinh.nam);
        else
        {
            if(a.ngaysinh.thang<10)
                printf ("Ngay sinh: %d/0%d/%d\n",a.ngaysinh.ngay,a.ngaysinh.thang,a.ngaysinh.nam);
            else
                printf ("Ngay sinh: %d/%d/%d\n",a.ngaysinh.ngay,a.ngaysinh.thang,a.ngaysinh.nam);
        }
    }
    printf ("Gioi tinh: %s\n",a.gioitinh);
    printf ("Dia chi: %s\n",a.diachi);
    printf ("So mon: %d\n",a.somon);
    for (int i=0; i<a.somon; i++)
        printf ("Ma mon %d: %.1f\n",a.mon[i].mamon,a.mon[i].diem);
}

void timtheomaso(SV a[],int n)
{
    char maso[15];
    printf ("Nhap ma so sinh vien can tim: "); fflush(stdin); scanf("%s",&maso);
    for (int i=0; i<n; i++)
    {
        if (strcmp(maso,a[i].mssv)==0)
        {
            xuatSV(a[i]);
            break;
        }
    }
    
}

void timtheoten(SV a[], int n)
{
    char ten[150];
    printf ("Nhap ten can tim: "); fflush(stdin); gets(ten);
    for (int i=0; i<n; i++)
    {
        if (strcmp(ten,a[i].hoten)==0)
            xuatSV(a[i]);
    }
}

void DSSVthang8(SV a[], int n)
{
    for (int i=0; i<n; i++)
    {
        if (a[i].ngaysinh.thang==8)
            xuatSV(a[i]);
    }
}

void DSSVtheogioitinh(SV a[], int n)
{
    char gioitinh[4];
    char *p;
    printf ("Nhap gioi tinh(Nam,Nu) can tim: "); fflush(stdin); scanf("%s",&gioitinh);
    for (int i=0; i<n; i++)
    {
        p=strstr(a[i].gioitinh,gioitinh);
        if (a[i].gioitinh==p)
            xuatSV(a[i]);
    }
}

void DSSVtheodiachi(SV a[], int n)
{
    char diachi[200];
    char *p;
    printf ("Nhap vao dia chi can tim: "); fflush(stdin); gets(diachi);
    for (int i=0; i<n; i++)
    {
        p=strstr(a[i].diachi,diachi);
        if (a[i].diachi==p)
            xuatSV(a[i]);
    }
}
