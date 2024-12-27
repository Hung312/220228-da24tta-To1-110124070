#include <stdio.h>
#include <stdlib.h>

double luythua(float a,int n);
int UCLN(int a,int b);
int Un(int n);
int Xn(int n);
int Yn(int n);

void moveDisk(int src,int des);
void Tower(int n, int cot1,int cot2,int cot3);

int tongmang(int *a,int n);
int chisomax(int *a,int n);


int main()
{
	int n,m;
	float a;
	//de quy luy thua
	printf ("Nhap a: "); scanf("%f",&a);
	printf ("Nhap luy thua: "); scanf ("%d",&n);
	printf ("Luy thua: %.1lf\n",luythua(a,n));
	//de quy UCLN
	printf ("Uoc chung lon nhat cua 2 so tu nhien: %d\n",UCLN(27,51));
	//de quy phi tuyen
	printf ("Nhap vao mot so phi tuyen: "); scanf ("%d",&m);
	printf ("Un=%d\n",Un(m));
	//de quy ho tuong
	printf ("Nhap vao n: "); scanf ("%d",&n);
	printf ("Ho tuong: %d\n",Yn(n));
	//de quy toa thap
	Tower(3,1,2,3);
	//de quy tong mang
	int *b=(int*) malloc(sizeof(int)*6);
	for (int i=0; i<6; i++)
	{
		printf ("b[%d]= ",i+1); scanf ("%d",&b[i]);
	}
	printf ("Tong mang gom 6 phan tu: %d\n",tongmang(b,6));
	
	//de quy tim chi so lon nhat
	printf ("Chi so lon nhat: %d\n",chisomax(b,6));
	
	return 0;
}

double luythua(float a,int n)
{
	if (n==0)
		return 1;
	else
		return (a*luythua(a,n-1));
}

int UCLN(int a,int b)
{
	if (a>b)
		return UCLN(a-b,b);
	else if (a<b)
		return UCLN(b-a,a);
	else
		return a;
}

int Un(int n)
{
	if (n<6)
		return n;
	else if (n>=6)
		{
			int s=0;
			for (int i=n-1;i>=1; i--)
				s+=Un(n-i);
			return s;
		}
}

int Xn(int n)
{
	if (n<5)
		return n;
	else
	{
		return (Xn(n-1)+Yn(n-2));
	}
}

int Yn(int n)
{
	if (n<8)
		return n-3;
	else
		return (Xn(n-1)+Yn(n-1));
}

void moveDisk(int src, int des)
{
	printf ("Tu %d den %d\n",src,des);
}

void Tower(int n,int cot1,int cot2,int cot3)
{
	if (n>0)
	{
		Tower(n-1,cot1,cot3,cot2);
		moveDisk(cot1,cot3);
		Tower(n-1,cot2,cot1,cot3);
	}
}

int tongmang(int *a,int n)
{
	if (n<1)
		return 0;
	return tongmang(a,n-1)+*(a+(n-1));
}

int chisomax(int *a,int n)
{
	if (n<1)
		return -1;
	else	if (n==1)
		return 0;
	else
	{
		int cs=chisomax(a,n-1);
		if (*(a+(n-1))>*(a+cs))
			return cs=n-1;
	}
}



