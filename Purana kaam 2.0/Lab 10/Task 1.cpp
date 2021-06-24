#include <iostream>

using namespace std;

class Shape{
	public:
		virtual float getArea()
		{
		}
};

class Rectangle : public Shape{
	int l,b;
	public:
		void setDimensions(int len,int bre)
		{
			l=len;
			b=bre;
		}
		float getArea()
		{
			return l*b;
		}
};

class Triangle : public Shape{
	int h,b;
	public:
		void setDimensions(int hei,int bas)
		{
			h=hei;
			b=bas;
		}
		float getArea()
		{
			return h*b/2.0;
		}
};

int main()
{
	Shape *ptr1,*ptr2;
	Triangle obj1;
	Rectangle obj2;
	obj1.setDimensions(10,2);
	obj2.setDimensions(5,4);
	ptr1=&obj1;
	ptr2=&obj2;
	cout<<ptr1->getArea()<<endl;
	cout<<ptr2->getArea();
}
