#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

#define MAX 5000
//Câu 1.1:
int  a[MAX];
int n;

//Câu 1.2: Khởi tạo DS ngẫu nhiên
void init (int a[], int &n)
{
	cout<<"Nhap vao so long phan tu cua danh sach: ";
	cin>>n;
	for (int i = 0; i<n; i++)
		a[i]=rand() % 10000 +1 ;

cout<<"Danh sach da duoc nhap ngau nhien nhu sau: ";
for (int i = 0; i<n; i++)
	cout<<a[i]<<"   ";
cout<< endl;
}
//Câu 1.2: Khỏi tạo DS 
void input(int a[], int &n)
{
	cout<<"Nhap vao so luong phan tu cua danh sach: ";
	cin>>n;
	cout<<"Nhap vao cac phan tu cua danh sach: ";
	for (int i = 0; i<n; i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}


//Câu 1.3: 
void output (int a[], int n)
{
	for (int i = 0; i<n; i++)
		cout<< a[i]<< "   ";
	cout<< endl;
}

void CoppyArray (int a[], int b[], int n)
{
	for (int i = 0; i<n; i++)
		b[i]=a[i];
}

//Câu 1.4: Insertion Sort
void InsertionSort (int a[], int n)
{
	int i, j, key;
	for (int i = 1; i<n; i++)
	{
		key=a[i];
		j=i-1;
		/* Di chuyen cac phan tu có gia trị lớn hơn giá trị key về sau một vị trí với giá trị ban đầu của nó */
		while (j>=0 && a[j]>key)
		{
			a[j+1]= a[j];
			j=j-1;
		}
		a[j+1]= key;
	}
}


void swap (int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}

//Câu 1.5: Selection Sort
void SelectionSort (int a[], int n)
{
	int  i, j, min_idx;
	for ( i = 0; i<n -1; i++)
	{
		min_idx = i;
		for (j=i+1; j<n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		swap (a[min_idx], a[i] );
	}
}

//Câu 1.6: Interchange Sort
void InterchangeSort (int a[], int n)
{
	for (int i = 0; i<n -1 ; i++)
		for (int j = i +1; j<n; j++)
			if (a[i]> a[j])
				swap(a[i], a[j]); 
}

//Câu 1.7: Buble Sort
void BubbleSort (int arr[], int n)
{
	int i, j;
	bool haveSwap= false;
	for (i=0 ; i<n-1; i++)
	{
		haveSwap = false;
		for (j=0; j<n- i -1; j++)
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
				haveSwap = true;
			}
	if (haveSwap == false)
		break;
	}
}

//Câu 1.8: Quick Sort
void QuickSort (int a[], int left, int right)
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
		QuickSort (a, left, j);
	if(i < right)
		QuickSort (a, i, right);
}

//Câu 1.9: Heap Sort
void shift (int a[], int i, int n)
{
	int j = 2* i + 1;
	if (j>=n)
		return;
	if (j+1 <n)
		if (a[j] <a[j+1])
			j++; 
	if (a[i] >= a[j])
		return; 
	else 
	{
		int x = a[i];
		a[i] = a[j];
		a[j]=x;
		shift (a, j, n);
	}
}

void HeapSort (int a[], int n)
{
	int i=n/2 -1;
	while (i>=0)
	{
		shift (a,i,n);
		i--;
	}
	int right= n-1;
	while (right>0)
	{
		swap (a[0], a[right]); 
		right--;
		if(right>0)
			shift (a,0,right); 
	}
}
//Câu 1.10:
void searchSequence (int a[], int n, int x)
{
	int i=0;
	while (i<n && a[i]!=x)
		i++;
	if (i==n)
		cout <<"Khong tim thay!"<<endl;
	else
		cout<<"Tim thay tai vi tri: " <<i<<endl;
}

//Câu 1.11:
int searchBinary (int a[], int n, int x)
{
	int left=0, right= n-1, mid;
	while (left <=right)
	{
		mid =(left +right)/2;
		if (a[mid]==x)
			return mid;
		if (x>a[mid])
			left=mid +1;
		else 
			right= mid-1;
	}
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start; 
	double duration;
	int choice, x, i;
	system ("cls");
	cout<<"--------BAI TAP 1, CHUONG 3, XEP THU TU VA TIM KIEM"<<endl;
	cout<<"0. Khoi tao danh sach ngau nhien"<<endl;
	cout<<"1. Nhap danh sach"<<endl;
	cout<<"2. Xuat danh sach"<<endl;
	cout<<"3. Xep thu tu danh sach bang SELECTION SORT"<<endl;
	cout<<"4. Xep thu tu danh sach bang INSERTION SORT"<<endl;
	cout<<"5. Xep thu tu danh sach bang BUBBLE SORT"<<endl;
	cout<<"6. Xep thu tu danh sach bang INTERCHANGE SORT"<<endl;
	cout<<"7. Xep thu tu danh sach bang QUICK SORT"<<endl;
	cout<<"8. Xep thu tu danh sach bang HEAP SORT"<<endl;
	cout<<"9. Tim kiem phan tu x bang TIM KIEM TUAN TU"<<endl;
	cout<<"10. Tim kiem phan tu x bang TIM KIEM NHI PHAN"<<endl;
	cout<<"11. Thoat"<<endl;
	do
	{
		cout<<"Vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 0:
				init (a,n);
				break;
			case 1:
				input(a,n);
				break;
			case 2:
				cout<<"Danh sach la"<<endl;
				output(a,n);
				break;
			case 3:
				CoppyArray (a, b, n);
				start = clock ();
				SelectionSort(b, n);
				duration = (clock() -start)/ (double)CLOCKS_PER_SEC;
				if (n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi SELECTION SORT la: "<<endl;
					output (b,n);
				}
				if( duration >0)
					cout<<"Thoi gian thuc hien SELECTION SORT: "<<duration *1000000<<" Microseconds"<<endl;
				break;
			case 4:
				CoppyArray (a, b, n);
				start = clock ();
				InsertionSort(b, n);
				duration = (clock () -start)/ (double)CLOCKS_PER_SEC;
				if (n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi INSERTION SORT la: "<<endl;
					output (b,n);
				}
				if( duration >0)
					cout<<"Thoi gian thuc hien INSERTION SORT: "<<duration *1000000<<" Microseconds"<<endl;
				break;
			case 5:
				CoppyArray (a, b, n);
				start = clock ();
				BubbleSort(b, n);
				duration = (clock () -start)/ (double)CLOCKS_PER_SEC;
				if (n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi BUBBLE SORT la: "<<endl;
					output (b,n);
				}
				if( duration >0)
					cout<<"Thoi gian thuc hien BUBBLE SORT: "<<duration *1000000<<" Microseconds"<<endl;
				break;
			case 6:
				CoppyArray (a, b, n);
				start = clock ();
				InterchangeSort(b, n);
				duration = (clock () -start)/ (double)CLOCKS_PER_SEC;
				if (n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi INTERCHANGE SORT la: "<<endl;
					output (b,n);
				}
				if( duration >0)
					cout<<"Thoi gian thuc hien INTERCHANGE SORT: "<<duration *1000000<<" Microseconds"<<endl;
				break;
			case 7:
				CoppyArray (a, b, n);
				start = clock ();
				QuickSort(b, 0, n-1);
				duration = (clock () -start)/ (double)CLOCKS_PER_SEC;
				if (n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi QUICK SORT la: "<<endl;
					output (b,n);
				}
				if( duration >0)
					cout<<"Thoi gian thuc hien QUICK SORT: "<<duration *1000000<<" Microseconds"<<endl;
				break;
			case 8:
				CoppyArray (a, b, n);
				start = clock ();
				shift(a, n/2-1,n);
				HeapSort(b, n);
				duration = (clock () -start)/ (double)CLOCKS_PER_SEC;
				if (n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi  HEAP  SORT la: "<<endl;
					output (b,n);
				}
				if( duration >0)
					cout<<"Thoi gian thuc hien  HEAP  SORT: "<<duration *1000000<<" Microseconds"<<endl;
				break;
			case 9:
				cout<<"Nhap phan tu x can tim: ";
				cin>>x;
				
				searchSequence (a,n,x);
			
				break;
			case 10:
				
				cout<<"Nhap gia tri x can tim: ";
				cin>>x;
				i= searchBinary(a, n, x);
				if (i!=-1)
					cout<<"Tim khong thay phan tu "<<x<<endl;
				else 
					cout<<"Tim thay phan tu "<<x<<endl;
				break;
			default:
				break;
		}
	}while (choice != 11);

	system ("pause ");
	return 0;
}
	