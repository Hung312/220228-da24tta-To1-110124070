#include <stdio.h>

int main()
{
	FILE *fp;
	char path[100];
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int n=3;
	printf ("Nhap duong dan: "); fflush(stdin); gets(path);
	fp=fopen(path,"w");
	if (fp==NULL)
		printf ("Loi file");
	else
	{
		fprintf (fp,"%d\n",n);
		for (int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				fprintf (fp,"%1d ",a[i][j]);
			fprintf (fp,"\n");
		}
		fclose(fp);
	}
	return 0;
}
