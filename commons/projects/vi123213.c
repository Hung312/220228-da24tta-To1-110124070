#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp= fopen("D://nerf//commons//projects//inout//input.txt","r");
    if (fp == NULL)
    {
        printf ("loi~ file");
    }
    else
    {
        int *a;
        int n;
        fscanf (fp,"%d",n);
        a=(int*) malloc(sizeof(int)*n);
        for (int i=0; i<n;i++)
        {
            fscanf(fp,"%d",a[i]);
            printf ("%d",a[i]);
        }
        fclose (fp);
    }
}