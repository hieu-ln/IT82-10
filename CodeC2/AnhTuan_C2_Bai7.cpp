//#include <stdio.h>
//#include<iostream>
//using namespace std;
//#define MAX 100
//
//void init(int a[], int &front, int &rear)
//{
//	front=-1;
//	rear=-1;
//}
//
//int isEmpty(int a[], int &front, int &rear)
//{
//	if (front==rear)
//		return 1;
//	else
//		return 0;
//}
//
//int isFull(int a[], int &front, int &rear)
//{
//	if ((front==0 && rear==MAX-1) || (front-rear == 1))
//		return 1;
//	else
//		return 0;
//}
//
//int Push(int a[], int &front, int &rear, int x)
//{
//	if(rear-front==MAX-1)
//		return 0;
//	else
//	{
//		if(front==-1)
//			front=0;
//		if(rear=MAX-1)
//		{
//			for (int i=front; i<=rear; i++)
//			{
//				a[i-front]=a[i];
//			}
//			rear=MAX-1-front;
//			front=0;
//		}
//		a[++rear]=x;
//		return 1;
//	}
//	return 0;
//}
//
//int Pop(int a[], int &front, int &rear, int &x)
//{
//	if (front==-1)
//		return 0;
//	else
//	{
//		x = a[++front];
//		if(front>rear)
//		{
//			front= -1;
//			rear= -1;
//		}
//		return 1;
//	}
//	return 0;
//}
//
//void Process_queue(int a[], int f, int r)
//{
//	cout<<"f= "<<f<<"\t r= "<<r<<endl;
//	if(f<=r && f!=-1)
//	{
//		cout<<"<-- ";
//		for (int i =f; i< r+1 ; i++)
//		{
//			cout<<a[i]<<" ";
//		}
//		cout<<"<-- "<<endl;
//	}
//}
//
//int main()
//{
//	int a[MAX];
//	int choice, f, r, x, i;
//	system("cls");
//	cout << "1. Khoi tao QUEUE rong\n"
//		 << "2. Them phan tu vao QUEUE\n"
//		 << "3. Lay phan tu ra khoi QUEUE\n"
//		 << "4. Kiem tra QUEUE co rong hay khong\n"
//		 << "5. Kiem tra QUEUE co day hay khong\n" 
//		 << "6. Xuat QUEUE\n"
//		 << "7. Thoat\n" << endl;
//	do
//	{
//		cout << "\nChon so thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init(a, f, r);
//			cout << "Da khoi tao QUEUE rong thanh cong!\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri x= ";
//			cin >> x;
//			i = Push(a, f, r, x);
//			cout << "QUEUE sau khi them la: ";
//			Process_queue(a, f, r);
//			break;
//		case 3:
//			i = Pop(a, f, r, x);
//			cout << "Phan tu lay ra tu QUEUE la x= " << x << endl;
//			cout << "QUEUE sau khi lay ra la: ";
//			Process_queue(a, f, r);
//			break;
//		case 4:
//			i = isFull(a, f, r);
//			if (i == 0)
//				cout << "QUEUE chua day!" << x << endl;
//			else
//				cout << "QUEUE da day!" << x << endl;
//			break;
//		case 5:
//			i = isEmpty(a, f, r);
//			if (i == 0)
//				cout << "QUEUE khong rong!" << x << endl;
//			else
//				cout << "QUEUE rong!" << x << endl;
//			break;
//		case 6:
//			cout << " QUEUE hien tai la: ";
//			Process_queue(a, f, r);
//			break;
//		case 7:
//			cout << "Goodbye!" << endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 7);
//	system("pause");
//	return 0;
//}