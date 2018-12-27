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
//char *fileName = "danhba.dat";
vector<Contact> db;
void docDBTuFile();
void ghiBDVaoFile();
void themMoi(Contact c);
void inContact(Contact c);
//void inDanhBa();
void docDBTuFile()
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
void ghiDBVaoFile()
{
	int size = db.size();
	FILE*f;
	f=fopen("danhba.dat","wb");
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
void inContact()
{
	for(int i=0;i<db.size();i++)
	{
	cout<<"so dt:"<<db[i].sdt<<"\n";
	cout<<"ten:"<<db[i].ten<<"\n";
	cout<<"-----------------------\n";
	}
}
//void inDanhBa()
//{
////	int size = db.size();
//	for(int i = 0; i <db. size;i++)
//	{
//		inContact(db[i]);
//	}
//}
//void menu(Contact c)
//{
//		int luachon;
//	while(1)
//	{
//		system("cls");//xoa man hinh//
//		cout<<"\n\n\t\t===================== Menu =====================";
//		cout<<"\n\t\t 1.Them danh ba";
//		cout<<"\n\t\t 2.Liet ke danh ba";
//		cout<<"\n\t\t 3.Chinh sua danh ba";
//		cout<<"\n\t\t 4.Xoa danh ba";
//		cout<<"\n\t\t 5.Tim kiem theo ten";
//		cout<<"\n\t\t 0. Ket thuc";
//		cout<<"\n\n\t\t=====================  End  =====================";
//		cout<<"\n\t nhap lua chon:";
//		cin>> luachon;
//		if(luachon != 0 && luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4 && luachon != 5)
//		{
//			cout<<"\n lua chon khong phu hop!";
//			system("pause");
//		}
//		else
//			if(luachon==1)
//		
//		{
//			cout<<"\n"<<endl;
//			themMoi(c);
//			system("pause");
//		}
//			
//		{
//			break;
//		}
//	}
//}


int main()
{
	docDBTuFile();
//	inDanhBa();
	Contact c1;
	strcpy(c1.sdt, "456");
	strcpy(c1.ten,"an");
	themMoi(c1);
	inContact();
//	Contact c2;
//	strcpy(c2.sdt,"134");
//	strcpy(c2.ten,"anh");
//	themMoi(c2);
//	cout<<"Danh ba:\n";
//	inDanhBa();
////	menu(c1);

}
