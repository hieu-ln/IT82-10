#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int front, rear;

void init(int a[],int &front,int &rear)
{
	front = -1;
	rear = -1;
}

void process_list(int a[],int front,int rear)
{
	for(int i=front;i<=rear;i++)
		cout << "\t" << a[i];
}

int isEmpty()
{
	if(front == -1)
		return 1;
	return 0;
}

int isFull()
{
	if(rear-front == MAX-1)
		return 1;
	return 0;
}

int push(int a[],int &front,int &rear, int x)
{
	if(rear-front == MAX-1)
		return 0;
	else
	{
		if(front == -1)
			front = 0;
		if(rear == MAX-1)
		{
			for(int i=front;i<=rear;i++)
				a[i-front] = a[i];
			rear = MAX-1-front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}

int pop(int a[],int &front,int &rear,int &x)
{
	if(front == -1)
		return 0;
	else
	{
		x = a[front++];
		if(front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
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
		cout << "\nmoi lua chon: ";
		cin >> z;
		switch(z)
		{
			case '1':
				init(a,front,rear);
				cout << " khoi tao thanh cong." << endl;
				break;
			case '2':
				process_list(a,front,rear);
				break;
			case '3':
				if(isEmpty()==1)
					cout << "danh sach rong." << endl;
				else
					cout << "danh sach khong rong." << endl;
				break;
			case '4':
				if(isFull()==1)
					cout << "danh sach day." << endl;
				else
					cout << "danh sach chua day." << endl;
				break;
			case '5':
				cout << "nhap gia tri can them: ";
				cin >> x;
				push(a,front,rear,x);
				break;
			case '6':
				pop(a,front,rear,x);
				cout << endl;
				process_list(a,front,rear);
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
