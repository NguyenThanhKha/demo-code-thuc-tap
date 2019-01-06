#include <iostream> 
#include <fstream> 
#include <iostream> 
using namespace std;
struct phanso{
	int tu;
	int mau;
};
void nhap(int n,int p,int q)
{
    ofstream f ("File Demo int.txt",ios::in);
    f<<" "<< n;
    f<<" "<< p;
    f<<" "<< q;
    f.close();
}
int sosanh(phanso ps,phanso ps1)
{
	if(ps.tu/ps.mau > ps1.tu/ps1.mau)
		swap(ps,ps1);
}

void xuat(phanso ps )
{
	fstream f("File Demo out.txt",ios::out);
	cout<<ps.tu<<"/"<<ps.mau;
	f.close();
}
int main()
{nhap(10,3,2);

}
