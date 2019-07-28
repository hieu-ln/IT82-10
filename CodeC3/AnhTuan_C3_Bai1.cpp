//#include <iostream>
//#include <cstdlib>
//#include <stdio.h>
//#define MAX 100
//using namespace std;
////Tao ds random
//void taoDS(int a[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 1000 + 1;
//	}
//	cout << "Danh sach khoi tao thanh cong!\n";
//}
////Nhap tay
//void inPut(int a[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap phan tu thu a[" << i << "]: ";
//		cin >> a[i];
//		cout << endl;
//	}
//}
//
//void outPut(int a[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		if ((i+1) % 10 == 0)
//		{
//			cout << " " << a[i] << endl;
//		}
//		else
//		{
//			cout << " " << a[i];
//		}
//	}
//	cout << endl;
//}
//
//void insertionSoft(int a[], int n) {
//	int x,j;
//	for (int i = 1; i < n; i++)
//	{
//		x = a[i];
//		j = i - 1;
//		while (0 <= j && x < a[j])
//		{
//			a[j + 1] = a[j];
//			j--;
//		}
//		a[j + 1] = x;
//	}
//	cout << " Da sap xep xong!\n";
//}
//
//void swap(int &a, int &b) {
//	int c;
//	c = a;
//	a = b;
//	b = c;
//}
//
//void selectionSort(int a[], int n) {
//	int min_Pos;
//	for (int i = 0; i < n; i++)
//	{
//		min_Pos = i;
//		for (int j = i+1; j < n; j++)
//		{
//			if (a[j] < a[min_Pos])
//			{
//				min_Pos = j;
//				swap(a[j], a[min_Pos]);
//			}
//		}
//	}
//	cout << " Da sap xep xong!\n";
//}
//
//void interchangeSort(int a[], int n) {
//	for (int i = 0; i < n-1; i++)
//	{
//		for (int j = i+1; j < n; j++)
//		{
//			if (a[i] > a[j])
//			{
//				swap(a[j], a[i]);
//			}
//		}
//	}
//	cout << " Da sap xep xong!\n";
//}
//
//void bubbleSort(int a[], int n) {
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = n-1; j >i; j--)
//		{
//			if (a[j-1] > a[j])
//			{
//				swap(a[j], a[j-1]);
//			}
//		}
//	}
//	cout << " Da sap xep xong!\n";
//}
//
//void quickSort(int a[], int left, int right) {
//	int x, i, j;
//	x = a[(left + right) / 2];
//	i = left;
//	j = right;
//	while (i < j)
//	{
//		while (a[i] < x)
//		{
//			i++;
//		}
//		while (a[j] > x)
//		{
//			j--;
//		}
//		if (i<=j)
//		{
//			swap(a[i], a[j]);
//			i++;
//			j--;
//		}
//	}
//	if (left < j)
//	{
//		quickSort(a, left, j);
//	}
//	if (i < right)
//	{
//		quickSort(a, i, right);
//	}
//}
//
//void heapSort(int a[],int i,int n) {
//	int j = 2 * i + 1;
//	if (j <=n)
//	{
//		return;
//	}
//	if (j+1<n)
//	{
//		if (a[j] < a[j+1])
//		{
//			j++;	
//		}
//	}
//	if (a[i] >= a[j])
//	{
//		return;
//	}
//	else {
//		int x = a[i];
//		a[i] = a[j];
//		a[j] = x;
//		heapSort(a, j, n);
//	}
//	cout << "Da sap xep xong!\n";
//}
//
//int searchSequence(int a[], int n, int x)
//{
//	int i = 0;
//	while (i < n && a[i] != x)
//		i++;
//	if (i < n) {
//		cout << "Da tim thay phan tu " << x << " tai vi tri: " << i << endl;
//		return i;
//	}
//	cout << "Khong tim thay phan tu " << x << endl;
//	return -1;
//}
//
//int searchBinary(int a[], int n, int x)
//{
//	int left = 0, right = n - 1, mid;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (a[mid] == x) {
//			cout << "Da tim thay phan tu " << x << " tai vi tri: " << mid << endl;
//			return mid;
//		}
//		if (x > a[mid]) left = mid + 1;
//		else right = mid - 1;
//	}
//	cout << "Khong tim thay phan tu " << x << endl;
//	return -1;
//}
//
//int main() {
//	int a[MAX], n, select;
//	cout << "Nhap so phan tu cua danh sach: ";
//	cin >> n;
//	int left = 0, right = n - 1;
//	int i = n / 2;
//	cout << "1.Khoi tao danh sach random.\n"
//		<< "2.Khoi tao danh sach thu cong.\n"
//		<< "3.Xuat danh sach!\n"
//		<< "4.Insertion Sort.\n"
//		<< "5.Selection Sort.\n"
//		<< "6.Interchange Sort.\n"
//		<< "7.Bubble Sort.\n"
//		<< "8.Quick Sort.\n"
//		<< "9.Heap Sort.\n"
//		<< "10.Search Sequense.\n"
//		<< "11.Search Binary.\n"
//		<< "12.Thoat!\n";
//		do{
//		cout<<"Chon buoc can thuc hien: ";
//		cin>>select;
//		switch(select)
//		{
//		case 1:
//			taoDS(a, n);
//			break;
//		case 2:
//			inPut(a, n);
//			break;
//		case 3:
//			cout << "Cac phan tu cua danh sach:\n ";
//			outPut(a, n);
//			break;
//		case 4:
//			insertionSoft(a, n);
//			cout << "Cac phan tu cua danh sach:\n ";
//			outPut(a, n);
//			break;
//		case 5:
//			selectionSort(a, n);
//			cout << "Cac phan tu cua danh sach:\n ";
//			outPut(a, n);
//			break;
//		case 6:
//			interchangeSort(a, n);
//			cout << "Cac phan tu cua danh sach:\n ";
//			outPut(a, n);
//			break;
//		case 7:
//			bubbleSort(a, n);
//			cout << "Cac phan tu cua danh sach:\n ";
//			outPut(a, n);
//			break;
//		case 8:
//			quickSort(a,left,right);
//			cout << "Da sap xep xong!\n";
//			cout << "Cac phan tu cua danh sach:\n ";
//			outPut(a, n);
//			break;
//		case 9:
//			heapSort(a,i,n);
//			cout << "Cac phan tu cua danh sach:\n ";
//			outPut(a, n);
//			break;
//		case 10:
//			int x;
//			cout << "Nhap vao gia tri can tim: ";
//			cin >> x;
//			searchSequence(a, n, x);
//			break;
//		case 11:
//			int y;
//			cout << "Nhap vao gia tri can tim: ";
//			cin >> y;
//			searchBinary(a, n, y);
//			break;
//		default:
//			break;
//		}
//	}while(select < 12);
//	cout << "Da thoat!\n";
//	system("pause");
//	return 0;
//}