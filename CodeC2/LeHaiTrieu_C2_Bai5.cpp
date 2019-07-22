//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
////Câu 5.1:
//#define MAX 100
//int a[MAX];
//int sp;
//
////Câu 5.2:
//void Init (int a[], int &sp)
//{
//	sp = -1;
//}
// 
////Câu 5.3:
//int IsEmpty (int a[], int sp)
//{
//	if (sp == -1)
//		return 1;
//	return 0;
//}
//
////Câu 5.4:
//int IsFull (int a[], int sp)
//{
//	if (sp == MAX-1)
//		return 1;
//	return 0;
//}
//
////Câu 5.5:
//int Push (int a[], int &sp, int x)
//{
//	if (sp < MAX-1)
//	{
//		a[++sp] = x;
//		return 1;
//	}
//	return 0;
//}
//
////Câu 5.6:
//int Pop (int a[], int &sp, int x)
//{
//	if (sp != -1)
//	{
//		x = a[sp--];
//		return 1;
//	}
//	return 0;
//}
//
////Xuất stack
//void Process_Stack (int a[], int sp)
//{
//	for (int i = 0; i <= sp; i++)
//		cout<<a[i]<<"\t";
//	cout<<endl;
//}
//
//int main()
//{
//	int choice = 0;
//	int x, i;
//	system ("cls");
//	cout<<"--------------BAI TAP 5, CHUONG 1, STACK (NGAN XEP)--------------"<<endl;
//	cout<<"1. Khoi tao STACK rong"<<endl;
//	cout<<"2. Kiem tra STACK co rong khong"<<endl;
//	cout<<"3. Kiem tra STACK co day khong"<<endl;
//	cout<<"4. Them phan tu vao STACK"<<endl;
//	cout<<"5. Lay phan tu ra khoi STACK"<<endl;
//	cout<<"6. Xuat STACK"<<endl;
//	cout<<"7. Thoat"<<endl;
//	do
//	{
//		cout<<"Vui long chon so de thuc hien: ";
//		cin>>choice;
//		switch (choice)
//		{
//		case 1:
//			Init (a, sp);
//			cout<<"Ban vua khoi tao thanh cong STACK rong"<<endl;
//			break;
//		case 2:
//			i= IsEmpty (a, sp);
//			if (i == 0)
//				cout<<"STACK khong rong!"<<endl;
//			else cout<<"STACK rong!"<<endl;
//			break;
//		case 3:
//			i= IsFull (a, sp);
//			if (i == 1)
//				cout<<"STACK da day!"<<endl;
//			else cout<<"STACK chua day!"<<endl;
//			break;
//		case 4:
//			cout<<"Nhap gia tri can them vao STACK x="<<endl;
//			cin>>x;
//			i = Push (a, sp, x);
//			if (i!=0)
//			{
//				cout<<"Da them thanh cong x="<<x<<" vao STACK!"<<endl;
//				cout<<"Danh sach sau khi them:"<<endl;
//				Process_Stack (a, sp);
//			}
//			else cout<<"Danh sach day! Khong the them x="<<x<<" vao STACK"<<endl;
//			break;
//		case 5:
//			cout<<"Nhap gia tri can lay khoi STACK x="<<endl;
//			cin>>x;
//			i = Pop (a, sp, x);
//			if (i!=0)
//			{
//				cout<<"Da lay thanh cong x="<<x<<" khoi STACK!"<<endl;
//				cout<<"Danh sach sau khi lay:"<<endl;
//				Process_Stack (a, sp);
//			}
//			else cout<<"Danh sach rong! Khong co phan tu nao!"<<endl;
//			break;
//		case 6:
//			cout<<"Danh sach hien tai la: "<<endl;
//			Process_Stack(a, sp);
//			break;
//		case 7:
//			cout<<"---GOODBYE---"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while (choice != 7);
//	system ("pause");
//	return 0;
//}