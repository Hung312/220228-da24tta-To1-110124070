#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,c,delta,x1,x2;
	printf ("Nhap vao 3 he so: "); scanf ("%d %d %d",&a,&b,&c);
	delta=(b*b)-(4*a*c);
	if (delta < 0)
		printf ("Phuong trinh vo nghiem");
	else
	{
		if (delta == 0)
		{
			printf ("Phuong trinh co nghiem kep\n");
			printf ("x1=x2= %.2f",-b/(2*a));
		}
		else
			{
				x1= (-b+sqrt(delta))/(2*a);
				x2= (-b-sqrt(delta))/(2*a);
				printf ("Phuong trinh co 2 nghiem phan biet:\n");
				printf ("x1=%.2f, x2=%.2f",x1,x2);
			}
	}
	return 0;
}
