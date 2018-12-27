#include<string>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct cauhoidapan{
	string cauhoi;
	string A;
	string B;
	string C;
	string DA;
	
};
vector<cauhoidapan> ds;
void chonde();
bool kiemtra(string A,string B);
void xuat(cauhoidapan ds);
void docde();
void xuat(cauhoidapan ds);

void chonde()
{
	ifstream f("de1.txt");
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
	docde();
	

}
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
	cout<<"nhap dap an";
	cin>>dapan;
	if(kiemtra(ds.DA,dapan))
		diem+=2;
	
	
	
}
void docde()
{
	int diem=0;
	for(int i=0;i<ds.size();i++)
		xuat(ds[i],diem);
		cout<<"\n"<<diem;
}
int main()
{
	
	chonde();
	
}
