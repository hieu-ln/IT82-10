//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//
////Câu 10.1:
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *sp;
//
////Câu 10.2:
//void Init ()
//{
//	sp=NULL;
//}
//
////Câu 10.3:
//int IsEmpty ()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//
////Câu 10.4:
//void Push (int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//
////Câu 10.5
//int Pop (int &x)
//{
//	if (sp != NULL)
//	{
//		Node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
////Xuất STACK
//void Process_Stack()
//{
//	Node *p = sp;
//	do{
//		cout<<p->info<<"\t";
//		p = p->link;
//	}while (p !=NULL);
//	cout<<endl;
//}
//
//int main()
//{
//	int choice, x, i;
//	system ("cls");
//	cout<<"----------BAI 10, CHUONG 2, STACK (NGAN XEP DSLK)----------"<<endl;
//	cout<<"1. Khoi tao STACK rong"<<endl;
//	cout<<"2. Them phan tu vo STACK"<<endl;
//	cout<<"3. Lay phan tu ra khoi STACK"<<endl;
//	cout<<"4. Xuat STACK"<<endl;
//	cout<<"5. Thoat"<<endl;
//	do
//	{
//			cout<<"Vui long chon so de thuc hien: ";
//			cin>>choice;
//			switch (choice)
//			{
//			case 1:
//				Init();
//				cout<<"Ban vua khoi tao STACK rong thanh cong!"<<endl;
//				break;
//			case 2:
//				cout<<"Vui long nhap vao gia tri x=";
//				cin>>x;
//				Push (x);
//				cout<<"STACK sau khi them la: "<<endl;
//				Process_Stack();
//				break;
//			case 3:
//				i = Pop (x);
//				if (i == 1)
//				{
//					cout<<"Phan tu lay ra tu STACK la x="<<x<<endl;
//					cout<<"STACK sau khi lay ra là: "<<endl;
//					Process_Stack();
//				}
//				else cout<<"STACK rong! khong co phan tu de xoa!"<<endl;
//				break;
//			case 4:
//				cout<<"STACK hien tai là: "<<endl;
//				Process_Stack();
//				break;
//			case 5:
//				cout<<"GOODBYE!"<<endl;
//				break;
//			default:
//				break;
//			}
//	}while (choice !=5);
//	system ("pause");
//	return 0;
//}