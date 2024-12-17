#include <stdio.h>
#define max 255

int main()
{
	FILE *fp1,*fp2;
	char path1[100], path2[100];
	printf ("Nhap duong dan tap tin de ghi bo sung: "); fflush(stdin); gets(path1);
	printf ("Nhap duong dan tap tin doc du lieu: "); fflush(stdin); gets(path2);
	fp1=fopen(path1,"a");
	fp2=fopen(path2,"r");
	if (fp1==NULL||fp2==NULL)
		printf ("Loi file");
	else
	{
		char chuoi[max+1];
		fprintf(fp1,"\n");
		while(feof(fp2)==0)
		{
			if (fgets(chuoi,max,fp2)!=NULL)
				fprintf (fp1,"%s",chuoi);
		}
		fclose(fp1);	fclose(fp2);
	}
	return 0;
}
