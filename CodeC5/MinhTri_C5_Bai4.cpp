#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX]; //Mảng 2 chiều
int n; //Số đỉnh của đồ thị
char vertex[MAX]; //Tên đỉnh

//DSLK sử dụng cho STACK & QUEUE
struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

////STACK
void Init_Stack()
{
	sp = NULL;
}

int isEmptyS()
{
	if(sp == NULL)
		return 1;
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
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//End STACK

////QUEUE
void Init_Queue()
{
	front = NULL;
	rear = NULL;
}

int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}

void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
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
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
///End QUEUE

void Init_Graph()
{
	n = 0;
}

void Input_Graph_From_Text()
{
	string line;
	ifstream myfile("matranke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i=0; i<n; i++)
			myfile >> vertex[i];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				myfile >> A[i][j];
		}
	}
}

//4.1: Nhập ma trận kề của đồ thị
void Input_Graph()
{
	cout << "Nhap so dinh cua do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i=0; i<n; i++)
		cin >> vertex[i];
	for(int i=0; i<n; i++)
	{
		cout << "Nhap vao dong thu " << i+1 << ": ";
		for(int j=0; j<n; j++)
			cin >> A[i][j];
	}
}

//4.2: Xuất ma trận kề của đồ thị
void Output_Graph()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void Output(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << vertex[ a[i] ] << " ";
}

//4.3: Duyệt đồ thị theo chiều rộng BFS (dùng QUEUE & DSLK đơn)
int C[100], bfs[100];
int nbfs = 0;
void InitC()
{
	for(int i=0; i<n; i++) //n là số đỉnh của đồ thị
		C[i] = 1;
}
void BFS(int v) //v là đỉnh bắt đầu
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w<n; w++)
			if(C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

//4.4: Duyệt đồ thị theo chiều sâu DFS (dùng STACK & DSLK đơn)
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while(isEmptyS() == 0)
	{
		if(v == n)
			PopS(u);
		for(v=0; v<n; v++)
			if(A[u][v]!=0 && C[v]==1)
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

//4.5: Dùng BFS tìm x trên đồ thị
void Search_by_BFS(int x, int v) //v là đỉnh bắt đầu
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "Tim thay x=" << x << endl;
			return;
		}
		for(w=0; w<n; w++)
			if(C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, x, i;
	system("cls");
	cout << "------- BAI TAP 4, CHUONG 5, DO THI ---------" << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE	tu file text" << endl;
	cout << "3. Nhap MA TRAN KE" << endl;
	cout << "4. Xuat MA TRAN KE" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "6. Duyet do thi theo chieu sau DFS - DSLK" << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Init_Graph();
				cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
				break;
			case 2:
				Input_Graph_From_Text();
				cout << "Ban vua nhap MA TRAN KE tu file: \n";
				Output_Graph();
				break;
			case 3:
				Input_Graph();
				break;
			case 4:
				Output_Graph();
				break;
			case 5:
				Init_Queue();
				InitC();
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				nbfs = 0;
				BFS(x);
				cout << "Thu tu dinh sau khi duyet BFS: " << endl;
				Output(bfs, n);
				break;
			case 6:
				Init_Stack();
				InitC();
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				ndfs = 0;
				DFS(x);
				cout << "Thu tu dinh sau khi duyet DFS: " << endl;
				Output(dfs, n);
				break;
			case 7:
				Init_Queue();
				InitC();
				nbfs = 0;
				cout << "Vui long nhap gia tri x can tim: ";
				cin >> x;
				Search_by_BFS(x, 0);
				break;
			case 8:
				cout << "Goodbye ......!" << endl;
				break;
			default:
				break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}