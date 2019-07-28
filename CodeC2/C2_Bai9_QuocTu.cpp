#include <stdio.h>
#include <iostream>
using namespace std;

void Tower(int n ,char A,char B,char C )
{
    if(n==1)
	{
        cout<<"\t"<<A<<"-------"<<C<<endl;
        return;
    }
    Tower(n-1,A,C,B);
    Tower(1,A,B,C);
    Tower(n-1,B,A,C);
}

int main()
{
    char A='A',B='B',C='C';
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    Tower(n,A,B,C);
    system("pause");
    return 0;
}
