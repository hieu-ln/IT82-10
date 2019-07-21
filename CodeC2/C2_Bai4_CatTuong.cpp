#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};Node *first ;

void init()
{
	first = NULL;
}

void process_list()
{
	Node *p = first ;
	while(p!= NULL)
	{
		cout << p ->info  << " ";
		p = p ->link ;
	}
	cout << endl;
}


void insert_After(int value, int loca)
{
	Node* p= new Node;
	p->info = value;
	p->link= NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node* q = first;
		int dem = 0;
		while(q->link != NULL && dem != loca - 1 )
		{
			if(q->link == NULL)
				cout <<"ko ton tai\n";
			dem++;
			q = q->link;
		}
		p->link = q->link;
		q->link = p ;
	}
}


Node *serch(int x)
{
	Node *p = first ;
	while(p!= NULL && p ->info != x)
	{
		p = p ->link;
	}
	return p;
}

void swapNode(Node *&p, Node *&q)
{
	Node *t = new Node;
	t->link = p->link;
	p->link = q->link;
	q->link = t->link;
	t->info = p->info;
	p->info = q->info;
	p->info = t->info;
}

void selection_Sort(Node *p)
{
	p = first;
	Node *q= first ;
	Node *e = first;
	q = p->link;

	while(p->info != NULL)
	{
		e = p;
		while(q->link != NULL)
		{
			if(e->info > q->info)
			{
				swapNode(e,q);
			}
			e = q;
			q = q->link ;
		}
		p = p->link;
	}
}

int search_And_Delte(int x)
{
	if(first != NULL)
	{
		Node* p, *q;
		p = first;
		q = first;
		while(p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link ;
		}
		if(p != first && p!= NULL)
		{
			if(p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
			if(p == first)
			{
				first = p->link;
				delete p;
				return 1;
			}
			else
				return 0;
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i, loca;
	Node *p = new Node;
	cout << ".............BAI TAP 04, CHUONG 01 - BAI TAP THEM \n" ;
	cout << "1.khoi tao danh sach lien ket don \n";
	cout << "2.them phan tu vao dau DSLK don tai vi tri bat ki \n";
	cout << "3.tim phan tu voi gia tri x  \n" ;
	cout <<"4.tim phan tu voi gia tri x va xoa no \n";
	cout << "5. Thoat\n";
	do{
		cout <<"chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
			init();
			cout << "khoi tao DSLK don thanh cong! \n";
			break;
		case 2:
			cout << "nhap gia tri can them: ";cin >> x;
			cout <<"nhap vi tri can them: "; cin >> loca;
			insert_After( x,  loca);
			cout << "danh sach sau khi them la: \n";
			process_list();
			break;
		case 3:
			/*selection_Sort(p);*/
			cout <<"nhap gia tri can tim: ";cin>> x;
			p = serch( x);;
			if(p != NULL)
				cout <<"tim thay phan tu co gia tri x=" << x << endl;
			else
				cout <<"khong tim thay phan tu co gia tri x=" << x << endl;
			break;
		case 4:
			/*selection_Sort(p);*/
			cout <<"nhap gia tri x can tim va xoa: ";cin>>x;
			i = search_And_Delte( x);
			if(i == 1)
			{
				cout <<"tim thay gia tri x=" << x << " da xoa thanh cong \n";
				cout <<"dnah sach sau khi xoa la: \n";
				process_list();
			}
			else
				cout <<"khong tim thay phan tu x="<<x << endl;
			break;
		case 5:
			cout <<"GOODBYE !" << endl;
		default:
			break;
		}
	}while(choice != 5);
	system("pause");
	return 0;
}