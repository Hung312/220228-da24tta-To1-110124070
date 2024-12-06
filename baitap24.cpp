#include <stdio.h>
#define max 2

typedef struct PhanSo
{
	int tuso, mauso;
}PS;

void nhapphanso(PS *a);
void nhap2phanso(PS a[]);
void xuatphanso(PS a);
void xuat2phanso(PS a[]);
void rutgonphanso(PS a);	int UCLN(int a,int b);
void cong2phanso(PS a[]);
void tru2phanso(PS a[]);
void nhan2phanso(PS a[]);
void chia2phanso(PS a[]);

int main()
{
	PS a[max];
	nhap2phanso(a);
	xuat2phanso(a);
	cong2phanso(a);
	tru2phanso(a);
	nhan2phanso(a);
	chia2phanso(a);
	return 0;
}


void nhapphanso(PS *a)
{
	printf ("Nhap tu so: "); scanf ("%d",&a->tuso);
	printf ("Nhap mau so: "); scanf ("%d",&a->mauso);
}

void nhap2phanso(PS a[])
{
	for (int i=0; i<max; i++)
		nhapphanso(&a[i]);
}

void xuatphanso(PS a)
{
	printf ("%d/%d\n",a.tuso,a.mauso);	
}

void xuat2phanso(PS a[])
{
	for (int i=0; i<max; i++)
	{
		printf("Phan so %d: ",i+1);
		xuatphanso(a[i]);
		rutgonphanso(a[i]);
	}
}

int UCLN(int a,int b)
{
	if (a%b!=0)
		return UCLN(b,a%b);
	return b;
}

void rutgonphanso(PS a)
{
	int x=a.tuso,y=a.mauso,ucln=UCLN(x,y);
	x/=ucln;
	y/=ucln;
	if (y!=1)
	{
		if (y<0)
		{
			x*=-1;
			y*=-1;
		}
		printf ("Rut ron phan so: %d/%d\n",x,y);
	}
	else
		printf ("Rut ron phan so: %d\n",x);
}

void cong2phanso(PS a[])
{
	int x,y;
	for (int i=0; i<max; i++)
	{
		for (int j=i+1; j<max; j++)
		{
			if (a[i].mauso==a[j].mauso)
			{
				x=a[i].tuso+a[j].tuso;
				y=a[i].mauso;
				break;
			}
			else
			{
				x=a[i].tuso*a[j].mauso+a[j].tuso*a[i].mauso;
				y=a[i].mauso*a[j].mauso;
				break;
			}
		}
	}
	x/=UCLN(x,y);
	y/=UCLN(x,y);
	if(y!=1)
	{
		if (y<0)
		{
			x*=-1;
			y*=-1;
		}
			printf ("Tong bang %d/%d\n",x,y);
	}
	else
		printf ("Tong bang %d",x);
}

void tru2phanso(PS a[])
{
	int x,y;
	for (int i=0; i<max; i++)
	{
		for (int j=i+1; j<max; j++)
		{
			if (a[i].mauso==a[j].mauso)
			{
				x=a[i].tuso-a[j].tuso;
				y=a[i].mauso;
			}
			else
			{
				x=a[i].tuso*a[j].mauso-a[j].tuso*a[i].mauso;
				y=a[i].mauso*a[j].mauso;
				break;
			}
		}
	}
	x/=UCLN(x,y);
	y/=UCLN(x,y);
	if(y!=1)
	{
		if (y<0)
		{
			x*=-1;
			y*=-1;
		}
			printf ("Hieu bang %d/%d\n",x,y);
	}
	else
		printf ("Hieu bang %d",x);
}

void nhan2phanso(PS a[])
{
	int x,y;
	for (int i=0; i<max; i++)
	{
		for (int j=i+1; j<max; j++)
		{
			x=a[i].tuso*a[j].tuso;
			y=a[i].mauso*a[j].mauso;
			break;
		}
	}
	x/=UCLN(x,y);
	y/=UCLN(x,y);
	if(y!=1)
	{
		if (y<0)
		{
			x*=-1;
			y*=-1;
		}
			printf ("Tich bang %d/%d\n",x,y);
	}
	else
		printf ("Tich bang %d",x);
}

void chia2phanso(PS a[])
{
	int x,y;
	for (int i=0; i<max; i++)
	{
		for (int j=i+1; j<max; j++)
		{
			x=a[i].tuso*a[j].mauso;
			y=a[i].mauso*a[j].tuso;
			break;
		}
	}
	x/=UCLN(x,y);
	y/=UCLN(x,y);
	if(y!=1)
	{
		if (y<0)
		{
			x*=-1;
			y*=-1;
		}
			printf ("Thuong bang %d/%d\n",x,y);
	}
	else
		printf ("Thuong bang %d",x);
}

