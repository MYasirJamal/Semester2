#include<iostream>
using namespace std;

int showChoices();

int metersAndCentTofeetAndInches(int meters, int centi, int &feet, int &inches);

int feetAndInchesToMetersAndCent(int feet, int inches, int &meters, int &centi);

int main()
{
	int choice,in1,in2,out1,out2;
	do
	{
		choice=showChoices();
		if(choice==1)
		{
			cout<<endl<<"Enter number of feet: ";
			cin>>in1;
			
			cout<<endl<<"Enter number of inches: ";
			cin>>in2;
			
			feetAndInchesToMetersAndCent(in1,in2,out1,out2);
			
			cout<<endl<<endl<<"Result"<<endl<<endl<<"Meters: "<<out1<<endl;
			cout<<"Centimeters: "<<out2<<endl<<endl<<endl;
		}
		else if(choice==2)
		{
			cout<<endl<<"Enter number of meters: ";
			cin>>in1;
			
			cout<<endl<<"Enter number of centimeters: ";
			cin>>in2;
			
			metersAndCentTofeetAndInches(in1,in2,out1,out2);
			
			cout<<endl<<endl<<"Result"<<endl<<endl<<"Feet: "<<out1<<endl;
			cout<<"Inches: "<<out2<<endl<<endl<<endl;
		}
	}while(choice!=3);
	
	
	return 1;
}

int showChoices()
{
	int choice;
	cout<<endl<<"1. Convert feet and inches to meters and centimeters";
	cout<<endl<<"2. Convert meters and centimeters to feet and inches";
	cout<<endl<<"3. Exit"<<endl;
	cout<<endl<<"Select option: ";
	cin>>choice;
	
	return choice;
}

int metersAndCentTofeetAndInches(int meters, int centi, int &feet, int &inches)
{
	centi+=meters*100;
	inches=centi/2.54;
	feet=inches/12;
	inches-=feet*12;
	return 1;
}

int feetAndInchesToMetersAndCent(int feet, int inches, int &meters, int &centi)
{
	inches+=feet*12;
	centi=inches*2.54;
	meters=centi/100;
	centi-=meters*100;
	return 1;
}
