#include<IOSTREAM>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
struct ngaythang
{
	int ngay;
	int thang;
	int nam;
} ;
void nhap(string &s)
{
	cout<<"nhap du lieu";
	getline(cin,s);
	cout<<s;
	
}
int namnhuan(int nam)
{
	if((nam%4==0&&nam%100!=0)||nam%400==0)
			return 1;
	return 0;
		
}


int main()
{
	char t[4];
	ngaythang x;
	string st;
	nhap(st);
	t[0]=st[0];
	t[1]=st[1];
	x.ngay=atoi(t);
	cout<<"\n ngay :"<<x.ngay;
	t[0]=st[3];
	t[1]=st[4];
	x.thang=atoi(t);
	t[0]=st[6];
	t[1]=st[7];
	t[2]=st[8];
	t[3]=st[9];
	x.nam=atoi(t);
	cout<<x.nam;
	if(namnhuan(x.nam))
		cout<<"\n la nam nhuan";
	 else
	 	cout<<"\n khong phai nam nhuan";
	
}
