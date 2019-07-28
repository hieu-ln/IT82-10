#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;	
};
Node *first;

void init()
{
	first=NULL;
}

void Process_list()
{
	Node *p;
	p = first;
	while(p!=NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}

Node *search(int x)
{
	Node *p=first;
	while((p!=NULL)&&(p->info!=x))
		p=p->link;
	return p;
}

void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while(q->link!=NULL)
			q = q->link;
		q->link = p;
	}
}

int delete_first()
{
	if(first!=NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

int delete_last()
{
	if(first!=NULL)
	{
		Node *p,*q;
		p = first;
		q = NULL;
		if(p!=NULL)
			while(p->link!=NULL)
			{
				q=p;
				p=p->link;
				
			}
		if(p!=first)
			q->link=NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int main()
{
	int x;
	char z;
	cout << "--------------------MENU-----------------" << endl;
	cout << "1. Khoi tao danh sach." << endl;
	cout << "2. Duyet danh sach." << endl;
	cout << "3. Tim 1 phan tu trong danh sach." << endl;
	cout << "4. Them 1 phan tu vao dau danh sach." << endl;
	cout << "5. Them 1 phan tu vao cuoi danh sach." << endl;
	cout << "6. Xoa 1 phan tu dau danh sach." << endl;
	cout << "7. Xoa 1 phan tu cuoi danh sach." << endl;
	cout << "8. Thoat." << endl;
	do
	{
		cout << "moi lua chon: ";
		cin >> z;
		switch(z)
		{
			case '1':
				init();
				cout << " khoi tao thanh cong." << endl;
				break;
			case '2':
				Process_list();
				break;
			case '3':
				cout << "nhap gia tri phan tu can tim: ";
				cin >> x;
				cout << search(x)->info << endl;
				break;
			case '4':
				cout << "nhap gia tri can them: ";
				cin >> x;
				Insert_first(x);
				break;
			case '5':
				cout << "nhap gia tri can them: ";
				cin >> x;
				Insert_last(x);
				break;
			case '6':
				delete_first();
				Process_list();
				break;
			case '7':
				delete_last();
				Process_list();
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
