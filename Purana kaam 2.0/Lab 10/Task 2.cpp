#include <iostream>

using namespace std;

class Car{
	protected:
	string model;
	float price;
	public:
		void setModel(string mod)
		{
			model = mod;
		}
		virtual void setPrice(float prc)
		{
		}
		string getModel()
		{
			return model;
		}
		float getPrice()
		{
			return price;
		}
		void display()
		{
			cout << endl << "Model: "<<model<<endl<<"Price: "<<price;
		}
};

class Color : public Car{
	public:
		void setPrice(float prc)
		{
			price=prc;
		}
		
};

class Company : public Car{
	public:
		void setPrice(float prc)
		{
			price=prc*1000;
		}
	
};

int main()
{
	Car *ptr1,*ptr2;
	Color obj1;
	Company obj2;
	ptr1=&obj1;
	ptr2=&obj2;
	
	ptr1->setModel("Color model");
	ptr2->setModel("Company model");
	
	ptr1->setPrice(5);
	ptr2->setPrice(5);
	
	ptr1->display();
	ptr2->display();
	
	return 1;
}
