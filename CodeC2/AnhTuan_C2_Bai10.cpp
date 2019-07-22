//#include <stdio.h>
//#include <iostream>
//using namespace std; 
//
//struct Node 
//{
//	int info;
//	Node *link;
//};
//Node*sp; 
//
//void init()
//{
//	sp = NULL;
//}
//
//int isEmpty()
//{
//	if(sp==NULL)
//		return -1;
//	return 0;
//}
//
//void Push(int x)
//{
//	Node *p = new Node;
//	p->info=x;
//	p->link=sp;
//	sp=p;
//}
//
//int Pop( int &x)
//{ 
//	if(sp!= NULL){
//		Node *p = sp;
//		x= p->info;
//		sp= p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//void Process_stack()
//{
//	Node *p=sp;
//	do{
//		cout<<p->info<<"   ";
//		p=p->link;
//	} while (p!=NULL);
//	cout<<endl;
//}
//int main()
//{
//	int choice, x, i;
//	cout << "1. Khoi tao Stack rong\n"
//		 << "2. Them phan tu vao Stack\n "
//		 << "3. Lay phan tu ra khoi Stack\n"
//		 << "4. Xuat Stack\n"
//		 << "5. Thoat\n";
//	do
//	{
//		cout<<"\nChon so de thuc hien: ";
//		cin>> choice;
//		switch(choice)
//		{
//		case 1:
//			init();
//			cout<<"Da khoi tao Stack rong thanh cong!\n";
//			break;
//		case 2:
//			cout<<"Nhap gia tri x=";
//			cin>>x;
//			Push(x);
//			cout<<"Stack sau khi them la: ";
//			Process_stack();
//			break;
//		case 3: 
//			Pop(x);
//			cout<<"Phan tu lay ra tu Stack la x= "<<x<<endl;
//			cout<<" Stack sau khi lay ra la: ";
//			Process_stack();
//			break;
//		case 4:
//			cout<< " Stack hien tai la: ";
//			Process_stack();
//			break;
//		case 5:
//			cout<< "Goodbye!"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while (choice!=5);
//	system("pause");
//	return 0;
//} 