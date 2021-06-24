#include<iostream>

using namespace std;

class Account{
	float balance;
	public:
		Account()
		{
			balance=0;
		}
		void Credit(float c)
		{
			balance+=c;
		}
		void Debit(float d)
		{
			balance-=d;
		}
		float Balance()
		{
			return balance;
		}
};

int main()
{
	Account obj;
	
	obj.Credit(100);
	cout<<endl<<"Balance after crediting 100: "<<obj.Balance()<<endl;
	
	obj.Debit(55);
	cout<<endl<<"Balance after debiting 55: "<<obj.Balance()<<endl;
	
	
	return 1;
}
