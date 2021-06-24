#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string mov_name;
	int adlt_tick,child_tick,n_tick;
	float adlt_prc,child_prc,gross_amt,don_prcnt,don_amt,net_sale;
	cout<<"Enter movie name: ";
	cin>>mov_name;
	cout<<"Enter adult ticket price: ";
	cin>>adlt_prc;
	cout<<"Enter child ticket price: ";
	cin>>child_prc;
	cout<<"Enter number of adult tickets sold: ";
	cin>>adlt_tick;
	cout<<"Enter number of child tickets sold: ";
	cin>>child_tick;
	n_tick=adlt_tick+child_tick;
	gross_amt=(adlt_tick*adlt_prc)+(child_tick*child_prc);
	cout<<"Percentage of the gross amount to be donated to the charity: ";
	cin>>don_prcnt;
	don_amt=(don_prcnt/100)*gross_amt;
	net_sale=gross_amt-don_amt;
	

	
	cout<<endl<<endl<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	
	cout<<"Movie Name: .......................  "<<mov_name<<endl;
	
	cout<<"Number of Tickets Sold: ...........  "<<n_tick<<endl;
	
	cout<<"Gross Amount: .....................  $ "<<fixed<<setprecision(2)<<gross_amt<<endl;
	
	cout<<"Percentage of Gross Amount Donated:  "<<fixed<<setprecision(2)<<don_prcnt<<"%"<<endl;
	
	cout<<"Amount Donated: ...................  $ "<<fixed<<setprecision(2)<<don_amt<<endl;
	
	cout<<"Net Sale: .........................  $ "<<fixed<<setprecision(2)<<net_sale<<endl;
	return 0;
}
