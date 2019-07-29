﻿#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

#define MAX 3000

//1.1
int a[MAX];
int n=0;

//1.2: Nhập danh sách ngẫu nhiên
void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for(int i=0; i<n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "DS da duoc nhap ngau nhien nhu sau: " << endl;
	for (int i=0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

//1.2: Nhập danh sách thủ công
void input(int a[], int &n)
{
	cout << "Nhap vao so luong pt cua ds: ";
	cin >> n;
	cout << "Nhap vao cac pt cua ds: " << endl;
	for(int i=0; i<n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//1.3: Xuất danh sách
void output(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

void copyArray(int a[], int b[], int n)
{
	for(int i=0; i<n; i++)
		b[i] = a[i];
}

//1.4: Indertion Sort
void Insertion_Sort(int a[], int n)
{
	int i, j, key;
	for(i=1; i<n, i++)
	{
		key = a[i];
		j = i-1;

		/*Di chuyển các pt có giá trị lớn hơn giá trị key 
		về sau 1 vị trí so với vị trí ban đầu của nó */
		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = key;
	}
}

//Hàm đổi chỗ 2 số nguyên
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

//1.5: Selection Sort
void Selection_Sort(int a[], int n)
{
	int i, j, min;
	//Di chuyển ranh giới của mảng đã sắp xếp & chưa sx
	for(i=0; i< n-1; i++)
	{
		//Tìm pt nhỏ nhất trong mảng chưa sx
		min = i;
		for(j= i+1; j<n; j++)
			if(a[j] < a[min])
				min = j;

		//Đổi chỗ pt nhỏ nhất vs pt đầu tiên
		swap(a[min], a[i]);
	}
}

//1.6
void Interchange_Sort(int a[], int n)
{
	for(int i=0; i< n-1; i++)
		for(int j= 1+1; j<n; j++)
			if(a[i] > a[j])
				//Đổi chỗ a[i] vs a[j]
				swap(a[i], a[j]);
}

//1.7
void Bubble_Sort(int a[], int n)
{
	bool haveSwap = false;
	for(int i=0; i<n; i++)
	{
		//i pt cuối cùng đã được sx
		haveSwap = false;
		for(int j=0; j< n-i-1; j++)
			if(a[j] > a[j+1])
			{
				swap( a[j], a[j+1] );
				//Ktra lần lặp này có swap không
				haveSwap = true;
			}
		//Nếu không có swap nào được thực hiện => mảng đã đc sx
		if(haveSwap == false)
			break;
	}
}

//1.8
void Quick_Sort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j)
		Quick_Sort(a, left, j);
	if(i < right)
		Quick_Sort(a, i, right);
}

//1.9
void shift(int a[], int i, int n)
{
	int j = 2*j+1;
	if(j >= n) //Nếu vtri j không tồn tại
		return;
	if(j+1 < n) //Nếu vtri j+1 tồn tại
		if(a[i] < a[j+1])
			j++;

	if(a[i] >= a[j]) //Xét a[i] là pt lớn nhất trong 3 pt
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n) //Xét tính lan truyền tại pt vừa...
	}
}

void Heap_Sort(int a[], int n)
{
	int i = n/2 - 1;
	while(i >= 0) //Tạo heap ban đầu
	{
		shift(a, i, n);
		i--;
	}
	int right = n-1; //right là vtri cuối heap đang xét
	while(right > 0)
	{
		swap(a[0] , a[right]); //Đổi vtri pt a[0] cho pt cuối
		right--; //Giới hạn pt cuối đang xét
		if(right > 0) //Ktra dãy đang xét còn nhiều hơn 1 pt
			shift(a, 0, right); //Tạo heap lại tại vtri 0
	}
}

//1.10
int Search_Sequence(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i] != x)
		i++;
	if(i == n)
		return -1; //cout << "Không tìm thấy";
	else
		return i; //cout << "Tìm thấy tại vtri " << i;
}

//1.11
int Search_Binary(int a[], int l, int r, int x)
{
	if(r >= l)
	{
		int mid = l+(r-1) /2;
		if(a[mid] == x) //Tìm kiếm nửa trái mảng
			return mid;
		if(a[mid] > x) //Tìm kiếm nửa phải mảng
			return Search_Binary(a, l, mid-1, x);
		return Search_Binary(a, mid+1, r, x);
	}
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x=10, i;
	system("cls");
	cout << "--------BAI TAP 1, CHUONG 3, XEP THU TU va TIM KIEM---------" << endl;
	cout << "0. Khoi tao danh sach ngau nhien " << endl;
	cout << "1. Nhap danh sach " << endl;
	cout << "2. Xuat danh sach " << endl;
	cout << "3. Xep thu tu ds bang SECLECTION SORT" << endl;
	cout << "4. Xep thu tu ds bang INSERTION SORT" << endl;
	cout << "5. Xep thu tu ds bang BUBBLE SORT" << endl;
	cout << "6. Xep thu tu ds bang INTERCHANGE SORT" << endl;
	cout << "7. Xep thu tu ds bang QUICK SORT" << endl;
	cout << "8. Xep thu tu ds bang HEAP SORT" << endl;
	cout << "9. Tim kiem pt x bang TIM KIEM TUAN HOAN" << endl;
	cout << "10. Tim kiem pt x bang TIM KIEM NHI PHAN" << endl;
	cout << "11. Thoat" << endl;
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			cout << "Danh sach la: " << endl;
			output(a, n);
			break;
		case 3:
			copyArray(a, b, n);
			start = clock();
			Selection_Sort(b, n);
			duration = (clock() - start) / (double) CLOCK_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi sax voi SECLECTION SORT la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian SELECTION SORT: " << duration * 1000000 << " giay" << endl;
			break;
		case 4:
			copyArray(a, b, n);
			start = clock();
			Insertion_Sort(b, n);
			duration = (clock() - start) / (double) CLOCK_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi sax voi INSERTION SORT la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian INSERTION SORT: " << duration * 1000000 << " giay" << endl;
			break;
		case 5:
			copyArray(a, b, n);
			start = clock();
			Bubble_Sort(b, n);
			duration = (clock() - start) / (double) CLOCK_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi sax voi BUBBLE SORT la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 << " giay" << endl;
			break;
		case 6:
			copyArray(a, b, n);
			start = clock();
			Interchange_Sort(b, n);
			duration = (clock() - start) / (double) CLOCK_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi sax voi INTERCHANGE SORT la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian INTERCHANGE SORT: " << duration * 1000000 << " giay" << endl;
			break;
		case 7:
			copyArray(a, b, n);
			start = clock();
			Quick_Sort(b, 0, n-1);
			duration = (clock() - start) / (double) CLOCK_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi sax voi Quick SORT la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian Quick SORT: " << duration * 1000000 << " giay" << endl;
			break;
		case 8:
			copyArray(a, b, n);
			start = clock();
			Heap_Sort(b, n);
			duration = (clock() - start) / (double) CLOCK_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi sax voi HEAP SORT la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian HEAP SORT: " << duration * 1000000 << " giay" << endl;
			break;
		case 9:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = Search_Sequence(a, n ,x);
			if(i == -1)
				cout << "Khong tim thay x = " << x << " trong mang" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			duration = (clock() - start) / (double) CLOCK_PER_SEC;
			if(duration > 0)
				cout << "Thoi gian TIM KIEM TUAN TU: " << duration * 1000000 << " giay" << endl;
			break;
		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = Search_Binary(b, 0, n, x);
			if(i == -1)
				cout << "Khong tim thay x = " << x << " trong mang" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			duration = (clock() - start) / (double) CLOCK_PER_SEC;
			if(duration > 0)
				cout << "Thoi gian TIM KIEM NHI PHAN: " << duration * 1000000 << " giay" << endl;
			break;
		case 11:
			cout << "\nGood bye";
			break;
		default:
			break;
		}
	}while(choice != 11);
	system("pause");
	return 0;
}