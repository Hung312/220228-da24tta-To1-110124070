#include <stdio.h>

int main()
{
	float dtb;
	printf ("Nhap diem trung binh: "); scanf ("%f",&dtb);
	if (dtb>9.5)
		printf ("Xuat sac");
	else
	{
		if (dtb>8.5 && dtb<=9.5)
			printf ("Gioi");
		else
		{
			if (dtb>6.5 && dtb<=8.5)
				printf ("Kha");
			else
			{
				if(dtb>5 && dtb<=6.5)
					printf ("Trung binh");
				else
					printf ("Yeu");
			}
		}
	}
	return 0;
}
