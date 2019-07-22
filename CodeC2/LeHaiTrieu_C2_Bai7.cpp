//#include <iostream>
//#include <stdio.h>
//using namespace std;
//#define MAX 100
//
////Câu 7.1:
//int a[MAX];
//int front, rear;
//
////Câu 7.2:
//void Init (int a[], int &front, int &rear)
//{
//	front = -1;
//	rear = -1;
//}
//
////Câu 7.3:
//int IsEmpty (int a[], int &front, int &rear)
//{
//	if (front == rear)
//		return 1;
//	else 
//		return 0;
//}
//
////Câu 7.4
//int IsFull (int a[], int &front, int &rear)
//{
//	if (front == 0 && rear == MAX-1)
//		return 1;
//	else 
//		return 0;
//}
//
////Câu 7.5:
//int Push (int a[], int &front, int &rear, int x)
//{
//	if (rear - front == MAX-1)
//		return 0;
//	else
//	{
//		if (front == -1)
//			front == 0;
//		if (rear == MAX-1)
//		{
//			for (int i=front; i<= rear; i++)
//				a[i - front] = a[i];
//			rear = MAX -1 - front;
//			front = 0;
//		}
//		a[++rear] = x;
//		return 1;
//	}
//	return 0;
//}
//
////Câu 7.6:
//int Pop (int a[], int &front, int &rear, int &x)
//{
//	if (front == -1)
//		return 0;
//	else
//	{
//		x = a[front++];
//		if (front > rear)
//		{
//			front = -1;
//			rear = -1;
//		}
//		return 1;
//	}
//	return 0;
//}
//
////Xuất QUEUE
//void Process_Queue (int a[], int f, int r)
//{
//	cout<<"f="<<f<<"\t r="<<r<<endl;
//	if(f<=r && f!= -1)
//	{
//		cout<<"<---   ";
//		for (int i = f; i<r+1; i++)
//			cout<<a[i]<<"    ";
//		cout<<"<---"<<endl;
//	}
//}
//
//int main()
//{
//	int a[MAX];
//	int choice, f, r, x, i;
//	system ("cls");
//	cout<<"---------BAI TAP 7, CHUONG 1, QUEUE (HANG DOI)---------"<<endl;
//	cout<<"1.Khoi tao QUEUE rong"<<endl;
//	cout<<"2. Kiem tra QUEUE co rong hay khong"<<endl;
//	cout<<"3. Kiem tra QUEUE co dac hay khong"<<endl;
//	cout<<"4. Them phan tu vao QUEUE"<<endl;
//	cout<<"5. Lay phan tu ra khoi QUEUE"<<endl;
//	cout<<"6. Xuat QUEUE"<<endl;
//	cout<<"7. Thoat"<<endl;
//	do
//	{
//		cout<<"Vui long chon so de thu hien: ";
//		cin>>choice;
//		switch (choice)
//		{
//		case 1:
//			Init (a, f, r);
//			cout<<"Ban vua khoi tao QUEUE rong thanh cong!"<<endl;
//			break;
//		case 2:
//			i = IsEmpty (a, f, r);
//			if(i == 0)
//				cout<<"QUEUE khong rong!"<<endl;
//			else
//				cout<<"QUEUE rong!"<<endl;
//			break;
//		case 3:
//			i = IsFull (a,f,r);
//			if (i == 0)
//					cout<<"QUEUE chua day!"<<endl;
//			else
//					cout<<"QUEUE da day!"<<endl;
//			break;
//		case 4:
//			cout<<"Vui long nhap gia tri x=";
//			cin>>x;
//			i = Push (a, f, r, x);
//			cout<<"QUEUE sau khi them la:"<<endl;
//			Process_Queue (a, f, r);
//			break;
//		case 5:
//			i=Pop (a,f,r ,x);
//			cout<<"Phan tu lay ra tu QUEUE la x="<<x<<endl;
//			cout<<"QUEUE sau khi lay ra la:"<<endl;
//			Process_Queue (a, f, r);
//			break;
//		case 6:
//			cout<<"QUEUE hien tai la: "<<endl;
//			Process_Queue (a, f, r);
//			break;
//		case 7:
//			cout<<"GOODBYE"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while (choice != 7);
//	system("pause");
//	return 0;
//}