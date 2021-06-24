#include<iostream>

using namespace std;

class Publication{
	private:
		string title;
		float price;
	public:
		void getData()
		{
			cout<<endl<<endl<<"---------------Enter details---------------"<<endl<<endl;
			cout<<endl<<"Enter title: ";
			fflush(stdin);
			getline(cin,title);
			cout<<endl<<"Enter price: ";
			cin>>price;
		}
		
		void putData()
		{
			cout<<endl<<endl<<"---------------DETAILS---------------"<<endl<<endl;
			cout<<endl<<"Title: "<<title<<endl;
			cout<<endl<<"Price: "<<price<<endl;
		}
};

class Publication2 : protected Publication{
	private:
		int day,month,year;
	public:
		void getData()
		{
			Publication::getData();
			cout<<endl<<"Enter date of publication: "<<endl<<"Day: ";
			cin>>day;
			cout<<endl<<"Month: ";
			cin>>month;
			cout<<endl<<"Year: ";
			cin>>year;
		}
		
		void putData()
		{
			Publication::putData();
			cout<<endl<<"Date of publication: "<<day<<"/"<<month<<"/"<<year;
		}
};

class Book : protected Publication2{
	private:
		int count;
	public:
		void getData()
		{
			Publication2::getData();
			cout<<endl<<"Enter number of pages: ";
			cin>>count;
		}
		
		void putData()
		{
			Publication2::putData();
			cout<<endl<<"Number of pages: "<<count<<endl;
		}
};

class Tape : protected Publication2{
	private:
		float play_time;
	public:
		void getData()
		{
			Publication2::getData();
			cout<<endl<<"Enter playing time in minutes: ";
			cin>>play_time;
		}
		
		void putData()
		{
			Publication2::putData();
			cout<<endl<<"Playing time in minutes: "<<play_time<<endl;
		}
};

int main()
{
	Book obj1;
	Tape obj2;
	
	obj1.getData();
	obj2.getData();
	
	obj1.putData();
	obj2.putData();
	
	return 1;
}
