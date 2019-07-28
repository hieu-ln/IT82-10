#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *front,*rear;

void init()
{
	front = NULL;
	rear = NULL;
}

int isEmpty()
{
	if(rear == NULL)
		return 1;
	return 0;
}

void push(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int pop(int x)
{
	if(front != NULL)
	{
		Node *p = front;
		x = p->info;
		front = front->link;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void process_list()
{
	Node *p;
	p = front;
	while(p!=NULL)
	{
		cout << p->info << "\t";
		p=p->link;
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
	cout << "4. Them 1 phan tu vao danh sach." << endl;
	cout << "5. Xoa 1 phan tu trong danh sach." << endl;
	cout << "6. Thoat." << endl;
	do
	{
		cout << "\nmoi lua chon: ";
		cin >> z;
		switch(z)
		{
			case '1':
				init();
				cout << " khoi tao thanh cong." << endl;
				break;
			case '2':
				process_list();
				break;
			case '3':
				if(isEmpty()==1)
					cout << "danh sach rong." << endl;
				else
					cout << "danh sach khong rong." << endl;
				break;
			case '4':
				cout << "nhap gia tri can them: ";
				cin >> x;
				push(x);
				break;
			case '5':
				if(pop(x)==1)
					cout << "xoa thanh cong." << endl;
				else
					cout << "xoa khong thanh cong." << endl;
				process_list();
				break;
			case '6':
				cout << "good bye." << endl;
				break;
			default:
				cout << "nhap sai." << endl;
				break;
		}
	}while(z!='6');
	system("pause");
	return 0;
}
