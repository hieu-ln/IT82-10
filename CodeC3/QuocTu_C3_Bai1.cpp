#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define MAX 100
int a[MAX];
int n;

void input(int a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout << "nhap phan tu thu " << i << " : ";
		cin >> a[i];
	}
}

void output(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout << "\t" << a[i];
}

void InsertionSort(int a[],int n)
{
	int x,i,j;
	for(int i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;;
		while(0<=j&&x<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
// do phuc tap cua thuat toan O(n^2)

void SelectionSort(int a[],int n)
{
	int min_pos,i,j;
	for(int i=0;i<n-1;i++)
	{
		min_pos=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[min_pos])
				min_pos=j;
		swap(a[min_pos],a[i]);
	}
}
// do phuc tap cua thuat toan O(n^2)

void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}

void InterchangeSort(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
// do phuc tap cua thuat toan O(n^2)

void BubbleSort(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(a[j-1]>a[j])
				swap(a[j],a[j-1]);
}
// do phuc tap cua thuat toan O(n^2)

void QuickSort(int a[],int left,int right)
{
	int x=a[(left+right)/2];
	int i=left;
	int j=right;
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left<j)
		QuickSort(a,left,j);
	if(i<right)
		QuickSort(a,i,right);
}
// do phuc tap cua thuat toan O(n log n)

void Shift(int a[],int i,int n)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		swap(a[i],a[j]);
		Shift(a,j,n);
	}
}

void HeapSort(int a[],int n)
{
	int i=n/2;
	while(i>=0)
	{
		Shift(a,i,n-1);
		i--;
	}
	int right=n-1;
	while(right>0)
	{
		swap(a[0],a[right]);
		right--;
		if(right>0)
			Shift(a,0,right);
	}
}
// do phuc tap cua thuat toan O(n log n)

int search(int a[],int n,int x)
{
	int i=0;
	while(i<n&&a[i]!=x)
		i++;
	if(i<n)
		return i;
	return 0;
}

int binarySearch(int a[], int x, int left, int right)
{
    if(left > right)
        return 0;
    else
	{
        int i=(left+right)/2;
        if(a[i]==x)
            return i;
        if(a[i]>x)
            return binarySearch(a,x,left,i-1);
        if(a[i]<x)
            return binarySearch(a,x,i+1,right);
    }
}

int main()
{
	int x;
	int z;
	cout << "-------------------MENU-----------------" << endl;
	cout << "1.  Nhap danh sach." << endl;
	cout << "2.  Xuat danh sach." << endl;
	cout << "3.  InsertionSort danh sach." << endl;
	cout << "4.  SelectionSort danh sach." << endl;
	cout << "5.  InterchangeSort danh sach." << endl;
	cout << "6.  BubbleSort danh sach." << endl;
	cout << "7.  QuickSort danh sach." << endl;
	cout << "8.  HeapSort danh sach." << endl;
	cout << "9.  Tim kiem tuan tu trong danh sach." << endl;
	cout << "10. Tim kiem nhi phan trong danh sach." << endl;
	cout << "11. Thoat." << endl;
	do
	{
		cout << "\nmoi lua chon: ";
		cin >> z;
		switch(z)
		{
			case 1:
				cout << "\nnhap do dai danh sach: ";
				cin >> n;
				input(a,n);
				break;
			case 2:
				output(a,n);
				break;
			case 3:
				InsertionSort(a,n);
				output(a,n);
				break;
			case 4:
				SelectionSort(a,n);
				output(a,n);
				break;
			case 5:
				InterchangeSort(a,n);
				output(a,n);
				break;
			case 6:
				BubbleSort(a,n);
				output(a,n);
				break;
			case 7:
				QuickSort(a,0,n-1);
				output(a,n);
				break;
			case 8:
				HeapSort(a,n);
				output(a,n);
				break;
			case 9:
				cout << "nhap gia tri can tim: ";
				cin >> x;
				if(search(a,n,x)==0)
					cout << "khong tim thay vi tri chua gia tri " << x << endl;
				else
					cout << "tim thay gia tri " << x << " tai vi tri " << search(a,n,x) << endl;
				break;
			case 10:
				cout << "nhap gia tri can tim: ";
				cin >> x;
				if(binarySearch(a,x,0,n-1)==0)
					cout << "khong tim thay vi tri chua gia tri " << x << endl;
				else
					cout << "tim thay gia tri " << x << " tai vi tri " << binarySearch(a,x,0,n-1) << endl;
				break;
			case 11:
				cout << "good bye." << endl;
				break;
			default:
				cout << "xin moi nhap lai. " << endl;
				break;
		}
	}while(z!=11);
	system("pause");
	return 0;
}
