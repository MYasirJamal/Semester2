#include<iostream>

using namespace std;

template <class T>
void swaparg(T &a, T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	int x=5,y=10;
	swaparg(x, y);
	cout<<x<<endl<<y<<endl;
}
