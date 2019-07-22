//QUEUE sử dụng DSLK
#include <iostream>
#include <stdio.h>
using namespace std;

//11.1: Khai báo cấu trúc QUEUE
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;

//11.2: Khởi tạo QUEUE rỗng
void init()
{
	front = NULL;
	rear = NULL;
}

//11.3: Ktra QUEUE rỗng
void isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}

//11.4: Thêm pt vào QUEUE
int Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear =p;
}

//11.5: Lấy 1 pt ra khoi QUEUE
int Pop(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//Xuất QUEUE
void Process_Queue()
{
	if(front != NULL)
	{
		Node *p = front;
		cout << "<--  ";
		do{
			cout << p->info << "	";
			p = p->link;
		}while(p != NULL);
		cout << "<--" << endl;
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "------ BAI TAP 11, CHUONG 2, QUEUE(DSLK) ------" << endl;
	cout << "1. Khoi tao QUEUE rong" << endl;
	cout << "2. Them pt vao QUEUE" << endl;
	cout << "3. Lay pt ra khoi QUEUE" << endl;
	cout << "4. Kiem tra QUEUE co rong hay khong" << endl;
	cout << "5. Xuat QUEUE" << endl;
	cout << "6. Thoat" << endl;
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "Ban vua khoi tao QUEUE rong thanh cong!" << endl;
				break;
			case 2:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				i = Push(x);
				cout << "QUEUE sau khi them la: ";
				Process_Queue();
				break;
			case 3:
				i = Pop(x);
				cout << "Phan tu lay ra tu QUEUE la x = " << x << endl;
				cout << "QUEUE sau khi lay ra la: ";
				Process_Queue();
				break;
			case 4:
				i = isEmpty();
				if(i == 0)
					cout << "QUEUE khong rong" << endl;
				else
					cout << "QUEUE rong" << endl;
				break;
			case 6:
				cout << "QUEUE hien tai la: ";
				Process_Queue();
				break;
			case 7:
				cout << "Goodbye....!" << endl;
				break;
			default:
				break;
		}
	}while(choice != 7);
	system("pause");
	return 0;
}
