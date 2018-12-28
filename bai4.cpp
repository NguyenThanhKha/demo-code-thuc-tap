#include<string>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;
fstream f;
fstream fp;
void taomoi(int a[100][100],int &n)
{
	cout<<"nhap n:";
	cin>>n;
	fp.open("doc1.txt",ios::out);
	fp<<n<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			cout<<"tu "<<i<<"den "<<j<<" ";
			cin>>a[i][j];
		fp<<a[i][j]<<" ";
		}
		cout<<endl;
//		fp<<endl;
	}
	fp.close();
}
//void DocFile(int a[100][100],int n)
//{
//	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			f>>a[i][j];
//		}
//	}
//}
void XuatFile(int a[100][100],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
			cout<<endl;
	}
}
int main(){
	int n,a[100][100];
	taomoi(a,n);
//	f.open("doc.txt",ios::in);
//	f>>n;
//	DocFile(a,n);
	XuatFile(a,n);
	}
