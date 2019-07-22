//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
////Khai bao cau truc danh sach
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *first;
//
////Khoi tao danh sach rong
//void Init()
//{
//	first = NULL;
//}
//
////Xuat cac pt trong danh sach
//void Process_list()
//{
//	Node *p;
//	p = first;
//	while (p != NULL)
//	{
//		cout << p->info << "\t";
//		p = p->link;
//	}
//	cout << endl;
//}
//
////Tim 1 pt trong danh sach
//Node *search(int x)
//{
//	Node *p = first;
//	while (p != NULL && p->info != x)
//		p = p->link;
//	return p;
//}
//
//// pt vao dau danh sach
//void insert_first(int x)
//{
//	Node *p;
//	p = new Node;
//	p -> info = x;
//	p -> link = first;
//	first = p;
//}
//
////Xoa pt dau danh sach
//int delete_first()
//{
//	if (first != NULL)
//	{
//		Node *p = first;
//		first = first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
////Them pt cuoi danh sach
//void insert_last(int x)
//{
//	Node *p;
//	p = new Node;
//	p->info = x;
//	p->link	= NULL;
//	if (first == NULL)
//		first = p;
//	else
//	{
//		Node *q = first;
//		while (q->link != NULL)
//			q = q->link;
//		q->link = p;
//	}
//}
//
////Xoa pt cuoi danh sach
//int delete_last()
//{
//	if(first != NULL)
//	{
//		Node *p, *q;
//		p = first;
//		q = first;
//		while(p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first)
//			q->link = NULL;
//		else
//			first = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
////Tim pt trong danh sach, xoa pt do neu co
//int search_and_delete(int x)
//{
//	if (first != NULL)
//	{
//		Node *p, *q;
//		p = first;
//		q = first;
//		while(p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first && p != NULL)
//		{
//			if(p->link != NULL)
//				q->link = p->link;
//			else
//				q->link = NULL;
//			delete p;
//			return 1;
//		}
//		else
//			if (p == first)
//			{
//				first = p->link;
//				delete p;
//				return 1;
//			}
//			else
//				return 0;
//	}
//	return 0;
//}
//
//int main()
//{
//	int choice = 0;
//	int x, i;
//	Node *p;
//	system("cls");
//	cout << "--------------BAI TAP 3, CHUONG 2, DANH SACH LK DON--------------";
//	cout << "1. Khoi tao DSLK DON rong" << endl;
//	cout << "2. Them pt vao dau DSLK DON" << endl;
//	cout << "3. Them pt vao cuoi DSLK DON" << endl;
//	cout << "4. Xoa pt dau DSLK DON" << endl;
//	cout << "5. Xoa pt cuoi DSLK DON" << endl;
//	cout << "6. Xuat DSLK DON" << endl;
//	cout << "7. Tim 1 pt gia tri x trong DSLK DON" << endl;
//	cout << "8. Tim pt gia tri x va xoa no neu co" << endl;
//	cout << "9. Thoat" << endl;
//	do{
//		cout << "Vui long chon buoc de thuc hien: ";
//		cin >> choice;
//		switch(choice)
//		{
//			case 1:
//				Init();
//				cout << "Khoi tao DSLK DON thanh cong\n";
//				break;
//			case 2:
//				cout << "Nhap gia tri x = ";
//				cin >> x;
//				insert_first(x);
//				cout << "Danh sach sau khi them la: ";
//				Process_list();
//				break;
//			case 3:
//				cout << "Nhap gia tri x = ";
//				cin >> x;
//				insert_last(x);
//				cout << "Danh sach sau khi them la: ";
//				Process_list();
//				break;
//			case 4:
//				i = delete_first();
//				if(i == 0)
//					cout << "Danh sach rong, khong the xoa" << x << endl;
//				else
//				{
//					cout << "Da xoa thanh cong pt dau cua DSLK DON" << endl;
//					cout << "Danh sach sau khi xoa la: ";
//					Process_list();
//				}
//				break;
//			case 5:
//				delete_last();
//				if(i == 0)
//					cout << "Danh sach rong, khong the xoa" << x << endl;
//				else
//				{
//					cout << "Da xoa thanh cong phan tu cuoi cua DSLK DON" << endl;
//					cout << "Danh sach sau khi xoa la: ";
//					Process_list();
//				}
//				break;
//			case 6:
//				cout << "Danh sach hien tai la";
//				Process_list();
//				break;
//			case 7:
//				cout << "Nhap pt can tim va xoa pt do";
//				cin >> x;
//				p = search(x);
//				if(p != NULL)
//					cout << "Tim thay phan tu co gia tri x = "<< x << endl;
//				else
//					cout << "Khong tim thay phan tu co gia tri x = "<< x << endl;
//				break;
//			case 8:
//				cout << "Nhap gia tri x can tim: ";
//				cin >> x;
//				i = search_and_delete(x);
//				if (i == 1)
//				{
//					cout << "Tim thay x="<< x <<" va da xoa thanh cong"<< endl;
//					cout << "Danh sach sau khi xoa la: ";
//					Process_list();
//				}
//				else
//					cout << "Khong tim thay pt co gia tri x = " << x << endl;
//			default:
//				cout << "\nGoodbye";
//				break;
//		}
//	}while(choice !=8);
//
//	system("pause");
//	return 0;
//}