#include <iostream>

using namespace std;

class Perimeter{
	int l,b,perimeter;
	public:
		void setDimensions(int len, int bre)
		{
			l=len;
			b=bre;
		}
		void calculatePerimeter()
		{
			perimeter = 2*l + 2*b;
		}
		friend class printClass;
};

class printClass{
	public:
	void print(const Perimeter &obj)
	{
		cout<<obj.perimeter;
	}
};

int main()
{
	Perimeter obj1;
	printClass obj2;
	obj1.setDimensions(5,4);
	obj1.calculatePerimeter();
	obj2.print(obj1);
}
