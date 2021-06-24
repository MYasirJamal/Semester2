#include <iostream>

using namespace std;

class Employee{
	protected:
		string name,code;
	public:
		Employee(string a, string b)
		{
			name=a;
			code=b;
		}
};

class Consultant : virtual public Employee{
	protected:
		int yearsOfExperience;
	public:
		Consultant(string a, string b, int c) : Employee(a,b)
		{
			yearsOfExperience=c;
		}
		
};

class Manager : virtual public Employee{
	protected:
		int noOfTeams;
	public:
		Manager(string a, string b, int c) : Employee(a,b)
		{
			noOfTeams=c;
		}
	
};

class ConsultantManager : public Consultant, public Manager{
	protected:
		
	public:
		ConsultantManager(string a, string b, int c, int d) : Consultant(a,b,c), Manager(a,b,d), Employee(a,b)
		{
		}
		
		void display()
		{
			cout<<endl<<name<<endl<<code<<endl<<yearsOfExperience<<endl<<noOfTeams;
		}
};

int main()
{
	ConsultantManager obj("Ali","S-123",17,5);
	obj.display();
	return 0;
}
