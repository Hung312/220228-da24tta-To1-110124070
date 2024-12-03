#include <stdio.h>
#include <stdlib.h>

void nhapgiatri(int p[], int n);
void xuatgiatri(int p[], int n);
int tonggiatri(int p[], int n);
int max(int p[], int n);
int demmax(int p[], int n);
void demX(int p[],int n);
int tontaisoduong(int p[], int n);
void sapxeptangdan(int p[], int n);
void locsoam(int p[],int n);

int main()
{
	int *p,n;
	do
	{
		printf ("Nhap vao mot so nguyen(0<n<50): "); scanf ("%d",&n);
	}while (n>=50||n<=0);
	p=(int*) calloc(n,sizeof(int));
	if(p==NULL)
	{
		printf ("Co loi, khong the cap phat");
		exit(0);
	}
	nhapgiatri(p,n);
	xuatgiatri(p,n);
	printf ("Tong cac gia tri: %d\n",tonggiatri(p,n));
	printf ("Gia tri lon nhat: %d\n",max(p,n));
	printf ("So lan xuat hien gia tri lon nhat: %d\n",demmax(p,n));
	demX(p,n);
	if (tontaisoduong(p,n)==1)
		printf ("Co ton tai so duong\n");
	else
		printf ("Khong ton tai so duong\n");
	sapxeptangdan(p,n);
	locsoam(p,n);
	return 0;
}

void nhapgiatri(int p[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("Nhap gia tri [%d]: ",i+1); scanf ("%d",&p[i]);
	}
}

void xuatgiatri(int p[], int n)
{
	printf ("Xuat gia tri:\n");
	for (int i=0; i<n; i++)
		printf ("Gia tri = %d\n",*(p+i));
}

int tonggiatri(int p[], int n)
{
	int S=0;
	for (int i=0; i<n; i++)
		S+= p[i];
	return S;
}

int max(int p[], int n)
{
	int max=p[0];
	for (int i=0; i<n; i++)
	{
		if (max<p[i])
			max=p[i];
	}
	return max;
	
}

int demmax(int p[], int n)
{
	int dem=0,max=p[0];
	for (int i=0; i<n; i++)
	{
		if (max<p[i])
			max=p[i];
	}
	for (int i=0; i<n; i++)
	{
		if (p[i]==max)
			dem++;
	}
	return dem;
}

void demX(int p[], int n)
{
	int dem=0, X;
	printf ("Nhap vao mot so de kiem tra so lan xuat hien: "); scanf ("%d",&X);
	for (int i=0; i<n; i++)
	{
		if (p[i]==X)
			dem++;
	}
	printf ("So lan xuat hien: %d\n",dem);
}

int tontaisoduong(int p[], int n)
{
	for (int i=0; i<n; i++)
	{
		if(p[i]>0)
			return 1;
	}
	return 0;
}

void sapxep(int *n, int *m)
{
	int temp=*n;
	*n=*m;
	*m=temp;
}

void sapxeptangdan(int p[], int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if(p[i]>p[j])
				sapxep(&p[i],&p[j]);
		}
	}
	xuatgiatri(p,n);
}

void locsoam(int p[],int n)
{
	int soam[n],m=0;
	for (int i=0; i<n; i++)
	{
		if (p[i]<0)
		{
			soam[i]=p[i];
			m++;
		}
	}
	xuatgiatri(soam,m);
}





