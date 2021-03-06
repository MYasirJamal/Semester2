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

class Sales{
	private:
		float sales[3];
	public:
		void getData()
		{
			int i;
			for(i=0;i<3;i++)
			{
				cout<<endl<<"Enter dollar sales for month "<<i+1<<": ";
				cin>>sales[i];
			}
		}
		
		void putData()
		{
			int i;
			for(i=0;i<3;i++)
			{
				cout<<endl<<"Enter dollar sales for month "<<i+1<<": "<<sales[i]<<endl;
			}
		}
};

class Book : protected Publication, protected Sales{
	private:
		int count;
	public:
		void getData()
		{
			Publication::getData();
			Sales::getData();
			cout<<endl<<"Enter number of pages: ";
			cin>>count;
		}
		
		void putData()
		{
			Publication::putData();
			Sales::putData();
			cout<<endl<<"Number of pages: "<<count<<endl;
		}
};

class Tape : protected Publication, protected Sales{
	private:
		float play_time;
	public:
		void getData()
		{
			Publication::getData();
			Sales::getData();
			cout<<endl<<"Enter playing time in minutes: ";
			cin>>play_time;
		}
		
		void putData()
		{
			Publication::putData();
			Sales::putData();
			cout<<endl<<"Playing time in minutes: "<<play_time<<endl;
		}
};

class Disks : protected Publication{
	private:
		string type;
	public:
		void getData()
		{
			bool c;
			Publication::getData();
			cout<<endl<<"Select type of disk (0.CD 1.DVD): ";
			cin>>c;
			if(c==0)
			{
				type="CD";
			}
			else if(c==1)
			{
				type="DVD";
			}
		}
		
		void putData()
		{
			Publication::putData();
			cout<<endl<<"Type of disk: "<<type<<endl;
		}
};

int main()
{
	Disks obj3;
	
	obj3.getData();
	
	obj3.putData();
	
	return 1;
}
