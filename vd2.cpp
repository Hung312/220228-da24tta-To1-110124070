#include <stdio.h>

int main()
{
	//khai bao bien
	char mssv[18],hoten[100],lop[20];
	int namsinh;
	float diem;
	//nhap
	printf ("Ma so sinh vien: "); fflush(stdin); scanf("%s",mssv);
	printf ("Ho va ten: "); fflush(stdin); gets(hoten);
	printf ("Lop: "); fflush(stdin); scanf("%s",lop);
	printf ("Nam sinh: "); scanf("%d",&namsinh);
	printf ("Diem so: ");scanf("%f",&diem);
	//xuat
	printf ("Thong tin ca nhan\n");
	printf ("Ma so sinh vien: %s\n",mssv);
	printf ("Ho va ten: %s\n",hoten); 
	printf ("Lop: %s\n",lop);
	printf ("Nam sinh: %d\n",namsinh);
	printf ("Diem so: %.1f\n",diem);
	return 0;
}
