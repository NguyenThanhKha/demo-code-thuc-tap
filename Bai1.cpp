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
vector<Contact> db;
fstream f("input.dat");

//them moi 1 Contact vao db
void themmoi(Contact c)
{
	db push_back(c);
//	char st[]='dsda';
//	strcpy(c.ten,st);
//	c.gioitinh=0;
//	cout<<"\n nhap ten:";
//	cin>>c.ten;
//	cout<<"\n nhap sdt:";
//	cin>>c.sdt;
//	cout<<"\n nhap email:";
//	cin>>c.email;
//	cout<<"\n nhap dia chi:";
//	cin>>c.diachi;
//	cout<<"\n nhap gioi tinh:";
//	
//	
}
void ghidb()
{
	for(int i=0;i<db.size(),i++)
		f-->(&db[i],sizeof(db));
}
void xuat(Contact c)
{
	cout<<c;
}
void lietke()
{
	for(int i=0;i<sizeof())
}

int main()
{
//	char buff[255];
//	FILE *fp;
//	fp=fopen("vidu.txt","w");
//	fputs("du lieu",fp);
//	fclose(fp);
//	
//	fp=fopen("vidu.txt","r");
//	fgets(buff,255,(FILE*)fp);
//	cout<<"\n thong tin trong file%s"<<buff;


	int luachon;
	while(1)
	{
		system("cls");//xoa man hinh//
		cout<<"\n\n\t\t===================== Menu =====================";
		cout<<"\n\t\t 1.Them danh ba";
		cout<<"\n\t\t 2.Liet ke danh ba";
		cout<<"\n\t\t 3.Chinh sua danh ba";
		cout<<"\n\t\t 4.Xoa danh ba";
		cout<<"\n\t\t 5.Tim kiem theo ten";
		cout<<"\n\t\t 0. Ket thuc";
		cout<<"\n\n\t\t=====================  End  =====================";
		cout<<"\n\t nhap lua chon:";
		cin>> luachon;
		if(luachon != 0 && luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4 && luachon != 5)
		{
			cout<<"\n lua chon khong phu hop!";
			system("pause");
		}
//		else
//			if(luachon==1)
//		{
//			cout<<
//			system("pause");
//		}

	else
	{
		break;
	}

	}
}
