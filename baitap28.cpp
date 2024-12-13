#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char path[100];
	int n;
	int *a;
	//nhap duong dan
	printf ("Nhap vao duong dan: "); fflush(stdin); gets(path);
	
	fp=fopen(path,"w+");
	if (fp==NULL)
	{
		printf ("Loi file");
	}
	else
	{
		printf ("Nhap vao so phan tu nguyen: "); scanf ("%d",&n);
		a=(int*)calloc(n,sizeof(int));
		fprintf (fp,"%d\n",n);
		for (int i=0; i<n; i++)
		{
			printf ("Phan tu %d: ",i+1); scanf ("%d",&a[i]);
			fprintf (fp,"%1d ",a[i]);
		}
		fclose(fp);
	}
	return 0;
}
