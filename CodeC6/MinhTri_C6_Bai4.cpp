#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Khai báo ma trận bằng mảng 2 chiều
#define MAX 20
int a[MAX][MAX];
int n; //Số đỉnh của đồ thị
char vertex[MAX]; //Tên đỉnh

void Init_Graph()
{
	n = 0;
}

void Input_Graph_From_Text()
{	
	ifstream myfile("mt4.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i=0; i<n; i++)
			myfile >> vertex[i];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				myfile >> a[i][j];
		}
	}
}

//Nhập ma trận kề của đồ thị
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
			cin >> a[i][j];
	}
}

//Xuất ma trận kề của đồ thị
void Output_Graph()
{
	cout << setw(5) << left;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << a[i][j] << setw(5) << left;
		cout << endl;
	}
}

//Khai báo tập E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; //Số phần tử tập

//Khai báo tập T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0; //Số phần tử tập

int TonTai(int d, int D[], int nD)
{
	for(int i=0; i<nD; i++)
	if(D[i] == d)
		return 1;
	return 0;
}

void Xoa_Vi_Tri_E(int i)
{
	for(int j=i; j<nE; j++)
	{
		E1[j] = E1[j+1];
		E2[j] = E2[j+1];
		wE[j] = wE[j+1];
	}
	nE--;
}

void Xoa_Canh_E(int u, int v)
{
	for(int i=0; i<nE; i++)
		if(E1[i]==u && E2[i]==v)
		{
			Xoa_Vi_Tri_E(i);
			break;
		}
}

void Prim(int s) //s là đỉnh bắt đầu
{
	int u = s, min, i, d1, d2;
	while(nT < n-1)
	{
		for(int v=0; v<n; v++)
		if(a[u][v] != 0)
			if(TonTai(v, T2, nT) == 0)
			{
				E1[nE] = u;
				E2[nE] = v;
				wE[nE] = a[u][v];
				nE++;
			}
		for(i = 0; i<nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		for(i = 0; i<nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
				if(min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		Xoa_Canh_E(d1, d2);
		u = d2;
	}
}

void OutPut(bool VertexName)
{
	int tong = 0;
	for(int i = 0; i<nT; i++)
	{
		if(VertexName)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
		else	
			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong = " << tong << endl;
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "--------- BAI TAP 4, CHUONG 6, TIM KIEM CAY KHUNG TOI TIEU, PRIM --------" << endl;
	cout << "1. Khoi tao MA TRAN KE rong " << endl;
	cout << "2. Nhap MA TRAN KE TU file text " << endl;
	cout << "3. Nhap MA TRAN KE " << endl;
	cout << "4. Xuat MA TRAN KE " << endl;
	cout << "5. Tim cay khung toi tieu bang PRIM " << endl;
	cout << "6. Thoat " << endl;
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Init_Graph();
				cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!" << endl; 
				break;
			case 2:
				Input_Graph_From_Text();
				cout << "Ban vua nhap MA TRAN KE tu file: " << endl;
				Output_Graph();
				break;
			case 3:
				Input_Graph();
				break;
			case 4:
				Output_Graph();
				break;
			case 5:
				cout << "VUi long nhap dinh xuat phat: ";
				cin >> x;
				Prim(x);
				cout << "Cay khung toi tieu voi PRIM: " << endl;
				OutPut(true);
				break;
			case 6:
				cout << "Goodbye .....! " << endl;

				break;
			default:
				break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}