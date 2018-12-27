#include<string>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;
//khai bao cau truc cau hoi
struct cauhoidapan{
	string cauhoi;
	string A;
	string B;
	string C;
	string DA;
	
};
//khai bao vector
vector<cauhoidapan> ds;
//khai bao ham 
void chonde();
bool kiemtra(string A,string B);
void xuat(cauhoidapan ds);
void docde();
void xuat(cauhoidapan ds);
//doc file chon de
void chonde()
{
	int a;
	cout<<"ban hay chon de:";
	cin>>a;
	{
		if(a==1){
	ifstream f("de1-.txt");
	int sl;
	cauhoidapan de;
	string s,ans;
	getline(f,s);
	//doi string sang int
	sl=atoi(s.c_str());
	for(int i=0;i<sl;i++)
	{
		getline(f,s) ;de.cauhoi=s;
		getline(f,s) ;de.A=s;
		getline(f,s) ;de.B=s;
		getline(f,s) ;de.C=s;
		getline(f,s) ;de.DA=s;
	 
		ds.push_back(de);
		
	}
	}
	if(a==2){
	ifstream fp("de2.txt");
	int sll;
	cauhoidapan de;
	string s1,ans1;
	getline(fp,s1);
	//doi string sang int
	sll=atoi(s1.c_str());
	for(int i=0;i<sll;i++)
	{
		getline(fp,s1) ;de.cauhoi=s1;
		getline(fp,s1) ;de.A=s1;
		getline(fp,s1) ;de.B=s1;
		getline(fp,s1) ;de.C=s1;
		getline(fp,s1) ;de.DA=s1;
	 
		ds.push_back(de);
		
	}
	}
	}
	docde();
	

}
//ham kiem tra string
bool kiemtra(string A,string B)
{
	if(A.compare(B)==0)
			return true;
		else
			return false;
		
}

void xuat(cauhoidapan ds,int &diem)
{
	
	string dapan;
	cout<<ds.cauhoi<<endl;
	cout<<ds.A<<endl;
	cout<<ds.B<<endl;
	cout<<ds.C<<endl;
	cout<<"nhap dap an:";
	cin>>dapan;
	if(kiemtra(ds.DA,dapan))
		diem+=2;
	
	
	
}

void docde()
{
	int diem=0;
	for(int i=0;i<ds.size();i++)
		xuat(ds[i],diem);
		cout<<"\n diem cua ban la:"<<diem;
}
int main()
{
	
	chonde();
	
}
