#include<iostream>

using namespace std;

class Invoice{
	string numb,descrp;
	int qty;
	double prc,invoice;
	public:
		Invoice()
		{
			
		}
		Invoice(string n, string des, int q, double p)
		{
			numb=n;
			descrp=des;
			if(q<0)
			{
				q=0;
			}
			if(prc<0)
			{
				prc=0;
			}
			qty=q;
			prc=p;
		}
		double getInvoiceAmount()
		{
			invoice=qty*prc;
			return invoice;
		}
};

int main()
{
	Invoice obj("A1","book ",5,3.25);
	cout<<"Invoice amount: "<<obj.getInvoiceAmount();
	
	return 1;
}
