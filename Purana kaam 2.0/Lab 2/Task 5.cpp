#include<iostream>
using namespace std;

float calculateBill(float hourly_rate, int consul_time, char low_income);

int main()
{
	int time,corr=0;
	float hour_rate,bill;
	char is_low;
	
	cout<<endl<<"Enter hourly rate: ";
	cin>>hour_rate;
	
	cout<<endl<<"Enter total consulting time (minutes): ";
	cin>>time;
	
	do{
		cout<<endl<<"Does the person have low income? (Y/N): ";
		cin>>is_low;
		if(is_low=='Y' || is_low=='y' || is_low=='N' || is_low=='n')
		corr=1;
		else
		cout<<endl<<"Enter Y or N";
	}while(!corr);
	
	bill=calculateBill(hour_rate,time,is_low);
	
	cout<<endl<<endl<<"Billing amount: $"<<bill;
	
	return 1;
}

float calculateBill(float hourly_rate, int consul_time, char low_income)
{
	float bill,prcnt;
	
	if(low_income=='Y' || low_income=='y')
	{
		if(consul_time<=30)
		consul_time=0;
		else
		consul_time-=30;
		prcnt=0.4;
	}
	else if(low_income=='N' || low_income=='n')
	{
		if(consul_time<=20)
		consul_time=0;
		else
		consul_time-=20;
		prcnt=0.7;
	}
	
	bill = hourly_rate * prcnt * (consul_time/60.0);
	
	return bill;
}
