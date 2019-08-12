#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

#define MAX 20
int a[MAX];
int A[MAX][MAX];
int n;
int sp;
int front, rear;
char vertex[MAX];

///STACk
void InitStack(int a[], int &sp)
{
	sp = -1;
}

int isEmptyS()
{
	if(sp == -1)
		return 1;
	return 0;
}

int PushS(int x)
{
	if(sp < MAX -1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

int PopS(int a[], int &sp, int &x)
{
	if(sp!= -1)
	{
		x = a[sp--];
	}
	return 0;
}

//QUEUE

void initQueue(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}

int isEmptyQ(int a[], int rear, int front)
{
	if(front == -1)
		return 1;
	return 0;
}

int PushQ(int a[], int &rear, int &front, int x)
{
	if( rear - front == MAX -1)
		return 0;
	else
	{
		if(front == -1)
			front = 0;
		if(rear == MAX -1)
		{
			for(int i = front; i <= rear; i++)
				a[i = front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear]= x;
		return 1;
	}
}

int PopQ(int a[], int &rear,int & front, int &x)
{
	if(front == -1)
		return 0;
	else
	{
		x = a[front++];
		if(front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}
//end QUEUE

void InitGraph()
{
	n = 0;
}

//Cau 6.2: Nhap ma tran ke
void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i = 0; i< n; i++)
			myfile>>vertex[i];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				myfile>>A[i][j];
		}
	}
}


void inputGraph()
{
	cout <<"Nhap so dinh do thi n: ";
	cin>> n;
	for(int i= 0; i < n; i++)
	{
		cout <<"Nhap ten dinh: ";
		cin >> vertex[i];
		cout <<"Nhap vao dong thu " << i + 1<< ":  ";
		for(int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}

//Cau 6.2: Xuat ma tran ke
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n;j++)
			cout <<A[i][j]<< " ";
		cout << endl;
	}
}

void outPut(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]]<< " ";
}

//Cau 6.3:duyet do thi theo chieu rong BFS
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for(int i = 0; i < n; i++)
		C[i] = 1;
}

void BFS(int v)
{
	int w, p;
	PushQ( a,rear, front, v);
	C[v] = 0;
	while(front != -1)
	{
		PopQ(a,rear, front, p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
		{
			if(C[w] && A[p][w] == 1)
			{
				PushQ(a,rear, front, w);
				C[w] = 0;
			}
		}
	}
}

//Cau 6.4: duyet do thi theo DFS
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
			PopS( a,sp,u);
		for(v = 0; v < n;v++)
			if(A[u][v]!=0 && C[v] == 1)
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
int main()
{
	int a[MAX];
	int b[MAX];
	int choice, sp, sp_b, x, i;
	system("cls");
	cout <<"------------BAI TAP 6, CHUONG 5, DO THI------------" << endl;
	cout <<"1.Khoi tao ma tran ke rong \n";
	cout <<"2.Nhap ma tran ke tu file text \n";
	cout <<"3.Nhap ma tran ke \n";
	cout <<"4.Xuat ma tran ke \n";
	cout <<"5.Duyet do thi theo BFS - DSLK \n" ;
	cout <<"6.Duyet do thi theo dfs - DSLK \n ";
	cout <<"7.Thoat \n" ;
	do{
		cout <<"Vui long chon so de thuc hien: ";
		cin>> choice ;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao ma tran ke rong thanh cong! \n";
			break;
		case 2:
			inputGraphFromText();
			cout <<"Ban vua nhap ma tran ke tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQueue( a, front,rear);
			initC();
			cout <<"Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout <<"Thu tu dinh sau khia duyet BFS: " << endl;
			outPut(bfs, n);
			break;
		case 6:
			InitStack( a,sp);
			initC();
			cout <<"Vui long nhap dnh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout <<"Thu tu dinh sau khia duyet BFS: " << endl;
			outPut(dfs, n);
			break;
		case 7:
			cout <<"---GOODBYE---" << endl;
			break;
		default:
			break;
		}
	}while(choice !=7);
	system("pause");
	return 0;
}