//#include  <iostream>
//using namespace std;
//
//struct node {
//	int info;
//	node *link;
//};
//
//node *first;
//
//void init() {
//	first = NULL;
//	cout << "Danh sach da khoi tao.\n";
//}
//
//void duyetList() {
//	node *p;
//	p = first;
//	cout << "Cac phan tu trong mang:\n";
//	while (p!=NULL)
//	{
//		cout << p->info << endl;
//		p = p->link;
//	}
//	cout << endl;
//}
//
//node *search() {
//	int a;
//	cout << "Nhap vao  gia tri can tim: ";
//	cin >> a;
//	node *p = first;
//	while (p!=NULL && p->info!=a)
//	{
//		p = p->link;
//	}
//	return p;
//}
//
//void insert_first() {
//	node *p = new node;
//	int a;
//	cout << "Nhap vao gia tri can them: ";
//	cin >> a;
//	p->info = a;
//	p->link = first;
//	first = p;
//}
//
//void insert_last() {
//	node *p = new node;
//	int a;
//	cout << "Nhap vao gia tri can them cuoi danh sach:";
//	cin >> a;
//	p->info = a;
//	p->link = NULL;
//	if (first==NULL)
//	{
//		first = p;
//	}
//	else
//	{
//		node*q = first;
//		while (q->link!=NULL)
//		{
//			q = q->link;
//		}
//		q->link = p;
//	}
//}
//
//void delete_first() {
//	if (first == NULL)
//	{
//		cout << "Ham khong co phan tu nao!\n";
//	}
//	else {
//		node *p = first;
//		first = p->link;
//		delete p;
//		duyetList();
//	}
//}
//
//void delete_last() {
//	node*p = first;
//	node*q = NULL;
//	while (p->link!=NULL)
//	{
//		q = p;
//		p = p->link;
//	}
//	if (p!=first)
//	{
//		q->link = NULL;
//	}
//	else {
//		first = NULL;
//	}
//	delete p;
//	duyetList();
//}
//
//void timxoa() {
//	node *p = first;
//	node *q = NULL;
//	int a;
//	cout << "Nhap gia tri can tim va xoa: ";
//	cin >> a;
//	if (first!=NULL)
//	{
//		while (p->link!=NULL&&p->info!=a)
//		{
//			q = p;
//			p = p->link;
//		}if (p->info!=a)
//		{
//			cout << "Khong tim thay phan tu!\n";
//		}
//		else {
//			if (p==first)
//			{
//				if (p->link!=NULL)
//				{
//					first = p->link;
//					delete p;
//				}
//				else{
//					first = NULL;
//				}
//			}
//			else {
//				q->link = p->link;
//				delete p;
//			}
//		}
//	}
//	else {
//		cout << "Mang rong!\n";
//	}
//	duyetList();
//}
//
//int main() {
//	cout << "Khoi tao danh sach rong.\n";
//	init();
//	cout << "1.Them dau danh sach\n"
//		<< "2.Them cuoi danh sach\n"
//		<< "3.Tim phan tu trong danh sach\n"
//		<< "4.Xoa phan tu dau danh sach\n"
//		<< "5.Xoa phan tu cuoi danh sach\n"
//		<< "6.Tim va xoa phan tu\n"
//		<< "7.Thoat!\n";
//	int select;
//	do
//	{
//		cout << "Vui long chon thao tac muon lam: ";
//		cin >> select;
//		switch (select){
//		case 1:
//			insert_first();
//			duyetList();
//			break;
//		case 2:
//			insert_last();
//			duyetList();
//			break;
//		case 3:
//			if (search()==NULL)
//			{
//				cout << "Khong tim thay phan tu!\n";
//			}
//			else {
//				cout << "Da tim thay phan tu!\n";
//			}break;
//		case 4:
//			delete_first();
//			break;
//		case 5:
//			delete_last();
//			break;
//		case 6:
//			timxoa();
//			break;
//		default:
//			break;
//		}
//	} while (select < 7);
//	cout << "Da thoat!\n";
//	system("pause");
//	return 0;
//}