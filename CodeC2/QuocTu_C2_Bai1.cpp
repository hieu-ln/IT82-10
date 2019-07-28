#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int n;

void input(int a[],int &n)
{
	cout << "nhap do dai danh sach: ";
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cout << "nhap phan tu a[ " << i << " ]: ";
		cin >> a[i];
	}
}

void output(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout << "\t" << a[i];
}

int search(int a[],int n,int x)
{
	int i=0;
	while((i<n)&&(x>=0))
	{
		if(i==x)
			return 1;
		i++;
	}
	return 0;
}

void add_last(int a[],int &n)
{
	if(n>0)	
	{
		n++;
		cout << "nhap gia tri them: ";
		cin >> a[n-1];
	}
}

void delete_last(int a[],int &n)
{
	if(n>0)
		n--;
}

void delete_i(int a[],int &n,int x)
{
	int i=0;
	while((i<n)&&(x>=i))
	{
		if(i==x)
		{
			for(int j=i;j<n;j++)
				a[j]=a[j+1];
			n--;
		}
		i++;
	}
}

void delete_a(int a[],int &n,int x)
{
	int i=0;
	while(i<n)
	{
		if(a[i]==x)
		{
			for(int j=i;j<n;j++)
				a[j]=a[j+1];
			n--;
		}
		i++;
	}
}

int main()
{
	int x;
	char z;
	cout << "--------------------MENU------------------------" << endl;
	cout << "1. Nhap danh sach." << endl;
	cout << "2. Xuat danh sach." << endl;
	cout << "3. Tim 1 phan tu trong danh sach." << endl;
	cout << "4. Them 1 phan tu cuoi danh sach." << endl;
	cout << "5. Xoa cuoi danh sach." << endl;
	cout << "6. Xoa 1 phan tu tai vi tri i trong danh sach." << endl;
	cout << "7. Xoa 1 gia tri trong danh sach." << endl;
	cout << "8. Thoat." << endl;
	do
	{
		cout << "moi ban chon: ";
		cin >> z;
		switch(z)
		{
			case '1':
				input(a,n);
				break;
			case '2':
				output(a,n);
				break;
			case '3':
				cout << "nhap vi tri can tim: ";
				cin >> x;
				if(search(a,n,x)==1)
					cout << "tim thay gia tri tai vi tri " << x << " la " << a[x] << endl;
				else
					cout << "khong tim thay." << endl;
				break;
			case '4':
				add_last(a,n);
				output(a,n);
				break;
			case '5':
				delete_last(a,n);
				output(a,n);
				break;
			case '6':
				cout << "nhap vi tri can xoa: ";
				cin >> x;
				delete_i(a,n,x);
				output(a,n);
				break;
			case '7':
				cout << "nhap gia tri can xoa: ";
				cin >> x;
				delete_a(a,n,x);
				output(a,n);
				break;
			case '8':
				cout << "good bye." << endl;
				break;
			default:
				cout << "nhap sai." << endl;
				break;
		}
	}while(z!='8');
	system("pause");
	return 0;
}
