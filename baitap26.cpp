#include <stdio.h>
#define max 20

typedef struct SACH
{
	char masach[20],tensach[150],tacgia[150],nhaXB[150];
	int dongia,soluong,namXB,thanhtien,thuctien;
	float thue=0.1;
}Sach;

void nhap(Sach *a);
void nhapSach(Sach a[],int n);	int thanhtien(Sach a);	int thuctien(Sach a);
void xuatSach(Sach a[], int n);
void sapxepSach(Sach a[], int n);	void hoanvi(int *n,int *m);

int main()
{
	Sach a[max];
	int n;
	printf ("Nhap vao so quyen sach: "); scanf ("%d",&n);
	nhapSach(a,n);	printf ("\n");
	xuatSach(a,n);
	sapxepSach(a,n);
	return 0;
}

void nhap(Sach *a)
{
	printf ("Nhap ma sach: "); fflush(stdin); scanf ("%s",a->masach);
	printf ("Nhap ten cuon sach: "); fflush(stdin); gets(a->tensach);
	printf ("Nhap ten tac gia: "); fflush(stdin); gets(a->tacgia);
	printf ("Nhap ten nha xuat ban: "); fflush(stdin); gets(a->nhaXB);
	printf ("Nhap nam xuat ban: "); scanf("%d",&a->namXB);
	printf ("Nhap vao don gia: "); scanf ("%d",&a->dongia);
	printf ("Nhap vao so luong: "); scanf ("%d",&a->soluong);
	a->thanhtien=a->soluong*a->dongia;
	a->thuctien=a->thanhtien+a->thanhtien*a->thue;
	printf ("Thanh tien= %d\n",a->thanhtien);
	printf ("Thuc tien= %d\n",a->thuctien);
}

void nhapSach(Sach a[],int n)
{
	for (int i=0; i<n; i++)
		nhap(&a[i]);
}

void xuat(Sach a)
{
	printf ("Ma sach: %s\n",a.masach);
	printf ("Ten sach: %s\n",a.tensach);
	printf ("Tac gia: %s\n",a.tacgia);
	printf ("Nha xuat ban: %s\n",a.nhaXB);
	printf ("Nam xuat ban: %d\n",a.namXB);
	printf ("Don gia va so luong: %d va %d\n",a.dongia,a.soluong);
	printf ("Thanh tien va thuc tien= %d va %d\n",a.thanhtien,a.thuctien);
}

void xuatSach(Sach a[],int n)
{
	for (int i=0; i<n; i++)
		xuat(a[i]);
}

void hoanvi(int *n, int *m)
{
	int temp=*n;
	*n=*m;
	*m=temp;
}

void sapxepSach(Sach a[],int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (a[i].namXB<a[j].namXB)
			{
				hoanvi(&a[i].namXB,&a[j].namXB);
			}
		}
	}
	xuatSach(a,n);
}














