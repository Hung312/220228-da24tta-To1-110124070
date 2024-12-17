#include <stdio.h>


int main()
{
	FILE *fp;
	char path[100];
	printf ("Nhap duong dan: "); fflush(stdin); gets(path);
	fp=fopen(path,"a");
	if (fp==NULL)
		printf ("Loi file");
	else
	{
		fprintf (fp,"Ai nhut thi toi dung nhi\n");
		fprintf (fp,"Ai ma hon nua toi thi dung ba\n");
	}
	return 0;
}
