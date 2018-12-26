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
 int thang[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
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
 int timstt(ngaythang n)
 {
 	int stt=0;
 	for(int i = 0; i < n.thang;i++)
 		stt+=thang[i];
 		stt+=n.ngay;
 	if(namnhuan(n.nam) == 1)
		stt + 1;
	 return stt;
}

ngaythang ngaytustt(int stt,int nam)
{
	ngaythang ngaycantim;
	int i=1;
	while( stt > thang[i] ){
		stt -= thang[i];
		i++;

		if(namnhuan(nam) == 1 && i ==2)
		thang[i]==29;
	}
	ngaycantim.ngay= stt;
	ngaycantim.thang=i;
	ngaycantim.nam=nam;
	thang[2]=28;
	return ngaycantim;
}
ngaythang tongngaythang(ngaythang n,int x)
{
	int kq=x + timstt(n);
	int nam=n.nam;
	if(kq<=365)
		return ngaytustt(kq,nam);
	else
		if(namnhuan(nam)==1)
			if(kq==365)
				return ngaytustt(kq,nam);
			else
				return ngaytustt(kq-365,nam+1);
		else
			return ngaytustt(kq-365,nam+1);
}
void inngay(ngaythang n)
{
	cout<<n.ngay<<"-"<<n.thang<<"-"<<n.nam<<endl;
}
int main()
{
	int a;
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
 	cout<<"\n thang :"<<x.thang;
 	t[0]=st[6];
 	t[1]=st[7];
 	t[2]=st[8];
 	t[3]=st[9];
 	x.nam=atoi(t);
 	cout<<"\n nam :"<<x.nam;
 	if(namnhuan(x.nam))
 		cout<<"\n la nam nhuan";
 	 else
 	 	cout<<"\n khong phai nam nhuan";
 	cout<<"\n so thu tu:"<<timstt(x);
 	cout<<"\n nhap so nguyen a:";
	cin>>a;
 	cout<<"\n cong :";
	inngay(tongngaythang(x,a));
 }
