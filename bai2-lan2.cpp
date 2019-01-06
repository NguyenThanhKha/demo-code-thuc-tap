#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
 struct nut{
 	char nd[80];
 	nut *sau,*truoc;
 };
 typedef nut Node;
 nut *dau,*dau1;
 void khoitao(nut *&dau)
 {
 	dau=NULL;
 }
 void nhap(nut *&dau)
 {
 	int i=1;
 	Node *q,*p;
 	char nd[80];
 	cout<<"\n go enter de dung:\n";
 	do{
 		cout<<"\n nhap doan van"<<i<<":\n"<<endl;
 		fflush(stdin);
 		gets(nd);
 		i=i+1;
 		if(strcmp(nd,"\0")!=0)
 		{
			p=new Node;
			strcpy(p->nd,nd);			
			p->sau=NULL;
			p->truoc=NULL;
			if(dau==NULL)
			dau=p;
			else
			{
				q->sau=p;
				p->truoc=q;
			}
			q=p;
		}
	
	}
	while(strcmp(nd,"\0")!=0);
}
void duyetvb(Node *dau)
{
	if(dau!=NULL)
	{
		printf("\n%s",dau->nd);
		duyetvb(dau->sau);
	}
}
void inij(Node *dau, int i, int j)
{
	int dem;
	Node *p,*q;
	if(j>=i)
	{
// tim i
		dem=1;
		p=dau;
		while(p!=NULL&&dem!=i)
		{
			p=p->sau;
			dem=dem+1;
		}
		if(p!=NULL)
		{
// tim j
			q=p;
			while(q!=NULL&&dem!=j)
			{
				q=q->sau;
				dem=dem+1;
			}
// in ra dong i den dong j.
			if(q!=NULL)
			while(p!=q->sau)
			{
				printf("\n%s",p->nd);
				p=p->sau;
			}	
		}
		
	}
}
 void Chencuoi(Node *&dau)
 {
 	Node *p,*q;
	char tam1[80];	
  	p = new Node;
  	cout<<" nhap noi dung muon chen :";
  	cin.getline(tam1,80);
  	strcpy(p->nd, tam1);
  	p->truoc =NULL;
    p->sau = NULL;
    q=dau;
	while(q->sau!= NULL)
	{
		q=q->sau;
		}	
		q->sau=p;
		p->truoc=q;
 }
void xoadong(Node *&dau,int i)
{
	nut *p,*t,*s;
	int k=1;
	p=dau;
	while((p!=NULL)&&(k!=i))
	{
		p=p->sau;
		k=k+1;
	}
	// truong hop p==dau
	if(p!=NULL)
	{
		if(p==dau)
		{
			dau=dau->sau;
			dau->truoc=NULL;
		
		}
		else
	// truong hop p nut cuoi
		if(p->sau=NULL)
		{
		t=p->truoc;
		t->sau=NULL;
		}
			else
		if((p!=dau)&&(p->sau!=NULL))
		{
			t=p->truoc;
			s=p->sau;
			t->sau=s;
			s->truoc=t;
		}
		delete p;	
	}
}
void xoadongij(Node *&dau,int i,int j)
{
	int k=j-i+1;
	for(k=i;k<=j;k++)
		xoadong(dau,i);
}
//----chen noi dung dong i sau dong k----//
//void chen(Node *&dau,int i,int k)
//{
//	Node *p,*t;
//	
//}
void chepij(Node *dau, int i, int j, Node *&dau1)
{
	int dem;
	Node *p,*q,*t,*l;
	if(j >= i)
	{
		// tim i
		dem = 1;
		p = dau;
		while(p != NULL && dem != i)
		{
			p = p->sau;
			dem += 1;
		}
		if(p != NULL)
		{
			// tim j
			q = p;
			while(q != NULL && dem != j)
			{
				q = q->sau;
				dem = dem+1;
			}
			// in ra dong i den dong j.
			if(q != NULL)
			while(p != q->sau)
			{
				
				t = new Node;
				strcpy(t->nd,p->nd);
				t->sau = NULL;
				t->truoc = NULL;
				if (dau1 == NULL)
					dau1 = t;
				else
				{
					l->sau=t;
					t->truoc=l;
				}
				l = t;
				p = p->sau;
			}
		}
	}
}
void chendongij(Node *&dau,int i, int j, int k)
{
	int m;
	Node *a,*b,*w;
	a = dau;
	m = 1;
	chepij(dau,i,j,dau1);
	while(a != NULL && m!=k)
	{
		a = a->sau;
		m = m+1;
	}
	if(a != NULL)
	{ 
		// a tro den dong k
		b = dau1;
		while(b->sau != NULL)
		b = b->sau;
		// b la dong cuoi cua ds dau1
		w = a->sau; // dong sau dong k
		a->sau = dau1;
		dau1->truoc = a;
		b->sau = w;
		w->truoc = b;
	}
}
int main()
{
	nhap(dau);
	duyetvb(dau);
	inij(dau,1,3);
	cout<<"\n--------------------------------------\n"<<endl;
	Chencuoi(dau);
	duyetvb(dau);
	cout<<"\n -----------------------------------------------\n"<<endl;
 	cout<<"\n xoa tu dong 3 den 4 \n";
	xoadongij(dau,3,4);
	duyetvb(dau);
	cout<<"\n --------------------------------------------------\n "<<endl;
	cout<<"\n chen dong 2->4 vao sau dong 6 \n";
	chendongij(dau,2,4,6);
	duyetvb(dau);
}

