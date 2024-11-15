#include <stdio.h>

int main()
{
	int n;
	//nhap
	do
	{
		printf ("Nhap vao so nguyen: "); scanf ("%d",&n);
	}while (n<=1||n>=10);
	//in ra bang nhan n
	int i=1;
	while (i<=10)
	{
		printf ("%d * %d= %d\n",n,i,n*i);
		i++;
	}
	printf ("\n");
	//in ra bang nhan 2 -> 9
	printf ("Bang cuu chuong\n");
	for (i=2;i<=9;i++)
	{
		for (int j=1;j<=10;j++)
		{
			printf ("%d * %d = %d\n",i,j,i*j);
		}
		printf ("\n");
	}
	return 0;	
}
