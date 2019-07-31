#include <stdio.h>
#include <iostream>
using namespace std;

#define COUNT 10
 //cau 1.1
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//cau 1.2:Khoi tao cay rong
void Inti()
{
	root=NULL;
}

//Cau 1.3: Them mot phan tu vao cay
void InsertNode (Node *&p, int x)
{
	if (p==NULL)
	{
		p=new Node;
		p->info=x;
		p->right=NULL;
		p->left=NULL;
	}
	else
	{
		if (p->info==x)
			return;
		else
			if (p->info >x)
				return InsertNode (p->left, x);
			else return InsertNode (p->right, x);
	}
}

//Cau 1.4: Tim kiem mot phan tu trong cay
Node *search (Node *p, int x)
{
	if (p!=NULL)
	{
		if (p->info ==x)
			return p;
		else
			if (x > p->info)
				return search (p->right, x);
			else return search (p->left, x);
	}
	return NULL;
}

//Cau 1.5: Xoa mot nuts tren cay
void SearchStandFor (Node *&p, Node *&q)
{
	if (q->left==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
	}
	else SearchStandFor(p,q->right);
}
int Delete (Node *&p, int x)
{
	if (p==NULL) return 0;
	if(p->info ==x)
	{
		Node *q = p;
		if ( p->left==NULL)
			p=p->right;
		else
			if (p->right == NULL)
				p=p->left;
			else
				SearchStandFor (q,p->right);
		delete p;
		return 1;
	}
	if (p->info<x) return Delete (p->right, x);
	if (p->info>x) return Delete (p->left, x);
}

//Cau 1.6: Duyet cay theo thu tu NLR
void DuyetNLR (Node *p)
{
	if (p!=NULL)
	{
		cout<<p->info<<" ";
		DuyetNLR (p->left);
		DuyetNLR (p->right);
	}
}

//Cau 1.7: Duyet cay theo thu tu LNR
void DuyetLNR (Node*p)
{
	if (p!=NULL)
	{
		DuyetLNR (p->left);
		cout<<p->info<<" ";
		DuyetLNR (p->right);
	}
}

//Cau 1.8: Duyet cay theo thu tu LRN
void DuyetLRN (Node *p)
{
	if (p!=NULL)
	{
		DuyetLRN (p->left);
		DuyetLRN (p->right);
		cout<<p->info<<" "; 
	}
}


//In cay nhi phan ra man hinh
void print2DUtil (Node *p, int space)
{
	if (p==NULL)
		return;
	
	space +=COUNT;
	print2DUtil (p->right, space);

	cout<<endl;
	for (int i= COUNT; i < space; i++)
		cout<<" ";
	cout<<p->info<<"\n";

	print2DUtil (p->left, space);

}

void ProcessTree()
{
	print2DUtil (root,0);
}


int main()
{
	int choice=0;
	int x, i;
	Node *p;

	system("cls");
	cout<<"------BAI TAP 1, CHUONG 4: CAY NHI PHAN TIM KIEM------"<<endl;
	cout<<"1. Khoi tao CAY NPTK rong "<<endl;
	cout<<"2. Them phan tu vao CAY NPTK"<<endl;
	cout<<"3. Tim phan tu co gia tri x trong CAY NPTK"<<endl;
	cout<<"4. Xoa phan tu co gia tri x trong CAY NPTK"<<endl;
	cout<<"5. Duyet CAY NPTK theo LNR"<<endl;
	cout<<"6. Duyet CAY NPTK theo NLR"<<endl;
	cout<<"7. Duyet CAY NPTK theo LRN"<<endl;
	cout<<"8. Xuat CAY NPTK"<<endl;
	cout<<"9. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				Inti();
				cout<<"Ban vua khoi tao xong CAY NPTK rong!"<<endl;
				break;
			case 2:
				cout<<"Vui long nhap gia tri x can them: ";
				cin>>x;
				InsertNode (root, x);
				cout<<"CAY NPTK sau khi them la: ";
				ProcessTree ();
				break;
			case 3:
				cout<<"vui long nhap phan tu x can tim: ";
				cin>>x;
				p=search (root, x);
				if (p!= NULL)
					cout<<"Tim thay phan tu x="<<x<<" trong CAY NPTK!"<<endl;
				else
					cout<<"Khong tim thay phan tu x="<<x<<" trong CAY NPTK!"<<endl;
				break;
			case 4:
				cout<<"Vui long nhap gia tri x can xoa: "<<endl;
				cin>>x;
				i=Delete (root, x);
				if (i==1)
				{
					cout<<"Da xoa thanh cong gia tri x="<<x<<endl;
					cout<<"CAY NPTK sau khi xoa la: ";
					ProcessTree ();
				}
				else
					cout<<"khong co gia tri x="<<x<<" trong CAY NPTK"<<endl;
				break;
			case 5:
				cout<<"\nCAY NPTK duyet theo LNR la: "<<endl;
				DuyetLNR (root);
				break;
			case 6:
				cout<<"\nCAY NPTK duyet theo NLR la: "<<endl;
				DuyetNLR(root);
				break;
			case 7:
				cout<<"\nCAY NPTK duyet theo LRN la: "<<endl;
				DuyetLRN  (root);
				break;
			case 8:
				cout<<"\nCAY NPTK nhu sau: "<<endl;
				ProcessTree ();
				break;
			case 9:
				cout <<"<3 ((:_+_+_+_GOODBYE_+_+_+_:)) <3"<<endl;
				break;



			default:
				break;
		}
	}while (choice!=9);
	

	system("pause");
	return 0;
}
