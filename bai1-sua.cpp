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
//khai bao vector
vector<Contact> db;
//khai bao cac thu vien
void docfile();
void ghifile();
void themmoi(Contact c);
void inContact(Contact c);
void chinhsuasdt(char sdt[]);
void xoa(char xoa[]);
void capnhat(Contact c);
//doc file .dat
void docfile()
{
	db.clear();
	FILE *f;
	f=fopen("danhba.dat","rb");
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
// ghi vao file .dat
void ghifile()
{
	FILE*f=fopen("danhba.dat","wb");
	Contact c;
	for(int i=0;i<db.size();i++)
		fwrite(&db[i],sizeof(db),1,f);
		fclose(f);
}
//in danh sach 
void inContact()
{
	for(int i= 0;i<db.size();i++)
	{
		cout<<"ten:"<<db[i].ten;
		cout<<"so dien thoai:"<<db[i].sdt;
		cout<<"dia chi email:"<<db[i].email;
		cout<<"dia chi :"<<db[i].diachi;
		cout<<"gioi tinh:"<<db[i].gioitinh;
	}
}
void lietke()
{
	for(int i=0 ; i <db.size() ;i++){
		cout<<"ten la: "<<db[i].ten<<endl;
		cout<<"sdt la: "<<db[i].sdt<<endl;
		cout<<"email la: "<<db[i].email<<endl;
		cout<<"dia chi la: "<<db[i].diachi<<endl;	
		cout<<"gioi tinh la: "<<db[i].gioitinh<<endl;
	}

	
}
// them moi 1 Contact
void themmoi()
{
	Contact c;
	db.push_back(c);
	ghifile();
	FILE*f=fopen("db.dat","wb");
	for(int i = 0 ; i < db.size() ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
}
void chinhsuasdt(char sdt[])
{
	for(int i=0;i<db.size();i++)
		if(strcmp(db[i].sdt,sdt)==0)
		{
			strcpy(db[i].ten,"an");
			for(int i=0;i<db.size();i++)
			{
				cout<<"ten:"<<db[i].ten;
			}
		}
	
}
void xoa(char xoa[])
{
	for(int i=0;i<db.size();i++)
	{
		if(strcmp(db[i].ten,xoa)==0)
			db.erase(db.begin());
	}
}
void capnhat()
{
	themmoi();
	lietke();
	
	FILE*f=fopen("danhba.dat","wb");
	Contact c;
	for(int i=0;i<db.size();i++)
		fwrite(&db[i],sizeof(db),1,f);
		fclose(f);
	//ghi file
}
int main()
{
	docfile();
	Contact c;
	strcpy(c.ten,"nguyen\n");
	themmoi(c);
	Contact c1;
	strcpy(c1.ten,"uyen");
	themmoi(c1);
	inContact();
	
}
