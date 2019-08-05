#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

void tree_empty()
{
	root=NULL;
}

void insertNode(Node *&p,int x)
{
	if(p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return;
		else if(p->info>x)
			return insertNode(p->left,x);
		else
			return insertNode(p->right,x);
	}
}

int Search(Node *p,int x)
{
	if(p!=NULL)
	{
		if(p->info==x)
			return 1;
		else
		{
			if(x>p->info)
				return Search(p->right,x);
			else
				return Search(p->left,x);
		}
	}
	return NULL;
}

void searchStandFor(Node *&p,Node *&q)
{
	if(q->left==NULL)
	{
		p->info==q->info;
		p=q;
		q=q->right;
	}
	else
		searchStandFor(p,q->left);
}

int Delete(Node *T,int x)
{
	if(T==NULL)
		return 0;
	if(T->info==x)
	{
		Node *p=T;
		if(T->left==NULL)
			T=T->right;
		else if(T->right==NULL)
			T=T->left;
		else
			searchStandFor(p,T->right);
		delete p;
		return 1;
	}
	if(T->info<x)
		return Delete(T->right,x);
	if(T->info>x)
		return Delete(T->left,x);
}

void duyetLNR(Node *p)
{
	if(p!=NULL)
	{
		duyetLNR(p->left);
		cout << "\t" << p->info;
		duyetLNR(p->right);
	}
}

void duyetNLR(Node *p)
{
	if(p!=NULL)
	{
		cout << "\t" << p->info;
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

void duyetLRN(Node *p)
{
	if(p!=NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << "\t" << p->info;
	}
}

int main()
{
	int x,z;
	cout << "-------------------------------MENU------------------------------" << endl;
	cout << "1. Khoi tao tree" << endl;
	cout << "2. Them vao tree" << endl;
	cout << "3. Tim trong tree" << endl;
	cout << "4. Xoa trong tree" << endl;
	cout << "5. Duyet LNR" << endl;
	cout << "6. Duyet NLR" << endl;
	cout << "7. Duyet LRN" << endl;
	cout << "8. exit" << endl;
	do
	{
		cout << "Moi lua chon: ";
		cin >> z;
		switch(z)
		{
			case 1:
				tree_empty();
				cout << "Khoi tao thanh cong. " << endl;
				break;
			case 2:
				cout << "nhap gia tri can them: ";
				cin >> x;
				insertNode(root,x);
				break;
			case 3:
				cout << "nhap gia tri can tim: ";
				cin >> x;
				if(Search(root,x)==NULL)
					cout << "khong tim thay gia tri can tim." << endl;
				else
					cout << "tim thay." << endl;
				break;
			case 4:
				cout << "nhap gia tri can xoa: ";
				cin >> x;
				if(Delete(root,x)==0)
					cout << "khoa khong thanh cong." << endl;
				else
					cout << "xoa thanh cong." << endl;
				break;
			case 5:
				duyetLNR(root);
				break;
			case 6:
				duyetNLR(root);
				break;
			case 7:
				duyetLRN(root);
				break;
			case 8:
				cout << "good bye." << endl;
				break;
			default:
				cout << "nhap sai." << endl;
				break;
		}
	}while(z!=8);
	system("pause");
	return 0;
}
