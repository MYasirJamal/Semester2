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

class Book : protected Publication{
	private:
		int count;
	public:
		void getData()
		{
			Publication::getData();
			cout<<endl<<"Enter number of pages: ";
			cin>>count;
		}
		
		void putData()
		{
			Publication::putData();
			cout<<endl<<"Number of pages: "<<count<<endl;
		}
};

class Tape : protected Publication{
	private:
		float play_time;
	public:
		void getData()
		{
			Publication::getData();
			cout<<endl<<"Enter playing time in minutes: ";
			cin>>play_time;
		}
		
		void putData()
		{
			Publication::putData();
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
