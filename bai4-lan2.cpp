#include<stdio.h>
#include<stdlib.h>
#define  inp  "bai4.inp.txt"
FILE *c;
void taofile();
void xuatfile();
int main()
{

	taofile();
	xuatfile();
//	c = fopen("bai4.inp.txt","t"); 
}



void taofile()
{
	int n,x;
	FILE *f=fopen("bai4.inp.txt","wt");
	
	if(f==NULL)
	{
		printf("\n khong nhap duoc");
	}
	printf("nhap so phan tu:");
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{	
		scanf("%d",&x);
		fprintf(f,"%3d",x);
	}
	fclose(f);
}
void xuatfile()
{ 
	FILE*f;char duongdan[100];
	int i=1,x;
	f=fopen("bai4.inp.txt", "rt");
	if(f==NULL)
	{
		printf("\n ko nhap dc");
		
	}
	while(!feof(f))
	{
		fscanf(f,"%3d",&x);
		printf("\n",x);
		i++;
	}
	fclose(f);
}
