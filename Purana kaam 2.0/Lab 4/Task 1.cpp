#include<iostream>
#include<cmath>
using namespace std;

class Circle{
	float radius,area,perim;
	public:
		Circle()
		{
			
		}
		Circle(float r)
		{
			radius=r;
			area=3.142*pow(radius,2);
			perim=2*3.142*radius;
		}
		float getArea()
		{
			return area;
		}
		float getPerimeter()
		{
			return perim;
		}
};

int main()
{
	Circle obj(1);
	
	cout<<endl<<"Area: "<<obj.getArea()<<endl<<"Perimeter: "<<obj.getPerimeter();
	
	return 1;
}
