#include <stdio.h>

int main()
{
	FILE *fp;
	char path[100];
	printf ("Nhap vao duong dan: "); fflush(stdin); gets(path);
	fp=fopen(path,"w");
	if (fp==NULL)
		printf ("Loi file");
	else
	{
		int a[3][3]={{1,2,-3},{4,5,-6},{7,-8,9}};
		int n=3;
		fprintf(fp,"Cac phan tu trong mang: ");
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				fprintf (fp,"%1d ",a[i][j]);
			}
		}
		fprintf(fp,"\n");
		fprintf (fp,"Cac phan tu duong trong mang: ");
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				if (a[i][j]>0)
					fprintf (fp,"%d ",a[i][j]);
			}
		}
		int S=0;
		fprintf (fp,"\n");
		fprintf (fp,"Tong duong: ");
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				if(a[i][j]>0)
				{
					S+=a[i][j];
				}
			}
		}
		fprintf (fp,"%d",S);
		fclose(fp);
	}
	return 0;
}
