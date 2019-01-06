#include<string.h>
#include<stdio.h> 
struct cay{
	int info;
	int cb; //yeu to can bang//
	cay *left,*right;
};
cay *goc;
void khoitao(cay *&goc);// ham tao gia tri cay
void mocnut(cay *&goc,int x);// moc nut vao cay
void taocay(cay *&goc);// tao cay khi moc nut
void duyetLNR(cay *goc); //Duyet cay LNR
void duyetNRL(cay *goc);//	Duyet cay NRL
void duyetRLN(cay *goc);//	Duyet cay  RLN
void xoaytrai(cay *&goc);// xoay trai
void xoayphai(cay *&goc);// xoay phai
void canbangtrai(cay *&p);	// Ham can bang cay con  trai
void canbangphai(cay *&p);// ham can bang cay con phai
void XoaNut(cay *goc, int x); // ham xoa 1 nut cua cay (tham khao son)
int main()
{
		int x;
	khoitao(goc);
	taocay(goc);
	printf("\n---Cay AVL vua tao---\n" );
	printf("\n---Cay AVL sau khi can bang---\n" );
	duyetLNR(goc);
	printf("Nhap nut can xóa: ");
	scanf("%d",&x);
	XoaNut(goc, x);
	duyetLNR(goc);
}
void khoitao()
{
	goc=NULL;
}
void mocnut(int x)
{
	if(goc==NULL)
	{
		goc= new cay;
		goc->info=x;
		goc->left=NULL;
		goc->right=NULL;
		goc->cb=0;
	}
	else
	{
		if(goc->info>=x)
			mocnut(goc->left,x);
		else
			mocnut(goc->right,x);
			
	}
}
void taocay(cay *&goc)
{
int tam;
int i=1;
	do{
		printf(" nhap cay AVL , 0 de dung lai ");
		scanf("%d",&tam);
		if(tam!=0)
			mocnut(goc,tam);
		i++;
			
	}
	while(tam!=0);
}
cay* TaoNut(int val) {
	cay *p;
	p = new cay;
	
	if (p == NULL) {  
		return NULL;
	}
	p->info = val;
	p->left = NULL;
	p->right = NULL;
	p->cb = 0; // Danh he so can bang cho nut
	return p;
}

//Duyet cay LNR
void duyetLNR(cay *goc)
{
	if(goc != NULL)
	{
		duyetLNR(goc->left);
		printf("%d",goc->info);
		duyetLNR(goc->right);
	}
} 
//	Duyet cay  RLN
void duyetRLN(cay *goc)
{
	if(goc != NULL)
	{
		duyetRLN(goc->right);
		duyetRLN(goc->left);
		printf("%d",goc->info);
	}
}
//	Duyet cay NRL
void duyetNRL(cay *goc)
{
	if(goc != NULL)
	{
		printf("%d",goc->info);
		duyetNRL(goc->right);
		duyetNRL(goc->left);
	}
}

// ham tinh chieu cao cay
//int max(int a, int b)
//{
//	if(a>=b)
//		return a;
//	return b;
//}
//
//int chieuCao(cay *goc)
//{
//	if(goc == NULL)
//		return 0;
//	return 1 + max(chieuCao(goc->left), chieuCao(goc->right));
//}
////ham tra ve can bang cay
//int canbang(cay *&goc)
//{
//	if(goc!=NULL)
//		return 1;
//	return goc->cb= chieuCao(goc->left)-chieuCao(goc->right);
//}
void xoaytrai(cay *&q)
{
	cay *p;
	q=p->left;
	p->left=q->right;
	q->right=p;
	p=q;
}
void xoayphai(cay *&q)
{
	cay *p;
	q=p->right;
	p->right=q->left;
	q->left=p;
	p=q;
}
// can bang cay con trai//
void canbangtrai(cay *&p)
{
	switch(p->left->cb)
	{
		case 1:// mat can bang trai trai
			xoayphai(p);
			p->cb=0;
			p->right->cb=0;
			break;
		case 2:// mat can bang trai phai
			xoaytrai(p->left);
			xoayphai(p);
			switch(p->cb)
			{
				case 0: 
					p->left->cb=0;
					p->right->cb=0;
				case 1:
					p->left->cb=0;
					p->right->cb=2;
				case 2:
					p->left->cb=1;
					p->right->cb=0;
			}
			p->cb=0;
			break;
	}
}
// can bang cay con phai//
void canbangphai( cay *&p)
{
		switch(p->right->cb)
	{
		case 1:// mat can bang phai trai//
			xoayphai(p->right);
			xoayphai(p);
			switch(p->cb)
			{
				case 0:
					p->left->cb=0;
					p->right->cb=0;
					break;
				case 1:
					p->left->cb=1;
					p->right->cb=0;
				case 2:
					p->left->cb=0;
					p->right->cb=2;
					break;
			}
			p->cb=0;
			break;
		case 2:// mat can bang  phai phai//
			xoaytrai(p);
			p->cb=0;
			p->left->cb=0;
			break;
	}
}
// Xoa mot nut thuoc cay AVL
void XoaNut(cay *goc, int x) {
	cay *p = goc, *q;
	while((p != NULL) && (p->info != x)) {
		q = p;
		if (p->info > x)
			p = p->left;
		else
			p = p->right;
	}
	if (p == NULL)
		printf("Khong tim thay nut nao!");
	else {
		//Nut can xoa la nut lá
		if (p->left == NULL && p->right == NULL) {
			if (q->left == p)
				q->left = NULL;
			else
				if (q->right == p)
					q->right = NULL;
			delete p;
		} else if (p->left != NULL && p->right == NULL) {
				//cay can xoa co cay con trai, khong co cay con phai
				if (q->left == p)
					q->left = p->left;
				else if (q->right == p)
						q->right = p->left;
				delete p;
			} else if (p->left == NULL && p->right != NULL) {
					//Nut can xoa co cay con phai, khong co cay con trai
					if (q->left == p)
						q->left = p->right;
					else if (q->right == p)
							q->right = p->right;
					delete p;
				} else {									
					//cay can xoa co cay con trai va cay con phai
					cay *t =p->left, *s = t;
					while (t->right != NULL) {
						s = t;
						t = t->right;
					}
					p->info = t->info;
					//Nut dau tien cua cay con trai khong phai la nut cuc phai
					if (s->right == t)					
						s->right = t->left;
					//cay dau tien cua cay con trai la nut cuc phai
					else								
						p->left = t->left;												
					delete t;							
				}
	}
}
int KTcayNPTK(cay *goc)
{
	if (goc == NULL)
		return 1;
	if(goc->left == NULL && goc->right == NULL)
		return 1;
	else
		if(goc->left == NULL) KTcayNPTK(goc->right);
		else
			if(goc->right == NULL) KTcayNPTK(goc->left);
			else
				if(goc->left->info > goc->info || goc->right->info < goc->info)
					return 0;
}

