#include <iostream>

using namespace std;

class Vehicle{
	protected:
		string type,make,model,color;
		int year;
		float miles;
	public:
		Vehicle(string a,string b,string c,string d,int e,float f)
		{
			type=a;
			make=b;
			model=c;
			color=d;
			year=e;
			miles=f;
		}
};

class ElectricVehicle : virtual public Vehicle{
	protected:
		int storage;
	public:
		ElectricVehicle(string a,string b,string c,string d,int e,float f, int g) : Vehicle(a,b,c,d,e,f)
		{
			storage=g;
		}
};

class GasVehicle : virtual public Vehicle{
	protected:
		int size;
	public:
		GasVehicle(string a,string b,string c,string d,int e,float f, int g) : Vehicle(a,b,c,d,e,f)
		{
			size=g;
		}
};

class HighPerformance : public GasVehicle{
	protected:
		int horsepower;
		float topspeed;
	public:
		HighPerformance(string a,string b,string c,string d,int e,float f, int g, int h, float i) : GasVehicle(a,b,c,d,e,f,g), Vehicle(a,b,c,d,e,f)
		{
			horsepower=h;
			topspeed=i;
		}
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle{
	protected:
		int max_weight, no_tires, length;
	public:
		HeavyVehicle(string a,string b,string c,string d,int e,float f, int g, int h, int i, int j, int k) : GasVehicle(a,b,c,d,e,f,g), ElectricVehicle(a,b,c,d,e,f,h), Vehicle(a,b,c,d,e,f)
		{
			max_weight=i;
			no_tires=j;
			length=k;
		}
};

class ConstructionTruck : public HeavyVehicle{
	protected:
		string cargo;
	public:
		ConstructionTruck(string a,string b,string c,string d,int e,float f, int g, int h, int i, int j, int k, string l) : HeavyVehicle(a,b,c,d,e,f,g,h,i,j,k), Vehicle(a,b,c,d,e,f)
		{
			cargo=l;
		}
};

class Bus : public HeavyVehicle{
	protected:
		int no_seats;
	public:
		Bus(string a,string b,string c,string d,int e,float f, int g, int h, int i, int j, int k, int l) : HeavyVehicle(a,b,c,d,e,f,g,h,i,j,k), Vehicle(a,b,c,d,e,f)
		{
			no_seats = l;
		}
		void display()
		{
			cout<<endl<<type<<endl<<make<<endl<<model<<endl<<color<<endl<<year<<endl<<miles<<endl<<size<<endl<<storage<<endl<<max_weight<<endl<<no_tires<<endl<<length<<endl<<no_seats;
		}
};

class SportsCar : public HighPerformance{
	protected:
		string gearbox, system;
	public:
		SportsCar(string a,string b,string c,string d,int e,float f, int g, int h, float i, string j, string k) : HighPerformance(a,b,c,d,e,f,g,h,i), Vehicle(a,b,c,d,e,f)
		{
			gearbox = j;
			system = k;
		}
};

int main()
{
	Bus obj("SUV","Toyota","Corolla","Black",2007,25.3,37,13,400,4,3,5);
	obj.display();
	return 0;
}

