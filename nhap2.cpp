#include<stdio.h>
struct nut{
	int info;
	nut *left,*right;
};
typedef nut Node;
Node *goc;
void khoitao( Node *&goc)
{
	goc= NULL;
}
//moc nut vao goc
void mocnut(Node *&goc,int x)
{
	if(goc==NULL)
	{
		goc= new Node;
		goc->info=x;
		goc->left=NULL;
		goc->right=NULL;
	}
	else
	{
	 	if(goc->info >= x)
			mocnut(goc->left,x);
		else
			mocnut(goc->right,x);
	}
}
void taocay(Node *&goc)
{
	int tam;
	do{
		printf(" nhap 1 sp 0 dung ");
		scanf("%d",&tam);
		if(tam!=0)
			mocnut(goc,tam);
			
	}
	while(tam!=0);
}
//duyetcay
void duyetLRN(Node *goc)
{
	if(goc!=NULL)
	{
		duyetLRN(goc->left);
		printf("%3d",goc->info);
		duyetLRN(goc->right);
	}
}
// dem la
int demla(Node *goc)
{
	if(goc==NULL)
		return 0;
	else
		if(goc->left==NULL&&goc->right==NULL)
			return 1;
	else	
		return demla(goc->left)+demla(goc->right);
}
//tong la
int tongla(Node *goc)
{
	if(goc==NULL)
		return 0;
	else
	{
		if((goc->left==NULL)&&(goc->right==NULL))
			return goc->info;
		else
			return tongla(goc->left)+tongla(goc->right);
	}
}
int main()
{
	khoitao(goc);
	taocay(goc);
	duyetLRN(goc);
	printf("\n so nut la:%3d\n",demla(goc));
	printf("\n so nut la:%3d:\n",tongla(goc));
	return 0;
}

