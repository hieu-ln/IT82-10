//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
////Khai bao cau truc danh sach
//#define MAX 100
//int a[MAX];
//int n;
//
////Nhap danh sách
//void input(int a[], int &n)
//{
//	cout << "Nhap so luong pt danh sach: ";
//	cin >> n;
//	for(int i=0; i<n; i++)
//	{
//		cout << "Nhap a["<< i+1 <<"]: ";
//		cin >> a[i];
//	}
//}
//
////Xuat danh sach
//void output(int a[], int n)
//{
//	for(int i=0; i<n; i++)
//		cout << a[i] << "\t";
//} 
//
////Tim phan tu trong danh sach
//int searchX(int a[], int n, int x)
//{
//	int i=0;
//	while((i<n) && (a[i] != x))
//		i++;
//	if (i==n)
//		return -1;
//	return i;
//}
//
////Them pt cuoi danh sach
//int insert_last(int a[], int &n, int x)
//{
//	if(n < MAX)
//	{
//		a[n] = x;
//		n++;
//		return 1;
//	}
//	return 0;
//}
//
////Xoa pt cuoi danh sach
//int delete_last(int a[], int &n)
//{
//	if(n > 0)
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
//
////Xoa pt tai vi tri thu i
//int Delete (int a[], int &n, int i)
//{
//	if (i >= 0 && i < n)
//	{
//		for(int j=i; j < n-1; j++)
//			a[j] = a[j+1];
//		n--;
//		return 1;
//	}
//	return 0;
//}
//
////Tim 1 pt va xoa pt do
//int search_and_delete(int a[], int &n, int x)
//{
//	for (int i=0; i < n; i++)
//	{
//		if (a[i] == x)
//		{
//			Delete(a, n ,i);
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int choice = 0;
//	int x, i;
//	system("cls");
//	cout << "--------------BAI TAP 1, CHUONG 2, DANH SACH DAC--------------";
//	cout << "1. Nhap danh sach" << endl;
//	cout << "2. Xuat danh sach" << endl;
//	cout << "3. Tim 1 pt trong danh sach" << endl;
//	cout << "4. Them 1 pt vao cuoi danh sach" << endl;
//	cout << "5. Xoa 1 pt cuoi danh sach" << endl;
//	cout << "6. Xoa pt tai vi tri thu i" << endl;
//	cout << "7. Tim 1 pt va xoa pt do" << endl;
//	cout << "8. Thoat" << endl;
//	do{
//		cout << "Vui long chon buoc de thuc hien: ";
//		cin >> choice;
//		switch(choice)
//		{
//			case 1:
//				input(a, n);
//				cout << "Nhap danh sach thanh cong";
//				break;
//			case 2:
//				output(a, n);
//				cout << "Xuat danh sach thanh cong";
//				break;
//			case 3:
//				cout << "Nhap phan tu can tim";
//				cin >> x;
//				cout << "Phan tu nam o vi tri "<< searchX(a, n, x);
//				break;
//			case 4:
//				cout << "Nhap phan tu can them vao cuoi ds";
//				cin >> x;
//				insert_last(a, n ,x);
//				output(a, n);
//				break;
//			case 5:
//				delete_last(a, n);
//				output(a, n);
//				break;
//			case 6:
//				cout << "Nhap vi tri can xoa";
//				cin >> i;
//				Delete(a, n, i);
//				output(a, n);
//				break;
//			case 7:
//				cout << "Nhap pt can tim va xoa pt do";
//				cin >> x;
//				search_and_delete(a, n, x);
//				output(a, n);
//				break;
//			default:
//				cout << "\nGoodbye";
//				break;
//		}
//	}while(choice !=8);
//
//	system("pause");
//	return 0;
//}