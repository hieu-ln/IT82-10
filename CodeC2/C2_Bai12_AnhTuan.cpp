//#include <iostream>
//using namespace std;
//
//struct node {
//	int info;
//	node *next,*previous;
//};
//
//node *first;
//node *last;
//
//void taoDs() {
//	first = NULL;
//	last = NULL;
//	cout << "Da khoi tao danh sach!\n";
//}
//
//void process_list() {
//	node *p;
//	p = first;
//	cout << "Cac phan tu trong danh sach:\n";
//	while (p!=NULL)
//	{
//		cout << p->info << endl;
//		p = p->next;
//	}
//}
//
//void insert_first() {
//	int x;
//	node *p = new node;
//	cout << "Nhap gia tri can chen:";
//	cin >> x;
//	p->next = first;
//	p->previous = NULL;
//	if (first!=NULL){
//		first->previous = p;
//	}
//	else {
//		last = p;
//	}
//	first = p;
//}
//
//void insert_last() {
//	int x;
//	cout << "Nhap vao gia tri can them: ";
//	cin >> x;
//	node *p = new node;
//	p->info = x;
//	p->next = NULL;
//	p->previous = last;
//	if (last!=NULL)
//	{
//		last->next = p;
//	}
//	else {
//		first = p;
//	}
//	last = p;
//}
//
//int delete_first() {
//	if (first!=NULL)
//	{
//		node*p = first;
//		first = first->next;
//		delete p;
//		if (first!=NULL)
//		{
//			first->previous = NULL;
//		}
//		else {
//			last = NULL;
//		}
//		return 1;
//	}
//	return 0;
//}
//
//int delete_last() {
//	if (last!=NULL)
//	{
//		node*p = last;
//		last = last->previous;
//		if (last!=NULL)
//		{
//			last->next = NULL;
//		}
//		else {
//			first = NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//
//int main() {
//	cout << "Khoi tao danh sach: \n";
//	taoDs();
//	cout << "1.Them dau danh sach\n"
//		 << "2.Them cuoi danh sach\n"
//		 << "3.Xoa dau danh sach\n"
//		 << "4.Xoa cuoi danh sach\n"
//		 << "5.Thoat.\n ";
//	int select;
//	do {
//		cout << "Vui long chon thao tac muon lam: ";
//		cin >> select;
//		switch (select) {
//		case 1:
//			insert_first();
//			process_list();
//			break;
//		case 2:
//			insert_last();
//			process_list();
//			break;
//		case 3:
//			delete_first();
//			process_list();
//			break;
//		case 4:
//			delete_last();
//			process_list();
//			break;
//		default:
//			break;
//		}
//	} while (select < 5);
//	cout << "Da thoat!\n";
//	system("pause");
//	return 0;
//		
//}