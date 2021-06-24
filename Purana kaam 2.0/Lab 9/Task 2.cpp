#include <iostream>

using namespace std;

class shape{
	public:
		int x,y,area;
		void Area()
		{
			area=x*y;
		}
		shape operator + (const shape &obj)
		{
			shape temp;
			temp.area=area+obj.area;
			return temp;
		}
};

int main()
{
	shape obj1,obj2,obj3;
	obj1.x=4;
	obj1.y=5;
	obj1.Area();
	obj2.x=2;
	obj2.y=10;
	obj2.Area();
	obj3=obj2+obj1;
	cout<<obj3.area;
}
