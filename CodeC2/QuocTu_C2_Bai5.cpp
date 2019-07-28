#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int sp;

void init(int a[],int &sp)
{
	sp=-1;
}

int push(int a[],int &sp,int x)
{
	if(sp<MAX-1)
	{
		a[++sp]=x;
		return 1;
	}
	return 0;
}

void process_list(int a[],int sp)
{
	int i=0;
	while(i<=sp)
	{
		cout << "\t" << a[i];
		i++;
	}
}

int pop(int a[],int &sp,int &x)
{
	if(sp!=-1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}

int isFull(int a[],int sp)
{
	if(sp==MAX-1)
		return 1;
	return 0;
}

int isEmpty(int a[],int sp)
{
	if(sp==-1)
		return 1;
	return 0;
}

int main()
{
	int x;
	char z;
	cout << "--------------------MENU-----------------" << endl;
	cout << "1. Khoi tao danh sach." << endl;
	cout << "2. Duyet danh sach." << endl;
	cout << "3. Kiem tra danh sach rong." << endl;
	cout << "4. Kiem tra danh sach day." << endl;
	cout << "5. Them 1 phan tu vao danh sach." << endl;
	cout << "6. Xoa 1 phan tu trong danh sach." << endl;
	cout << "7. Thoat." << endl;
	do
	{
		cout << "moi lua chon: ";
		cin >> z;
		switch(z)
		{
			case '1':
				init(a,sp);
				cout << " khoi tao thanh cong." << endl;
				break;
			case '2':
				process_list(a,sp);
				break;
			case '3':
				if(isEmpty(a,sp)==1)
					cout << "danh sach rong." << endl;
				else
					cout << "danh sach khong rong." << endl;
				break;
			case '4':
				if(isFull(a,sp)==1)
					cout << "danh sach day." << endl;
				else
					cout << "danh sach chua day." << endl;
				break;
			case '5':
				cout << "nhap gia tri can them: ";
				cin >> x;
				push(a,sp,x);
				break;
			case '6':
				cout << "nhap vi tri can xoa: ";
				cin >> x;
				pop(a,sp,x);
				break;
			case '7':
				cout << "good bye." << endl;
				break;
			default:
				cout << "nhap sai." << endl;
				break;
		}
	}while(z!='7');
	system("pause");
	return 0;
}
