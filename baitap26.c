#include <stdio.h>
#include <stdlib.h>


typedef struct SAN_PHAM
{
    char ma[15],ten[75],tacgia[150],nhaXB[200];
    int namXB,soluong;
    float dongia,thanhtien,thuctien;
    float thue;
}SP;

void nhapDSSP(SP a[],int n);
void nhapSP(SP *a);

void xuatSP(SP a);
void xuatDSSP(SP a[],int n);

float Thanhtien(SP a[],int n);
float Thuctien(SP a[], int n);
void sapxep(SP a[],int n);
void hoanvi(SP *n, SP *m);


int main()
{
    SP *A;
    int n;
    printf ("Nhap vao so luong cuon sach: "); scanf("%d",&n);
    A=(SP*)calloc(n,sizeof(SP));
    nhapDSSP(A,n);
    xuatDSSP(A,n);  printf ("\n");
    sapxep(A,n);
    free(A);
    return 0;
}

void nhapSP(SP *a)
{
    printf ("Nhap ma sach: "); fflush(stdin); scanf ("%s",a->ma);
    printf ("Nhap ten sach: "); fflush(stdin); gets(a->ten);
    printf ("Nhap ten tac gia: "); fflush(stdin); gets(a->tacgia);
    printf ("Nhap nha Xuat ban: "); fflush(stdin); gets(a->nhaXB);
    printf ("Nhap vao nam xuat ban: "); scanf ("%d",&a->namXB);
    printf ("Nhap don gia: "); scanf ("%f",&a->dongia);
    printf ("Nhap vao so luong: "); scanf ("%d",&a->soluong);
    a->thue=0.1;
    a->thanhtien=a->dongia*a->soluong;
    a->thuctien=a->thanhtien+(a->thanhtien*a->thue);
}

void nhapDSSP(SP a[], int n)
{
    for (int i=0; i<n; i++)
        nhapSP(&a[i]);
}

void xuatDSSP(SP a[], int n)
{
    printf ("Ma Sach\tTen sach\tTac gia\tnha XB\tNam XB\tDon gia\tSo luong\n");
    for (int i=0; i<n; i++)
    {
        xuatSP(a[i]);   printf ("\n");
    }
    printf ("Thanh tien: %.1f",Thanhtien(a,n)); printf ("\n");
    printf ("Thuc tien: %.1f",Thuctien(a,n));  printf ("\n");
}

void xuatSP(SP a)
{
    printf ("%s\t%s\t%s\t\t%s\t%d\t%.1f\t%d\n",a.ma,a.ten,a.tacgia,a.nhaXB,a.namXB,a.dongia,a.soluong);
}

float Thanhtien(SP a[], int n)
{
    float thanhtien;
    for (int i=0; i<n; i++)
        thanhtien+=a[i].thanhtien;
    return thanhtien;
}

float Thuctien(SP a[],int n)
{
    float thuctien;
    for (int i=0; i<n; i++)
        thuctien+=a[i].thuctien;
    return thuctien;
}   

void sapxep(SP a[],int n)
{
    for (int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i].namXB<=a[j].namXB)
            {
                hoanvi(&a[i],&a[j]);
                xuatSP(a[i]);
            }
            else
            {
                if (a[i].namXB>a[j].namXB)
                {
                    xuatSP(a[j]);
                }
            }
        }
    }
}

void hoanvi(SP *n, SP *m)
{
    SP temp=*n;
    *n=*m;
    *m=temp;
}

