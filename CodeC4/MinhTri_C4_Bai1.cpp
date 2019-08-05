﻿#include <iostream>
#include <stdio.h>
using namespace std;

#define COUNT 10

//1.1: Khai báo cấu trúc cây nhị phân tìm kiếm
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//1.2: Khởi tạo cây rỗng
void Init()
{
	root = NULL;
}

//1.3: Thêm 1 pt vào cây (dùng đệ quy)
void Insert_Node(Node *&p, int x)
{
	if(p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(p->info == x)
			return; //đã có giá trị x
		else
			if(p->info > x)
				return Insert_Node(p->left, x);
			else
				return Insert_Node(p->right, x);
	}
}

//1.4: Tìm 1 pt trong cây (dùng đệ quy)
Node *Search(Node *p, int x)
{
	if(p != NULL)
	{
		if(p->info == x)
			return p;
		else
			if(x > p->info)
				return Search(p->right, x);
			else
				return Search(p->left, x);
	}
	return NULL;
}

//1.5: Xóa 1 nút trong cây (dùng đệ quy)
void Search_Stand_For(Node *&p, Node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		Search_Stand_For(p, q->left);
}
int Delete(Node *&T, int x)
{
	if(T == NULL)
		return 0;
	if(T->info == x)
	{
		Node *p = T;
		if(T->left == NULL) //Bậc 1
			T = T->right;
		else
			if(T->right == NULL) //Bậc 1
				T = T->left;
			else
				Search_Stand_For(p, T->right);
		delete p;
		return 1;
	}
	if(T->info < x)
		return Delete(T->right, x);
	if(T->info > x)
		return Delete(T->left, x);
}

//1.6: Duyệt cây theo NLR (dùng đệ quy)
void Duyet_NLR(Node *p)
{
	if(p != NULL)
	{
		cout << p->info << " ";
		Duyet_NLR(p->left);
		Duyet_NLR(p->right);
	}
}

//1.7: Duyệt cây theo LNR (dùng đệ quy)
void Duyet_LNR(Node *p)
{
	if(p != NULL)
	{
		Duyet_LNR(p->left);
		cout << p->info << " ";
		Duyet_LNR(p->right);
	}
}

//1.8: Duyệt cây theo LRN (dùng đệ quy)
void Duyet_LRN(Node *p)
{
	if(p != NULL)
	{
		Duyet_LRN(p->left);
		Duyet_LRN(p->right);
		cout << p->info << " ";
	}
}

//In hình cây
void Print_2D_Util(Node *p, int space)
{
	//Base case
	if(p == NULL)
		return;

	//Increase distance between levels
	space += COUNT;

	//Process right child first
	Print_2D_Util(p->right, space);

	//Print current node after space
	//count
	cout << endl;
	for(int i=COUNT; i<space; i++)
		cout << " ";
	cout << p->info << endl;

	//Process left child
	Print_2D_Util(p->left, space);
}

//Wrapper over Print_2D_Util()
void Process_Tree()
{
	//Pass initial space count as = 0
	Print_2D_Util(root, 0);
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "------BAI TAP 1, CHUONG 4, CAY NPTK------" << endl;
	cout << "1. Khoi tao cay nhi phan rong" << endl;
	cout << "2. Them 1 pt vao cay NPTK" << endl;
	cout << "3. Tim pt gia tri x trong cay NPTK" << endl;
	cout << "3. Xoa pt gia tri x trong cay NPTK" << endl;
	cout << "4. Duyet cay NPTK theo NLR" << endl;
	cout << "5. Duyet cay NPTK theo LNR" << endl;
	cout << "6. Duyet cay NPTK theo LRN" << endl;
	cout << "7. Xuat cay NPTK" << endl;
	cout << "8. Thoat" << endl;
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Init();
				cout << "Ban vua khoi tao cay NPTK thanh cong!" << endl;
				break;
			case 2:
				cout << "Vui long nhap gia tri x can them: ";
				cin >> x;
				Insert_Node(root, x);
				cout << "Cay NPTK sau khi them la: ";
				Process_Tree();
				break;
			case 3:
				cout << "Vui long nhap gia tri x can tim: ";
				cin >> x;
				p = Search(root, x);
				if(p != NULL)
					cout << "Tim thay x = " << x << " trong cay NPTK" << endl;
				break;
			case 4:
				cout << "Vui long nhap gia tri x can xoa";
				cin >> x;
				i = Delete(root, x);
				if (i == 0)
					cout << "Khong tim thay x = " << x << " de xoa!" << endl;
				else
				{
					cout << "Da xoa thanh cong pt x = " << x << " trong cay NPTK" << endl;
					cout << "Cay NPTK sau khi xoa la: ";
					Process_Tree();
				}
				break;
			case 5:
				cout << "Cay NPTK duyet theo NLR la: ";
				Duyet_NLR(root);
				break;
			case 6:
				cout << "Cay NPTK duyet theo LNR la: ";
				Duyet_LNR(root);
				break;
			case 7:
				cout << "Cay NPTK duyet theo LRN la: ";
				Duyet_LRN(root);
				break;
			case 8:
				cout << "Cay NPTK nhu sau: ";
				Process_Tree();
				break;
			case 9:
				cout << "Goodbye.....!" << endl;
				break;
			default:
				break;
		}
	}while(choice != 9);
	system("pause");
	return 0;
}