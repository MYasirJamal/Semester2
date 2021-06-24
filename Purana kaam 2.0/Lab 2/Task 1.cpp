#include<iostream>
#include<cmath>
using namespace std;

float residential(int num_premium);
float business(int num_premium, int num_connect);
int main()
{
	float bill;
	int acc_num,cus_code,no_prem,no_conn;
	char type;
	
	cout<<endl<<"Enter account number: ";
	cin>>acc_num;
	
	cout<<endl<<"Enter customer code: ";
	cin>>cus_code;
	
	cout<<"R - Resident"<<endl<<"B - Business"<<endl;
	cout<<endl<<endl<<"Enter type of connection (R/B): ";
	cin>>type;
	
	cout<<endl<<"Enter number of premium channels: ";
	cin>>no_prem;
	
	if(type=='B'||type=='b')
	{
		cout<<endl<<"Enter number of basic service connections: ";
		cin>>no_conn;
	}
	
	if(type=='B'||type=='b')
	{
		bill = business(no_prem,no_conn);
	}
	else if(type=='R'||type=='r')
	{
		bill = residential(no_prem);
	}
	else
	{
		cout<<endl<<"Invalid type entered";
	}
	
	cout<<endl<<endl<<endl<<"Account number: "<<acc_num<<endl;
	cout<<endl<<"Total amount: $"<<bill;
	return 1;
}
float residential(int num_premium)
{
	float bill=0,prcs_fee=4.50,bas_srvc=20.50,premium=7.50;
	bill += prcs_fee + bas_srvc + (num_premium * premium);
	return bill;
}
float business(int num_premium, int num_connect)
{
	float bill=0,prcs_fee=15.00,bas_srvc=75.00,premium=50.00;
	bill += prcs_fee + (num_premium * premium);
	if(num_connect<=10)
	{
		bill += num_connect * bas_srvc;
	}
	else
	{
		bill += 750 + 5 * (num_connect - 10);
	}
	return bill;
}
