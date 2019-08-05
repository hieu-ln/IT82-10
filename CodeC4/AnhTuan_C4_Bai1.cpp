//#include<iostream>
//#include<stdio.h>
//#define COUNT 5
//
//using namespace std;
//
//struct Node{
//	int info;
//	Node *left;
//	Node *right;
//};
//Node *root;
//
//void init(){
//	root = NULL;
//}
//
//int insertNode(int x, Node *q){
//	if (q->info == x)
//		return 0;
//	else
//		if (q->info > x){
//			if (q->left == NULL){
//				Node *p = new Node;
//				p->info = x;
//				p->left = NULL;
//				p->right = NULL;
//				q->left = p;
//				return 1;
//			}
//			else
//				return insertNode(x, q->left);
//		}
//		else{
//			if (q->right == NULL){
//				Node *p = new Node;
//				p->info = x;
//				p->left = NULL;
//				p->right = NULL;
//				q->right = p;
//				return 1;
//			}
//			else
//				return insertNode(x, q->right);
//		}
//}
//
//void insertNodePointer(Node *&p, int x){
//	if (p == NULL){
//		p = new Node;
//		p->info = x;
//		p->left = NULL;
//		p->right = NULL;
//	}
//	else{
//		if (p->info == x)
//			return;
//		else if (p->info > x)
//			return insertNodePointer(p->left, x);
//		else
//			return insertNodePointer(p->right, x);
//	}
//}
//
//Node *search(Node *p, int x){
//	if (p != NULL){
//		if (p->info == x)
//			return p;
//		else
//			if (x > p->info)
//				return search(p->right, x);
//			else
//				return search(p->left, x);
//	}
//	return NULL;
//}
//
//void searchForDel(Node *&p, Node *&q){
//	if (q->left == NULL){
//		p->info = q->info;
//		p = q;
//		q = q->right;
//	}
//	else
//		searchForDel(p, q->left);
//}
//
//int deleteNode(Node *&T, int x){
//	if (T == NULL)
//		return 0;
//	if (T->info == x){
//		Node *p = T;
//		if (T->left == NULL)
//			T = T->right;
//		else if (T->right == NULL) 
//			T = T->left;
//		else 
//			searchForDel(p, T->right);
//		delete p;
//		return 1;
//	}
//	else if (T->info < x)
//		return deleteNode(T->right, x);
//	else
//		return deleteNode(T->left, x);
//}
//
//void processLNR(Node *p){
//	if (p != NULL){
//		processLNR(p->left);
//		cout << p->info << "  ";
//		processLNR(p->right);
//	}
//}
//
//void processNLR(Node *p){
//	if (p != NULL){
//		cout << p->info << "  ";
//		processNLR(p->left);
//		processNLR(p->right);
//	}
//}
//
//void processLRN(Node *p){
//	if (p != NULL){
//		processLRN(p->left);
//		processLRN(p->right);
//		cout << p->info << "  ";
//	}
//}
//
//void xuatTree(Node *p, int space){
//	if (p == NULL)
//		return;
//	space += COUNT;
//	xuatTree(p->right, space);
//	cout << endl;
//	for (int i = COUNT; i < space; i++)
//		cout << "  ";
//	cout << p->info << "\n";
//	xuatTree(p->left, space);
//}
//
//void processTree(){
//	xuatTree(root, 0);
//}
//
//int main(){
//	int select = 0;
//	int x, i;
//	Node *p;
//	cout << "1. Khoi tao cay NPTK rong" << endl
//		 << "2. Them phan tu vao cay NPTK" << endl
//		 << "3. Tim phan tu co gia tri x trong cay NPTK" << endl
//		 << "4. Xoa gia tri co gia tri x trong cay NPTK" << endl
//		 << "5. Duyet cay NPTK theo LNR" << endl
//		 << "6. Duyet cay NPTK theo NLR" << endl
//		 << "7. Duyet cay NPTK theo LRN" << endl
//		 << "8. Xuat cay NPTK" << endl
//		 << "9. Thoat" << endl;
//	do{
//		cout << " \nVui long cho so de thuc hien: ";
//		cin >> select;
//		switch (select){
//		case 1:
//			init();
//			cout << "Da khoi tao cay NPTK thanh cong!\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri x can them: ";
//			cin >> x;
//			insertNodePointer(root, x);
//			cout << "Cay NPTK sau khi them la: ";
//			processTree();
//			break;
//		case 3:
//			cout << "Nhap gia tri x can tim: ";
//			cin >> x;
//			p = search(root, x);
//			if (p != NULL)
//				cout << "Tim thay " << x << " trong cay NPTK\n";
//			else
//				cout << "Khong tim thay " << x << " trong cay NPTK\n";
//			break;
//		case 4:
//			cout << "Nhap gia tri x can xoa: ";
//			cin >> x;
//			i = deleteNode(root, x);
//			if (i == 0)
//				cout << "Khong tim thay phan tu " << x << " de xoa!";
//			else{
//				cout << "Da xoa thang cong phan tu " << x << endl;
//				cout << " Cay NPTK sau khi xoa: ";
//				processTree();
//			}
//			break;
//		case 5:
//			cout << "Cay NPTK duyet theo LNR: ";
//			processLNR(root);
//			break;
//		case 6:
//			cout << "Cay NPTK duyet theo NLR: ";
//			processNLR(root);
//			break;
//		case 7:
//			cout << "Cay NPTK duyet theo LRN: ";
//			processLRN(root);
//			break;
//		case 8:
//			cout << " Cay NPTK: \n";
//			processTree();
//			break;
//		case 9:
//			cout << "Da Thoat!\n";
//			break;
//		default:
//			break;
//		}
//	} while (select != 9);
//	system("pause");
//	return 0;
//}