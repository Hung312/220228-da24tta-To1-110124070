#include <stdio.h>
#define max 10005

int min(int n,int m);
int abs(int a);
int chiphi(int i);




int n,h[max],f[max];
void main()
{
    printf ("Nhap vao n: "); scanf ("%d",&n);
    for (int i=1; i<=n; i++)
        scanf ("%d",&h[i]);
    for (int i=1; i<=n; i++)
        f[i]= -1;
    printf ("chi phi: %d",chiphi(1));
}

int abs(int a)
{
    if (a<0)
        return -a;
    return a;
}

int min(int n, int m)
{
    if (n<m)
        return n;
    return m;
}

int chiphi(int i)
{
    if (i==n) 
        return 0;
    if (f[i] != -1) 
        return f[i];
    f[i]=chiphi(i+1) +abs(h[i]-h[i+1]);
    if (i<n-1)
        f[i]=min(f[i],chiphi(i+2)+abs(h[i]-h[i+2]));
    return f[i];
}


