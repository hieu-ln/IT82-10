#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];

/// DSLK su dung cho Stack va Queue
struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

///Stack
void InitStack()
{
	sp = NULL;
}

int isEmptyS()
{
	if(sp == NULL)
	{
		return 1;
	}
	return 0;
}

void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
{
	if(sp != NULL)
	{
		Node *p = new Node;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
/// end Stack

/// Queue
void InitQueue()
{
	front = NULL;
	rear = NULL;
}

int isEmptyQ()
{
	if(front == NULL)
	{
		return 1;
	}
	return 0;
}

void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
	{
		front = p;
	}
	else
	{
		rear->link = p;
	}
	rear = p;
}

int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
/// end Queue

// cau 5.1: Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "nhap ten dinh: ";
		cin >> vertex[i];
		cout << "nhap vao dong thu " << i + 1 << ": ";
		for(int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
}

// cau 5.2: Xuat ra ma tran ke cua do thi
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << A[i][j] << "	";
		}
		cout << endl;
	}
}

// cau 4.3: Duyet do thi theo chieu rong BFS (dung Queue va DSLK don)
int C[100], bfs[100];
int nbfs = 0;

void InitC()
{
	for(int i = 0; i < n; i++) // n la so dinh cua do thi
	{
		C[i] = 1;
	}
}

void BFS(int v) // v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
		{
			if(C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
		}
	}
}

// cau 4.4: duyet do thi theo chieu sau DFS (dung Stack va DSLK don)
int dfs[100];
int ndfs = 0;

void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1;
	int u = s;
	while(isEmptyS() == 0)
	{
		if(v == n)
		{
			PopS(u);
		}
		for(v = 0; v < n; v++)
		{
			if(A[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}

// cau 4.5: dung BFS tim x tren do thi
void Search_by_BFS(int x, int v) // v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "tim thay x = " << x << endl;
			return;
		}
		for(w = 0; w < n; w++)
		{
			if(C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
		}
	}
}

void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << vertex[a[i]] << "	";
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, x, sp, sp_b, i;
	system("cls");
	cout << "---------------------------MENU--------------------------" << endl;
	cout << "1. Nhap ma tran ke." << endl;
	cout << "2. Xuat ma tran ke." << endl;
	cout << "3. Duyet do thi theo chieu rong BFS(Queue-DSLK)" << endl;
	cout << "4. Duyet do thi theo chieu sau DFS(Stack-DSLK)" << endl;
	cout << "5. Kiem tra dinh do thi co ton tai khong? (duyet BFS)" << endl;
	cout << "6. Thoat" << endl;
	do 
	{
		cout << "\nNhap lua chon: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				inputGraph();
				break;
			case 2:
				outputGraph();
				break;
			case 3:
				InitQueue();
				InitC();
				cout << "vui long nhap dinh xuat phat: ";
				cin >> x;
				nbfs = 0;
				BFS(x);
				cout << "thu tu dinh sau khi duyet BFS: " << endl;
				output(bfs,n);
				break;
			case 4:
				InitStack();
				InitC();
				cout << "vui long nhap dinh xuat phat: ";
				cin >> x;
				ndfs = 0;
				DFS(x);
				cout << "thu tu dinh sau khi duyet DFS: " << endl;
				output(dfs,n);
				break;
			case 5:
				cout << "vui long nhap gia tri x can tim: ";
				cin >> x;
				Search_by_BFS(x,0);
				break;
			case 6:
				cout << "GOOD BYE." << endl;
				break;
			default:
				break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}
