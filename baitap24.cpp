#include <stdio.h>

#define max 2

typedef struct PHANSO
{
    int tu,mau;
}PS;

void nhapphanso(PS *a);
void nhap2phanso(PS a[]);
void xuat2phanso(PS a[]);
void rutgonphanso(PS a);    int UCLN(int tu, int mau);
void tongphanso(PS a[]);
void hieuphanso(PS a[]);
void tichphanso(PS a[]);
void thuongphanso(PS a[]);


void main()
{
    PS a[max];
    nhap2phanso(a);
    xuat2phanso(a);
    tongphanso(a);
    hieuphanso(a);
    tichphanso(a);
    thuongphanso(a);
}                               

void nhapphanso(PS *a)
{
    printf ("Nhap tu so: "); scanf("%d",&a->tu);
    printf ("Nhap mau so: "); scanf("%d",&a->mau);
}

void nhap2phanso(PS a[])
{
    for (int i=0; i<max; i++)
        nhapphanso(&a[i]);
}

void xuat2phanso(PS a[])
{
    for (int i=0; i<max; i++)
    {
        printf ("Phan so %d= %d/%d\n",i+1,a[i].tu,a[i].mau);
        rutgonphanso(a[i]); printf ("\n");
    }
}

int UCLN(int tu, int mau)
{
    int uoc;
   if (mau != 0)
    {
        if (mau<=10 || mau>=-10)
        {
        if (tu % mau != 0)
            return UCLN (mau, tu%mau);
        else
            return mau;
        }
        else
        {
            if (mau>10 || mau<-10)
            {
                for (int i=1; i<=tu; i++)
                {
                    if (tu%i==0 && mau%i==0)
                        uoc = i;
                }
            }   
        }
    }
    return uoc;
}

void rutgonphanso(PS a)
{
    PS b;
    int uoc= UCLN(a.tu,a.mau);
    b.tu=a.tu/uoc;
    b.mau=a.mau/uoc;
    if (b.tu!=0)
    {
        if (b.mau<0)
        {
            b.tu*=-1;
            b.mau*=-1;
        }
        if (b.mau!=1)
            printf ("Rut gon: %d/%d",b.tu,b.mau);
        else
            printf ("Rut gon: %d",b.tu);
    }
    else
        printf ("Rut gon: 0");
}

void tongphanso(PS a[])
{
    PS tong;
    for (int i=0; i<max; i++)
    {
        for (int j=i+1; j<max; j++)
        {
            if (a[i].mau!=a[j].mau)
            {
                tong.tu=a[i].tu*a[j].mau+a[j].tu*a[i].mau;
                tong.mau=a[i].mau*a[j].mau;
                break;
            }
            else 
            {
                tong.tu=a[i].tu+a[j].tu;
                tong.mau=a[i].mau=a[j].mau;
                break;
            }
        }
    }
    int uoc=UCLN(tong.tu,tong.mau);
    tong.tu/=uoc;
    tong.mau/=uoc;
    if (tong.tu!=0)
    {
        if (tong.mau<0)
        {
            tong.tu*=-1;
            tong.mau*=-1;
        }
        if (tong.mau!=1)
            printf ("Tong bang %d/%d\n",tong.tu,tong.mau);
        else
            printf ("Tong bang %d\n",tong.tu);
    }
    else
        printf ("Tong bang 0\n");
}

void hieuphanso(PS a[])
{
    PS hieu;
    for (int i=0; i<max; i++)
    {
        for (int j=i+1; j<max; j++)
        {
            if (a[i].mau!=a[j].mau)
            {
                hieu.tu=a[i].tu*a[j].mau-a[i].mau*a[j].tu;
                hieu.mau=a[i].mau*a[j].mau;
                break;
            }
            else
            {
                hieu.tu=a[i].tu-a[j].tu;
                hieu.mau=a[i].mau=a[j].mau;
            }
        }
    }
    int uoc=UCLN(hieu.tu,hieu.mau);
    hieu.tu/=uoc;
    hieu.mau/=uoc;
    if (hieu.tu!=0)
    {
        if (hieu.mau<0)
        {
            hieu.tu*=-1;
            hieu.mau*=-1;
        }
        if (hieu.mau!=1)
            printf ("Hieu bang %d/%d\n",hieu.tu,hieu.mau);
        else
            printf ("Hieu bang %d\n",hieu.tu);
    }
    else
        printf ("Hieu bang 0\n");
}

void tichphanso(PS a[])
{
    PS tich;
    for (int i=0; i<max; i++)
    {
        for (int j=0; j<max; j++)
        {
            tich.tu=a[i].tu*a[j].tu;
            tich.mau=a[i].mau*a[j].mau;
            break;
        }
    }
    int uoc=UCLN(tich.tu,tich.mau);
    tich.tu/=uoc;
    tich.mau/=uoc;
    if (tich.tu!=0)
    {
        if(tich.mau<0)
        {
            tich.tu*=-1;
            tich.mau*=-1;
        }
        if (tich.mau!=1)
            printf ("Tich bang %d/%d\n",tich.tu,tich.mau);
        else
            printf ("Tich bang %d\n",tich.tu);
    }
    else
        printf ("Tich bang 0\n");
}

void thuongphanso(PS a[])
{
    PS thuong;
    for (int i=0; i<max; i++)
    {
        for (int j=i+1; j<max; j++)
        {
            thuong.tu=a[i].tu*a[j].mau;
            thuong.mau=a[i].mau*a[j].tu;
            break;
        }
    }
    int uoc=UCLN(thuong.tu,thuong.mau);
    thuong.tu/=uoc;
    thuong.mau/=uoc;
    if (thuong.tu!=0)
    {
        if (thuong.mau<0)
        {
            thuong.tu*=-1;
            thuong.mau*=-1;
        }
        if (thuong.mau!=1)
            printf ("Thuong bang %d/%d\n",thuong.tu,thuong.mau);
        else
            printf ("Thuong bang %d\n",thuong.tu);
    }
    else
        printf ("Thuong bang 0\n");
}

