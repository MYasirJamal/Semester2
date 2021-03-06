#include<iostream>
using namespace std;

class Movie{
	private:
		string name;
		string MPAArate;
		int rate1, rate2, rate3, rate4, rate5;
		float Average;
	public:
		
		Movie()
		{
			rate1=0;
			rate2=0;
			rate3=0;
			rate4=0;
			rate5=0;
			//All initialized to 0 as no one has rated them yet
		}
		
		Movie(string nam, string rat)
		{
			name=nam;
			MPAArate=rat;
			//name and MPAA rating initialization through parametrized constructor
			rate1=0;
			rate2=0;
			rate3=0;
			rate4=0;
			rate5=0;
			//All initialized to 0 as no one has rated them yet
		}
		//Setters for private variables
		void setName(string n)
		{
			name=n;
		}
		
		void setMPAA(string r)
		{
			MPAArate=r;
		}
		
		//no setter for Average as it depends on ratings being entered
		
		void addRating(int a)
		{
			switch(a)
			{
				case 1:
					rate1++;
					break;
				case 2:
					rate2++;
					break;
				case 3:
					rate3++;
					break;
				case 4:
					rate4++;
					break;
				case 5:
					rate5++;
					break;
				default:
					cout<<endl<<"Please enter rating between 1 and 5"<<endl;
					break;	
			}
			calculateAverage();		//Automatically updates Average everytime rating is added
		}
		
		void inputDetails()	//Allow user to enter Movie name and MPAA Rating
		{
			cout<<endl<<"Enter movie name: ";
			getline(cin,name);		//getline used to input string
			cout<<endl<<"MPAA Rating: ";
			fflush(stdin);
			getline(cin,MPAArate);
		}
		
		void inputRating()		//Take rating input from user
		{
			int in;
			char n='Y';
			while(n=='Y'||n=='y')	//When user iputs anything other than y, the program exits the loop
			{
				cout<<endl<<"Enter rating for "<<name<<": ";
				cin>>in;
				addRating(in);
				cout<<endl<<"Add another? (Y/N): ";
				cin>>n;
			}
			
		}
		
		void calculateAverage()		//calculates Average based on inputted ratings
		{
			Average=1.0*(rate1*1 + rate2*2 + rate3*3 + rate4*4 + rate5*5)/(rate1 + rate2 + rate3 + rate4 + rate5);
		}
		
		//Getters for private variables
		
		string getName()
		{
			return name;
		}
		
		string getMPAA()
		{
			return MPAArate;
		}
		
		float getAverage()
		{
			return Average;
		}

		printDetails()		//Outputs desired details without overcrowding main with cout/cin functions
		{
			cout<<endl<<endl<<endl<<"Details"<<endl<<"--------------------------------------------------------";
			cout<<endl<<"Name: "<<getName()<<endl;
			cout<<endl<<"MPAA Rating: "<<getMPAA()<<endl;
			cout<<endl<<"Average rating: "<<getAverage()<<endl;
		}
};

int main()
{
	Movie obj1;
	Movie obj2("Movie 2","PG");
	
	obj1.inputDetails();
	
	obj1.inputRating();
	
	obj2.inputRating();
	
	obj1.printDetails();
	
	obj2.printDetails();
	
	return 1;
}
