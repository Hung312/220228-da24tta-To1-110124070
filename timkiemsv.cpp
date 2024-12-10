int timSV(SV *list, int n, char*mssv);
void xuatSV(SV *sv);
void xuatSV1(SV sv);
#include<string.h>
int main()
{
	SV *list;
	int n = 10;
	
	list = (SV*)malloc(n*sizeof(SV));
	
	/*SV list[20];
	int n = 10;
	*/
	nhapDanhSach(list, n);
	int vt=timSV(list,n,"110124001");
	if(vt==-1)
	{
		printf("\nKhong ton tai");
	}
	else
	{
		xuatSV(*(list+vt));
	}
	
	return 0;
}
int timSV(SV *list, int n, char*mssv)
{
	for(i =0-->n-1)
	{
		if(strcmp((list+i)->mssv, mssv)==0)
		{
			return i;
		}
	}
	return -1;
}
