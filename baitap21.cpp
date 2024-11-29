#define row 100
#define col 100
#include <stdio.h>

void nhapMang(int a[][col], int n, int m);
void xuatMang(int a[][col], int n, int m);
int tongMang(int a[][col], int n, int m);
void tongDongk(int a[][col], int n, int m);
void tongCotk(int a[][col], int n, int m);
void tontaiamDongk(int a[][col], int n, int m); int kiemtrasoam(int n);
void tontainguyentoCotk(int a[][col],int n, int m); int kientranguyento(int n);
void sapxepmangDongkGiamDan(int a[][col], int n, int m); void sapxep(int *n, int *m);
void kiemtraCotktoanSoLe(int a[][col],int n, int m); int kiemtrasole(int n);
void kiemtratontaiX(int a[][col],int n, int m);
void xacdinhX(int a[][col], int n, int m);
void MaxDongk(int a[][col], int n, int m);
void MinDongk(int a[][col], int n, int m);
void inNguyenToDongk(int a[][col], int n, int m);
int main()
{
 	int a[row][col], m, n;
	do
	{
		printf ("Nhap vao so dong: "); scanf ("%d",&n);
		printf ("Nhap vao so cot: "); scanf ("%d",&m);
	}while (m<=0||m>col||n<=0||n>row);	
	//ham
	nhapMang(a,n,m);
	xuatMang(a,n,m);	printf ("\n");
	printf ("Tong cac phan tu trong mang = %d",tongMang(a,n,m));	printf ("\n");
	tongDongk(a,n,m);	printf ("\n");
	tongCotk(a,n,m);	printf ("\n");
	tontaiamDongk(a,n,m);	printf ("\n");
	tontainguyentoCotk(a,n,m);	printf ("\n");
	kiemtraCotktoanSoLe(a,n,m);	printf ("\n");
	sapxepmangDongkGiamDan(a,n,m); printf ("\n");
	kiemtratontaiX(a,n,m);	printf ("\n");
	xacdinhX(a,n,m);	printf ("\n");
	MaxDongk(a,n,m);	printf ("\n");
	MinDongk(a,n,m);	printf ("\n");
	inNguyenToDongk(a,n,m);	printf ("\n");
	return 0;
}

void nhapMang(int a[][col], int n, int m)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf ("Nhap phan tu a[%d][%d]: ",i+1,j+1); scanf ("%d",&a[i][j]);
		}
	}
}

void xuatMang(int a[][col], int n, int m)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf ("%3d",a[i][j]);
		}
		printf ("\n");
	}
}

int tongMang(int a[][col], int n, int m)
{
	int S=0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			S+=a[i][j];
		}
	}
	return S;
}

void tongDongk(int a[][col], int n, int m)
{
	int S=0,k;
	do
	{
		printf ("Nhap vao dong tinh tong(0<=k<n): "); scanf ("%d",&k);
	}while (k<0||k>n);
	for (int j=0; j<m; j++)
		S+=a[k-1][j];
	printf ("Tong cac phan tu tren dong %d= %d",k,S);
}

void tongCotk(int a[][col], int n, int m)
{
	int S=0,k;
	do
	{
		printf ("Nhap vao cot tinh tong(0<=k<m): "); scanf ("%d",&k);
	}while (k<0||k>m);
	for (int i=0; i<n; i++)
		S+=a[i][k-1];
	printf ("Tong cac phan tu tren cot %d= %d",k,S);
}

int kiemtrasoam(int n)
{
	if (n<0)
		return 1;
	return 0;
}

void tontaiamDongk(int a[][col], int n, int m)
{
	int k,dem=0;
	do
	{
		printf ("Nhap dong can kiem tra so am: "); scanf ("%d",&k);
	}while (k>n||k<=0);
	for (int j=0; j<m; j++)
	{
		if(kiemtrasoam(a[k-1][j])==1)
		{
			dem++;
			break;
		}
	}
	if (dem!=0)
		printf ("Dong %d co ton tai so am",k);
	else
		printf ("Dong %d khong ton tai so am",k);
}

int kiemtranguyento(int n)
{
	int dem=0;
	if (n<2)
		return 0;
	for (int i=1; i<=n; i++)
	{
		if (n%i==0)
			dem++;
	}
	if (dem==2)
		return 1;
	return 0;
}

void tontainguyentoCotk(int a[][col], int n, int m)
{
	int dem=0,k;
	do
	{
		printf ("Nhap cot can kiem tra nguyen to: "); scanf ("%d",&k);
	}while (k<=0||k>m);
	for (int i=0; i<m; i++)
	{
		if (kiemtranguyento(a[i][k-1])==1)
		{
			dem++;
			break;
		}
	}
	if (dem!=0)
		printf ("Cot %d co ton tai so nguyen to",k);
	else
		printf ("Cot %d khong ton tai so nguyen to",k);
}

void sapxep(int *n,int *m)
{
	int temp;
	
	temp= *n;
	*n= *m;
	*m= temp;
}

void sapxepmangDongkGiamDan(int a[][col], int n, int m)
{
	int k,temp;
	do
	{
		printf ("Nhap dong can sap xep giam dan: "); scanf ("%d",&k);
	}while (k<=0||k>n);
	for (int i=0; i<m; i++)
	{
		for(int j=i+1; j<m; j++)
		{
			if (a[k-1][i]<a[k-1][j])
				sapxep(&a[k-1][i],&a[k-1][j]);
		}
	}
	xuatMang(a,n,m);
}

int kiemtrasole(int n)
{
	if (n%2!=0)
		return 1;
	return 0;
}

void kiemtraCotktoanSoLe(int a[][col],int n, int m)
{
	int k,dem = 0;
	do
	{
		printf ("Nhap cot kiem tra toan so le: "); scanf ("%d",&k);
	}while (k<=0||k>m);
	for (int i=0; i<n; i++)
	{
		if (kiemtrasole(a[i][k-1])==1)
			dem++;
	}
	if (dem==m)
		printf ("Cot %d toan so le",k);
	else
		printf ("Cot %d khong toan so le",k);
}

void kiemtratontaiX(int a[][col], int n, int m)
{
	int X,temp=0;
	printf ("Nhap vao gia tri kiem tra ton tai: "); scanf ("%d",&X);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (a[i][j]==X)
			{
				temp++;
				break;
			}
		}
	}
	if (temp!=0)
		printf ("Mang co ton tai gia tri %d",X);
	else
		printf ("Mang khong ton tai gia tri %d",X);
}

void xacdinhX(int a[][col], int n, int m)
{
	int x,y,giatri;
	printf ("Nhap vao mot gia tri kiem tra vi tri: "); scanf ("%d",&giatri);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (a[i][j]==giatri)
			{
				x=i+1;
				y=j+1;
			}
		}
	}
	printf ("Gia tri %d nam o dong %d, cot %d",giatri, x, y);
}

void MaxDongk(int a[][col], int n, int m)
{
	int max=a[1][1],k;
	do
	{
		printf ("Nhap dong can tim gia tri lon nhat: "); scanf ("%d",&k);
	}while (k<=0||k>n);
	for (int j=0; j<m ; j++)
	{
		if (max<=a[k-1][j])
			max=a[k-1][j];
	}
	printf ("Gia tri lon nhat tren dong %d= %d",k,max);
}

void MinDongk(int a[][col], int n, int m)
{
	int min=a[1][1],k;
	do
	{
		printf ("Nhap dong can tim gia tri nho nhat: "); scanf ("%d",&k);
	}while (k<=0||k>n);
	for (int j=0; j<m ; j++)
	{
		if (min>=a[k-1][j])
			min=a[k-1][j];
	}
	printf ("Gia tri nho nhat tren dong %d= %d",k,min);
}

void inNguyenToDongk(int a[][col], int n, int m)
{
	int k;
	do
	{
		printf ("Nhap dong in gia tri nguyen to: "); scanf ("%d",&k);
	}while (k<=0||k>n);
	printf ("Cac phan tu nguyen to tren dong %d:\n",k);
	for (int j=0; j<m; j++)
	{
		if (kiemtranguyento(a[k-1][j])==1)
			printf ("%3d",a[k-1][j]);
	}
}



