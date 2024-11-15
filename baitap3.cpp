#include <stdio.h>

#define Pi 3.1415

int main()
{
	int a=50,b=23,h=30;
	float C=12.56;
	float ST, STh;
	//tinh dien tich hinh tron
	printf ("Dien tich hinh tron:\n");
	ST= (C*C)/(Pi*4); 	printf ("S = %.2f\n",ST);
	
	//tinh dien tich hinh thang
	printf ("Dien tich hinh thang:\n");
	STh= ((a+b)/2)*h;	printf ("S = %.2f\n",STh);
	
	//tinh dien tich con lai
	printf ("Dien tich con lai cua san truong = %.2f",STh-ST);
	
	return 0;
}
