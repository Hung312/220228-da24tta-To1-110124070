#include <stdio.h>
#include <stdlib.h>

void nhapmang(int *a,int n,int m);
void xuatmang(int *a,int n,int m);

int main()
{
	int *A;
	int n,m;
	do
	{
		printf ("Nhap vao so dong: "); scanf ("%d",&n);
		printf ("Nhap vao so cot: "); scanf ("%d",&m);
	} while (n<=0||m<=0);
	A= (int*) calloc(n*m,sizeof(int));
	int x,y; //dong, cot lay tu tap tin matrix.txt
	int *B; //mang con tro lay du lieu tu tap tin matrix.txt
	nhapmang(A,n,m);
	FILE *fp;	char path[100];
	printf ("Nhap vao duong dan ghi du lieu va doc du lieu: "); fflush(stdin); gets(path);
	fp=fopen (path,"w+");
	if (fp==NULL)
		printf ("Loi hoac khong tim thay file\n");
	else
	{
		fprintf (fp,"%d\n",n);
		fprintf (fp,"%d\n",m);
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
				fprintf (fp,"%d ",*(A+i*m+j));
			fprintf (fp,"\n");
		}
		fseek(fp,0,0);
		fscanf(fp,"%d",&x);
		fscanf(fp,"%d",&y);
		B=(int*) malloc(x*y*sizeof(int));
		while (!feof(fp))
		{
			for (int i=0; i<x*y; i++)
				fscanf(fp,"%d",B+i);
		}
		printf ("Danh sach du lieu da doc tu file:\n");
		xuatmang(B,x,y);
		fclose(fp);
	}
	free(A); free(B);
	return 0;
}

void nhapmang(int *a,int n,int m)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf ("Nhap phan tu [%d][%d]= ",i+1,j+1); scanf("%d",a+i*m+j);
		}
	}
}

void xuatmang(int *a,int n,int m)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
			printf("%d ",*(a+i*m+j));
		printf ("\n");
	}
}
