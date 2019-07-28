﻿// Bai 1, Chuong 3, Xep thu tu va tim kiem
#include<iostream>
#include<stdio.h>
#include<ctime>

using namespace std;
#define MAX 5000
// Cau 1
int a[MAX];
int n;

// Cau 1.0: Khoi tao ngau nhien
void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach da duoc nhap ngau nhien nhu sau:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
}

// Cau 1.2: Nhap danh sach
void input (int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] =";
		cin >> a[i];
	}
}

// Cau 1.3: Xuat danh sach
void output (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
}

void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

// Cau 1.4: Insertion Sort
void insertionSort (int a[], int n)
{
	int i, key, j;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		/* Di chuyển các phần tử có giá trị lớn hơn giá trị key về sau 1 vị trí so với vị trí ban đầu của nó */
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

// Ham doi cho 2 so nguyen
void swap (int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

// Cau 1.5: Selection Sort
void selectionSort (int a[], int n)
{
	int i, j, min_idx;
	//Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; i < n - 1; i++)
	{
		// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		swap (a[min_idx], a[i]);
	}
}

// Cau 1.6: Interchange Sort
void interchangeSort (int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap (a[i], a[j]);
}

// Cau 1.7: Bubble Sort
void bubbleSort (int a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if ( a[j - 1] > a[j])
				swap (a[j], a[j - 1]);
}

// Cau 1.8: Quick Sort
void quickSort (int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if(i <= j)
		{
			swap (a[i], a[j]);
			i++; j--;
		}
	}
	if(left < j)
		quickSort (a, left, j);
	if(i < right)
		quickSort (a, i, right);
}

// Cau 1.9: Heap Sort
void shift (int a[], int i, int n)
{
	int j = 2*i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}

void heapSort (int a[], int n)
{
	int i = n / 2 - 1;
	while ( i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		swap (a[0], a[right]);
		right--;
		if (right > 0)
			shift (a, 0, right);
	}
}

// Cau 1.10
void searchSequence (int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i == n)
	{
		cout << "Khong tim thay!";
	}
	else
	{
		cout << "Tim thay tai vi tri " << i;
	}
}

// Cau 1.11
int searchBinary (int a[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = (l + r) / 2;

		// Nếu a[mid] = x, trả về chỉ số và kết thúc.
		if ( a[mid] == x)
			return mid;
		if ( a[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}

	// Nếu không tìm thấy
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system ("cls");
	cout << " -------- BAI TAP 1, CHUONG 3, XEP THU TU va TIM KIEM --------" << endl;
	cout << "0. Khoi tao danh sach ngau nhien " << endl;
	cout << "1. Nhap danh sach " << endl;
	cout << "2. Xuat danh sach " << endl;
	cout << "3. Xep thu tu danh sach bang SELECTION SORT " << endl;
	cout << "4. Xep thu tu danh sach bang INSERTION SORT " << endl;
	cout << "5. Xep thu tu danh sach bang BUBBLE SORT " << endl;
	cout << "6. Xep thu tu danh sach bang INTERCHANGE SORT " << endl;
	cout << "7. Xep thu tu danh sach bang QUICK SORT " << endl;
	cout << "8. Xep thu tu danh sach bang HEAP SORT " << endl;
	cout << "9. Tim kiem phan tu x bang TIM KIEM TUAN TU " << endl;
	cout << "10. Tim kiem phan tu x bang TIM KIEM NHI PHAN " << endl;
	cout << "11. Thoat " << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			init (a, n);
			break;
		case 1:
			input (a, n);
			break;
		case 2:
			cout << " Danh sach la: " << endl;
			output(a, n);
			break;
		case 3:
			CopyArray (a, b, n);
			start = clock();
			selectionSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << " DS sau khi xep thu tu voi SELECTION SORT:";
				output(b, n);
			}
			if (duration > 0)
					cout << "Thoi gian SELECTION SORT : " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 4:
			CopyArray (a, b, n);
			start = clock();
			insertionSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << " DS sau khi xep thu tu voi INSERTION SORT:";
				output(b, n);
			}
			if (duration > 0)
					cout << "Thoi gian INSERTION SORT : " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 5:
			CopyArray (a, b, n);
			start = clock();
			bubbleSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << " DS sau khi xep thu tu voi BUBBLE SORT:";
				output(b, n);
			}
			if (duration > 0)
					cout << "Thoi gian BUBBLE SORT : " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 6:
			CopyArray (a, b, n);
			start = clock();
			interchangeSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << " DS sau khi xep thu tu voi INTERCHANGE SORT:";
				output(b, n);
			}
			if (duration > 0)
					cout << "Thoi gian INTERCHANGE SORT : " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 7:
			CopyArray (a, b, n);
			start = clock();
			quickSort (b, 0, n - 1);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << " DS sau khi xep thu tu voi QUICK SORT:";
				output(b, n);
			}
			if (duration > 0)
					cout << "Thoi gian QUICK SORT : " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 8:
			CopyArray (a, b, n);
			start = clock();
			shift (a, n / 2 - 1, n);
			heapSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << " DS sau khi xep thu tu voi HEAP SORT:";
				output(b, n);
			}
			if (duration > 0)
					cout << "Thoi gian HEAP SORT : " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 9:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			searchSequence (a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			
			if (duration > 0)
					cout << " Thoi gian TIM KIEM TUAN TU : " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = searchBinary (a, 0, n - 1, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(i == -1)
				cout << "Khong tim thay x = " << x << " trong mang" << endl;
			if (duration > 0)
					cout << "Thoi gian TIM KIEM NHI PHAN : " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 11:
			cout << "goodbye" << endl;
		default:
			break;
		}
	}while(choice != 11);
	system ("pause");
	return 0;
}