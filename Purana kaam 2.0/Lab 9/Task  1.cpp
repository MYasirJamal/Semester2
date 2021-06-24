#include <iostream>

using namespace std;

class overload{
	public:
    	int x;
		overload operator --()
		{
			overload obj;
			x*=4;
			obj.x=x;
			return obj;
		}
};

int main()
{
	overload obj1,obj2;
	obj1.x=5;
	obj2=--obj1;
	cout<<obj2.x;
	
	return 1;
}
