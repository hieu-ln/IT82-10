//#include <iostream>
//using namespace std;
//#define MAX 100
//
//void init(int a[], int &space)
//{
//	space=-1;
//	cout << "Stack duoc khoi tao\n";
//}
//
//void push(int a[], int &space)
//{
//	int x;
//	cout<<"Nhap gia tri can them: ";
//	cin>>x;
//	if(space < MAX-1)
//	{
//		a[++space]=x;
//		cout<<"Da them phan tu thanh cong\n";
//	}
//	else
//		cout<<"Stack day! Khong the them phan tu\n";
//}
//
//void pop(int a[], int &space, int &x)
//{
//	if(space!=-1)
//	{
//		x=a[space--];
//		cout << "Lay phan tu thanh cong\n";
//	}
//	else
//		cout << "Stack rong! Khong the lay phan tu\n";
//}
//
//void isFull(int a[], int &space)
//{
//	if(space==MAX-1)
//		cout<<"Stack day!\n";
//	else
//		cout<<"Stack chua day!\n";
//}
//
//void isEmpty(int a[], int &space)
//{
//	if(space==-1)
//		cout<<"Stack rong!\n";
//	else
//		cout<<"Stack khong rong!\n";
//}
//
//int main()
//{
//	int a[MAX], space,x;
//	int select;
//	cout << "----------BAI TAP 5, CHUONG 2, STACK (NGAN XEP- DS DAC)-----------";
//	cout <<"1. Khoi tao Stack rong\n";
//	cout <<"2. Kiem tra Stack rong\n";
//	cout <<"3. Kiem tra Stack day\n";
//	cout <<"4. Them 1 phan tu vao Stack\n";
//	cout <<"5. Xoa 1 phan tu vao Stack\n";
//	cout <<"6. Thoat\n";
//	do{
//		cout<<"Chon buoc can thuc hien: ";
//		cin>>select;
//		switch(select)
//		{
//		case 1:
//			init(a, space);
//			break;
//		case 2:
//			isEmpty(a, space);
//			break;
//		case 3:
//			isFull(a, space);
//			break;
//		case 4:
//			push(a, space);
//			break;
//		case 5:
//			pop(a, space, x);
//			break;
//		default:
//			break;
//		}
//	}while(select < 6);
//	cout << "Da thoat!\n";
//	system("pause");
//	return 0;
//} 