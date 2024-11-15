#include <stdio.h>


int main()
{
	int DT,sl,gia,phi;
	printf ("Nhap vao so luong ban ra trong ngay: "); scanf ("%d",&sl);
	printf ("Nhap vao gia 1 san pham: "); scanf("%d",&gia);
	printf ("Nhap vao phi van chuyen: "); scanf ("%d",&phi);
	DT= sl*gia-phi;
	printf ("Doanh thu trong ngay = %d",DT);
	return 0;
}
