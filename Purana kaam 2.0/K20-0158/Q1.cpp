#include<iostream>

using namespace std;

class Package{
	protected:
		string name,address,city,state;
		int ZIP_send,ZIP_rec;
		float weight;
		double cost,cost_po;
	public:
		Package()
		{
		}
		Package(string n, string ad, string c, string s, int zip_s, int zip_r, float w, double cpo)
		{
			name=n;
			address=ad;
			city=c;
			state=s;
			ZIP_send=zip_s;
			ZIP_rec=zip_r;
			if(w>=0)
			{
				weight=w;
			}
			if(cpo>=0)
			{
				cost_po=cpo;
			}
		}
		
		double calculateCost()
		{
			cost=weight*cost_po;
			return cost;
		}
};

class TwoDayPackage : protected Package{
	protected:
		const double fee;
	public:
		TwoDayPackage(double f):fee(f)
		{
		}
		TwoDayPackage(string n, string ad, string c, string s, int zip_s, int zip_r, float w, double cpo, double f):fee(f),Package(n,ad,c,s,zip_s,zip_r,w,cpo)
		{
		}
		
		void input()
		{
			cout<<endl<<"Enter name of package: ";
			fflush(stdin);
			getline(cin,name);
			cout<<endl<<"Enter address of package: ";
			fflush(stdin);
			getline(cin,address);
			cout<<endl<<"City: ";
			fflush(stdin);
			getline(cin,city);
			cout<<endl<<"State: ";
			fflush(stdin);
			getline(cin,state);
			cout<<endl<<"Enter ZIP code of sender: ";
			cin>>ZIP_send;
			cout<<endl<<"Enter ZIP code of recipient: ";
			cin>>ZIP_rec;
			cout<<endl<<"Enter weight in ounces of package: ";
			cin>>weight;
			cout<<endl<<"Enter cost per ounce of package: ";
			cin>>cost_po;
		}
		
		double calculateCost()
		{
			cost=weight*cost_po;
			cost+=fee;
			return cost;
		}
		
		void display()
		{
			cout<<endl<<endl<<"--------------------------DETAILS--------------------------"<<endl<<endl;
			cout<<endl<<"Name: "<<name<<endl;
			cout<<endl<<"Address: "<<address<<endl;
			cout<<endl<<"City: "<<city<<endl;
			cout<<endl<<"State: "<<state<<endl;
			cout<<endl<<"Sender ZIP code: "<<ZIP_send<<endl;
			cout<<endl<<"Recipient ZIP code: "<<ZIP_rec<<endl;
			cout<<endl<<"Weight(ounces): "<<weight<<endl;
			cout<<endl<<"Cost per ounce: "<<cost_po<<endl;
			cout<<endl<<"Flat fee: "<<fee<<endl;
		}
};

class OvernightPackage : protected Package{
	protected:
		double fee_po;
	public:
	    OvernightPackage(string n, string ad, string c, string s, int zip_s, int zip_r, float w, double cpo, double f):Package(n,ad,c,s,zip_s,zip_r,w,cpo)
		{
			fee_po=f;
		}
		
		double calculateCost()
		{
			cost_po+=fee_po;
			cost=weight*cost_po;
			return cost;
		}
		
		void input()
		{
			cout<<endl<<"Enter name of package: ";
			fflush(stdin);
			getline(cin,name);
			cout<<endl<<"Enter address of package: ";
			fflush(stdin);
			getline(cin,address);
			cout<<endl<<"City: ";
			fflush(stdin);
			getline(cin,city);
			cout<<endl<<"State: ";
			fflush(stdin);
			getline(cin,state);
			cout<<endl<<"Enter ZIP code of sender: ";
			cin>>ZIP_send;
			cout<<endl<<"Enter ZIP code of recipient: ";
			cin>>ZIP_rec;
			cout<<endl<<"Enter weight in ounces of package: ";
			cin>>weight;
			cout<<endl<<"Enter cost per ounce of package: ";
			cin>>cost_po;
			cout<<endl<<"Enter additional fee per ounce for overnight delivery: ";
			cin>>fee_po;
		}
		
		void display()
		{
			cout<<endl<<endl<<"--------------------------DETAILS--------------------------"<<endl<<endl;
			cout<<endl<<"Name: "<<name<<endl;
			cout<<endl<<"Address: "<<address<<endl;
			cout<<endl<<"City: "<<city<<endl;
			cout<<endl<<"State: "<<state<<endl;
			cout<<endl<<"Sender ZIP code: "<<ZIP_send<<endl;
			cout<<endl<<"Recipient ZIP code: "<<ZIP_rec<<endl;
			cout<<endl<<"Weight(ounces): "<<weight<<endl;
			cout<<endl<<"Cost per ounce: "<<cost_po<<endl;
			cout<<endl<<"Additional fee per ounce: "<<fee_po<<endl;
		}
};

int main()
{
	double flat_fee;
	cout<<endl<<"Enter flat fee for two day package: ";
	cin>>flat_fee;
	TwoDayPackage obj1(flat_fee);
	OvernightPackage obj2;
	
	obj1.input();
	obj2.input();
	
	obj1.display();
	cout<<endl<<"Total cost obj1: "<<obj1.calculateCost();
	obj2.display();
	cout<<endl<<"Total cost obj2: "<<obj2.calculateCost();
	
	return 0;
}
