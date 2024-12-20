#include <stdio.h>
#include <stdlib.h>

typedef struct Phan_So
{
	int tu,mau;
}PS;
 
void nhapPS(PS *a);
void nhapDSPS(PS a[],int n);

void xuatPS(PS a,int n);
void xuatDSPS(PS a[], int n);

void rutgon(PS a[],int n);	int UCLN(int tu, int mau);

PS PSmin(PS a[], int n);	float giatri(PS a);
int demsoPSmin(PS a[], int n);

int main()
{
	PS *A,*B;
	int n;
	char path[100];	FILE *fp;
	printf ("Nhap vao so phan so: "); scanf("%d",&n);
	A=(PS*)calloc(n,sizeof(PS));
	nhapDSPS(A,n);
	B=(PS*)calloc(n,sizeof(PS));
	printf ("Nhap vao duong dan: "); fflush(stdin); gets(path);
	fp=fopen(path,"w+b");
	
	if (fp==NULL)
		printf ("Loi file");
	else
	{
		for (int i=0; i<n; i++)
		{
			fwrite(A,sizeof(PS),n,fp);
			fseek(fp,0,0);
			fread(A+i,sizeof(PS),n,fp);
		}
		fclose (fp);	printf ("\n");
		xuatDSPS(A,n);	printf ("\n");
		PS min=PSmin(A,n);
		printf ("Phan so co gia tri nho nhat: %d/%d\n",min.tu,min.mau);
	}
	free(A);
	return 0;
}

void nhapPS(PS *a)
{
	printf ("Nhap tu: "); scanf ("%d",&a->tu);
	printf ("Nhap mau: "); scanf ("%d",&a->mau);
}

void nhapDSPS(PS a[],int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("Phan so thu %d\n",i);
		nhapPS(&a[i]);	printf ("\n");
	}
}

void xuatDSPS(PS a[], int n)
{
	rutgon(a,n);
	for (int i=0; i<n; i++)
	{
		if (a[i].tu!=0)
		{
			if (a[i].mau<0)
			{
				a[i].tu*=-1;
				a[i].mau*=-1;
			}
			if (a[i].mau!=1)
				printf ("%d/%d\n",a[i].tu,a[i].mau);
			else
				printf ("%d\n",a[i].tu);
		}
		else
			printf ("0\n");
	}
}

int UCLN(int tu, int mau)
{
	int uoc;
	if (mau!=0)
	{
		if(mau<=10||mau>=-10)
		{
			if (tu%mau!=0)
				return UCLN(mau,tu%mau);
			else
				return mau;
		}
		else
		{
			if(mau>10||mau<-10)
			{
				for (int i=0; i<mau; i++)
				{
					if (tu%i==0&&mau%i==0)
						uoc=i;
				}
			}
		}
	}
	else
		return 0;
	return uoc;
}

void rutgon(PS a[],int n)
{
	for (int i=0; i<n; i++)
	{
		int uoc =UCLN(a[i].tu,a[i].mau);
		a[i].tu/=uoc;
		a[i].mau/=uoc;
	}
}

PS PSmin(PS a[],int n)
{
	int gt=giatri(a[0]);
	PS min;
	for (int i=0; i<n; i++)
	{
		if (gt>giatri(a[i]))
			{
				min=a[i];
				gt=giatri(a[i]);
			}
	}
	return min;
}

float giatri(PS a)
{
	float gt=a.tu/a.mau;
	return gt;
}

int demsoPSmin(PS a[],int n)
{
	float gt=giatri(a[0]);
	PS min;
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (gt>giatri(a[i]))
		{
			min=a[i];
			gt=giatri(a[i]);
			dem++;
		}
	}
	return dem;
}








