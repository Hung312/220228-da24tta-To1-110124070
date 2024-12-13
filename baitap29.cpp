#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char path[100];
	printf ("Nhap vao duong dan: "); fflush(stdin); gets(path);
	fp=fopen(path,"r");
	if (fp==NULL)
		printf ("Loi file");
	else
	{
		int n,*p;
		fscanf(fp,"%d",&n);
		p=(int*)calloc(n,sizeof(int));
		printf ("danh sach gia tri lay tu file\n");
		for (int i=0; i<n; i++)
		{
			fscanf(fp,"%d",&p[i]);
			printf ("%d ",p[i]);
		}
		fclose(fp);
	}
	return 0;
}
