#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<vector>
#include<iostream>
using namespace std;
typedef struct 
{
	char ten[20];
	char sdt[11];
	char email[20];
	char diachi[50];
	bool gioitinh;
} Contact ;
char *fileName="danhba.dat";
vector<Contact> db;
void docDBTuFile();
void ghiBDVaoFile();
void themMoi(Contact c);
void inContact(Contact c);
void inDanhBa();
int main()
{
	docDBTuFile();
	inDanhBa();
	Contact c1;
	strcpy(c1.sdt, "456");
	strcpy(c1.ten,"an");
	Contact c2;
	strcpy(c2.sdt,"134");
	strcpy(c2.ten,"anh");
	themMoi(c1);
	themMoi(c2);
	cout<<"Danh ba:\n";
	inDanhBa();

}
void docDBTuFile()
{
	db.clear();
	FILE *f;
	f=fopen(fileName,"rb");
	if(f!=NULL)
	{
		while(!feof(f))
		{
			Contact c;
			fread(&c, sizeof(Contact),1,f);
			db.push_back(c);
		}
		fclose(f);
		db.pop_back();
	}
}
void ghiDBVaoFile()
{
	int size = db.size();
	FILE*f;
	f=fopen(fileName,"wb");
	Contact c;
	for(int i = 0; i < size; i++ )
	{
		c=db[i];
		fwrite(&c,sizeof(Contact),1,f);
	}
	fclose(f);
}
void themMoi(Contact c )
{
	db.push_back(c);
	ghiDBVaoFile();
}
void inContact(Contact c)
{
	cout<<"so dt:"<<c.sdt<<"\n";
	cout<<"ten:"<<c.ten<<"\n";
	cout<<"-----------------------\n";
}
void inDanhBa()
{
	int size = db.size();
	for(int i = 0; i < size;i++)
	{
		inContact(db[i]);
	}
}
