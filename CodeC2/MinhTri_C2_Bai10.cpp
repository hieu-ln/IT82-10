////STACK sử dụng DSLK đơn
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
////10.1: Khai báo cấu trúc STACK
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *sp;
//
////10.2: Khởi tạo STACK rỗng
//void init()
//{
//	sp = NULL;
//}
//
////10.3: Ktra STACK rỗng
//int isEmpty()
//{
//	if(sp == NULL)
//		return 1;
//	return 0;
//}
//
////10.4: Thêm pt vào stack
//void Push(int x)
//{
//	Node *p = new Node;
//	p ->info = x;
//	p ->link = sp;
//	sp = p;
//}
//
////10.5: Lấy pt ra khỏi STACK
//int Pop(int &x)
//{
//	if(sp != NULL)
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
//		cout << p->info << "\t";
//		p = p->link;
//	}while(p != NULL);
//	cout << endl;
//}
//
//int main()
//{
//	int choice, x, i;
//	system("cls");
//	cout << "------ BAI TAP 10, CHUONG 2, STACK ------" << endl;
//	cout << "1. Khoi tao STACK rong" << endl;
//	cout << "2. Them pt vao STACK" << endl;
//	cout << "3. Lay pt ra khoi STACK" << endl;
//	cout << "4. Xuat STACK" << endl;
//	cout << "5. Thoat" << endl;
//	do{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout << "Ban vua khoi tao STACK rong thanh cong!" << endl;
//				break;
//			case 2:
//				cout << "Vui long nhap gia tri x = ";
//				cin >> x;
//				Push(x);
//				cout << "STACK sau khi them la: ";
//				Process_Stack();
//				break;
//			case 3:
//				i = Pop(x);
//				cout << "Phan tu lay ra tu STACK la x = " << x << endl;
//				cout << "STACK sau khi lay ra la: ";
//				Process_Stack();
//				break;
//			case 4:
//				cout << "STACK hien tai la: ";
//				Process_Stack();
//				break;
//			case 5:
//				cout << "Goodbye....!" << endl;
//				break;
//			default:
//				break;
//		}
//	}while(choice != 5);
//	system("pause");
//	return 0;
//}