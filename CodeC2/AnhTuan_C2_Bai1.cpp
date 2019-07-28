//#include <iostream>
//#include <cstdlib>
//#define MAX 100
//using namespace std;
//
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
//	cout << "Cac phan tu trong danh sach:";
//	for (int i = 0; i < n; i++)
//	{
//		if (i % 10 == 0)
//		{
//			cout << endl << " " << a[i];
//		}
//		else
//		{
//			cout << " " << a[i];
//		}
//	}
//	cout << endl;
//}
//
//void search(int a[], int n) {
//	int x, i = 0;
//	cout << "Nhap vao gia tri can tim: ";
//	cin >> x;
//	cout << endl;
//	while (i < n && a[i] != x)
//	{
//		i++;
//	}
//	if (i == n) {
//		cout << "Khong tim thay " << x << " Trong danh sach!" << endl;
//		cout << endl;
//	}
//	else
//	{
//		cout << "Tim thay " << x << " o vi tri a[" << i << "]" << endl;
//		cout << endl;
//	}
//}
//
//void insertLast(int a[], int &n) {
//	int k;
//	cout << "Nhap gia tri can them vao cuoi array: ";
//	cin >> k;
//	a[n] = k;
//	n++;
//	outPut(a, n);
//}
//
//void insert(int a[], int &n) {
//	int h, y;
//	cout << "Nhap vi tri a[i] can chen them phan tu: ";
//	cin >> h;
//	cout << endl;
//	while (h > n)
//	{
//		cout << "Vi tri can chen khong hop le!\n Vui long nhap lai: ";
//		cin >> h;
//		cout << endl;
//	}
//	cout << "Nhap gia tri can chen: ";
//	cin >> y;
//	n++;
//	for (int i = n - 1; i >= h; i--)
//	{
//		a[i] = a[i - 1];
//	}
//	a[h] = y;
//	outPut(a, n);
//}
//
//void deleteLast(int a[], int &n) {
//	a[n - 1] = NULL;
//	n--;
//	cout << "Sau khi xoa phan tu cuoi ";
//	outPut(a, n);
//}
//
//void delvitri(int a[], int &n) {
//	int u;
//	cout << "Nhap vi tri a[i] can xoa: ";
//	cin >> u;
//	while (u > n)
//	{
//		cout << "Vi tri khong ton tai!\n Vui long nhap lai vi tri a[i] can xoa: ";
//		cin >> u;
//	}
//	for (int i = u; i < n-1; i++)
//	{
//		a[i] = a[i + 1];
//	}
//	n--;
//	cout << "Sau khi xoa phan tu a[i] ";
//	outPut(a, n);
//}
//
//void findNdel(int a[], int &n) {
//	int x, i = 0;
//	cout << "Nhap vao gia tri can tim: ";
//	cin >> x;
//	cout << endl;
//	while (i < n && a[i] != x)
//	{
//		i++;
//	}
//	if (i == n) {
//		cout << "Khong tim thay " << x << " Trong danh sach!" << endl;
//		cout << endl;
//	}
//	else
//	{
//		cout << "Tim thay " << x << " o vi tri a[" << i << "]" << endl;
//		for (int j = i; j < n; j++)
//		{
//			a[j] = a[j + 1];
//		}
//		n--;
//		cout << "Da xoa phan tu " << x << " ";
//		outPut(a, n);
//	}
//}
//
//int main() {
//	int a[MAX];
//	int n, x, k;
//	cout << "Nhap so phan tu cua mang: ";
//	cin >> n;
//	inPut(a, n);
//	search(a, n);
//	insertLast(a, n);
//	insert(a, n);
//	deleteLast(a, n);
//	delvitri(a, n);
//	findNdel(a, n);
//	system("pause");
//	return 0;
//}