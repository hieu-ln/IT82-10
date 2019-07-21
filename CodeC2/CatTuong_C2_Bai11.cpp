//#include <iostream>
//#include <stdio.h>
//using namespace std;
////11.1 Khai bao cau truc Queue
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *front, *rear;
//
////11.2 Khoi tao Queue rong
//void init()
//{
//	front=NULL;
//	rear=NULL;
//}
//
////11.3 Kiem tra Queue rong
//int isEmpty()
//{
//	if(front==NULL)
//		return 1;
//	return 0;
//}
////11.4 Them phan tu vao Queue
//void Push(int x)
//{
//	Node *p= new Node;
//	p->info=x;
//	p->link=NULL;
//	if(rear==NULL)
//		front=p;
//	else
//		rear->link=p;
//	rear=p;
//}
////11.5 Lay phan tu ra khoi Queue
//int Pop(int &x)
//{
//	if(front!=NULL)
//	{
//		Node *p=front;
//		front=p->link;
//		x=p->info;
//		if(front==NULL)
//		{
//			rear==NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////11.6 Xuat Queue
//void Process_queue()
//{
//	if(front!=NULL)
//	{
//		Node *p = front;
//		cout<<"<---   ";
//		do
//		{
//			cout<<p->info<<"   ";
//			p=p->link;
//		}while(p!=NULL);
//		cout<<"<---"<<endl;
//	}
//}
//int main()
//{
//	int choice, x, i;
//	system("cls");
//	cout<<"----------BAI TAP 11, CHUONG 2, QUEUE(HANG DOI - DSLK)----------"<<endl;
//	cout<<"1.Khoi tao Queue rong\n";
//	cout<<"2.Them phan tu vao Queue\n";
//	cout<<"3.Lay phan tu ra khoi Queue\n";
//	cout<<"4.Kiem tra Queue co rong khong\n";
//	cout<<"5.Xuat Queue\n";
//	cout<<"6.Thoat\n";
//	do
//	{
//		cout<<"\nChon so thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout<<"Khoi tao Queue rong thanh cong!\n";
//				break;
//			case 2:
//				cout<<"Vui long nhap gia tri x= ";
//				cin>>x;
//				Push(x);
//				cout<<"Queue sau khi them la: ";
//				Process_queue();
//				break;
//			case 3:
//				Pop(x);
//				cout<<"Phan tu lay ra tu Queue la x = "<<x<<endl;
//				cout<<"Queue sau khi lay ra la: ";
//				Process_queue();
//				break;
//			case 4:
//				i = isEmpty();
//				if(i==0)
//					cout<<"Queue khong rong! "<<x<<endl;
//				else
//					cout<<"Queue rong!"<<endl;
//				break;
//			case 5:
//				cout<<"Queue hien tai la: ";
//				Process_queue();
//				break;
//			case 6:
//				cout<<"Goodbye!"<<endl;
//				break;
//			default:
//				break;
//		}
//
//	}while(choice!=6);
//	system("pause");
//	return 0;
//}