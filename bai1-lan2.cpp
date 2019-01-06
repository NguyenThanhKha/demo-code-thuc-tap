#include<stdio.h>
#include<iostream>
using namespace std;
#define max 50;
int n=4;//
int a[5][5]={0,0,0,1,0,
			 0,0,1,1,1,
			 1,0,0,0,1,
			 0,0,0,0,0,
			 0,0,0,0,0};
int thutu=2;
int tt[5];
//-------ham tra ve khi khong co cung den,-1 khong co dinh-------//
//----xoa cung den tu dinh j--//
void xoacung(int j)
{
	int k;
	for(k=0;k<=n;k++)
		a[j][k]=0;
}
void ghinhan(int j,int &thutu)
{
	tt[j]=thutu;
	thutu=thutu+1;
	xoacung(j);	
}
int dinhkd(int a[5][5],int n)
{
	int i,j=0 ,kt;//
	while(j <= n)
	{
		kt=0;
		for(i=0;i<=n;i++)
			if(a[i][j]!=0)
				kt=3;
			if((kt==0)&&(tt[j]==0))
			{
				ghinhan(j,thutu);
				thutu+1;
				return j;		
			}
			else{
				kt=0;
				j=j+1;
				}
	}
    return -1;
}
//-------//

//--kiem tra so dinh duoc chon---///
void kiemtra(int tt[5],int n)
{
	int k,dem=0,i;
	for(k=0;k<=n;k++)
		if(tt[k]!=0) dem=dem+1;
	if(dem!=n+1)
		printf("\n khong sap xep topo duoc\n");
	else
	{
		for(k=2;k<=n+2;k++)
			for(i=0;i<=n;i++)
				if(tt[i]==k)
					printf("%3d",i);
	}
	
}
int main()
{
	int dinh;
	int sddc=0;
	do{
		dinh=dinhkd(a,n);
				
				if((dinh!=-1)&&(sddc<=n))
				{
					if(tt[dinh]!=0)
					sddc=sddc+1;
				}	
	}
	while((dinh!=-1)&&(sddc<=n));
	kiemtra(tt,n);
	return 0;
//	printf("\n dinh khong co cung den la:%d",dinhkd(a,n));
	
}

