#include <stdio.h>
#include <stdlib.h>


void nhapmang(int *a,int n,int m);
void xuatmang(int *a,int n,int m);


int main()
{
	int *a;
	int n,m;
	printf ("Nhap vao so dong: "); scanf("%d",&n);
	printf ("Nhap vao so cot: "); scanf ("%d",&m);
	a=(int*)malloc(sizeof(int)*n*m); //chua du lieu
	nhapmang(a,n,m);
	FILE *fp;
	char path[100];
	printf ("Nhap duong dan dua du lieu vao: "); fflush(stdin); gets(path);
	fp= fopen(path,"w+");
	if (fp==NULL)
		printf ("Loi file");
	else
	{
		fprintf (fp,"%d\n",n);
		fprintf (fp,"%d\n",m);
		for (int i=0; i<n ;i++)
		{
			for (int j=0; j<m; j++)
				fprintf (fp,"%d",*(a+i+j));
		}
		printf ("\n");
		int *list= (int*) malloc(sizeof(int)*n*m); //doc du lieu
		int x,y;
		fscanf(fp,"%d",&x);
		fscanf(fp,"%d",&y);
		for (int i=0; i<x; i++)
		{
			for (int j=0; j<y; j++)
				fscanf(fp,"%d ",list+i+j);
		}
		for (int i=0; i<x; i++)
		{
			for (int j=0; j<y; j++)
			{
				fprintf (fp,"%d ",*(list+i+j));
			}
			fprintf (fp,"\n");
		}
		fclose(fp);
	}
	return 0;
}

void nhapmang(int *a,int n,int m)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf ("Phan tu [%d][%d]= ",i+1,j+1); scanf ("%d",(a+i+j));
		}
	}
}

void xuatmang(int a[],int n,int m)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf ("%d ",*(a+i+j));
		}
		printf ("\n");
	}
}


