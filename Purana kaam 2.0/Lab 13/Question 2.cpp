#include<iostream>

using namespace std;

#define SIZE 10

template <class T>
int findloc(T x,T arr[SIZE])
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(arr[i]==x)
		{
			break;
		}
	}
	return i;
}

int main()
{
	float find=55,arr[SIZE]={10,20,30,40,50,11,22,33,44,55};
	cout<<"Location of number "<<find<<" in array is at index "<<findloc(find,arr);
	return 0;
}
