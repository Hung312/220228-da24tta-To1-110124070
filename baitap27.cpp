#include <stdio.h>


int main()
{
	FILE *fp;
	char path[100];
	printf ("Nhap vao duong dan: "); fflush(stdin); gets(path);
	fp= fopen(path,"w+");
	if (fp==NULL)
	{
		printf ("Loi file");
	}
	else
	{
		fprintf (fp,"Nguyen Truong Hung");
	}
	return 0;
}
