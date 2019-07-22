#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int sp;

void init(int a[],int &sp)
{
	sp=-1;
}

void process_list(int a[],int sp)
{
	int i=sp;
	while(i>=0)
	{
		cout << "\t" << a[i];
		i--;
	}
}

void nhiphan(int a[],int &sp, int x)
{
	while(x>0)
	{
		a[++sp]=x%2;
		x=x/2;
	}
	if(sp==MAX-1)
		cout << "tran bo nho." << endl;
}

int main()
{
	init(a,sp);
	int x;
	cout << "nhap vao 1 so thap phan: ";
	cin >> x;
	nhiphan(a,sp,x);
	process_list(a,sp);
	cout << endl;
	system("pause");
	return 0;
}
