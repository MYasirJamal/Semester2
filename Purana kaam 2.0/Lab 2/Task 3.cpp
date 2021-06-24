#include<iostream>
using namespace std;

float calculateRegular(int minutes);

float calculatePremium(int minutes_1, int minutes_2);

int main()
{
	int acc_no,corr=0,reg_min,prem_am_pm,prem_pm_am,no_min;
	float amount_due;
	char srvc_typ;
	
	cout<<endl<<"Enter account number: ";
	cin>>acc_no;
	
	do{
		cout<<endl<<endl<<"R - Regular"<<endl<<"P - Premium"<<endl<<endl<<"Enter type of service: ";
		cin>>srvc_typ;
		
		if(srvc_typ=='R' || srvc_typ=='r' || srvc_typ=='P' || srvc_typ=='p')
		corr=1;
		else
		cout<<"Error - Choose from the options above"<<endl;
	}while(!corr);
	
	if(srvc_typ=='R' || srvc_typ=='r')
	{
		cout<<"Enter number of minutes service was used: ";
		cin>>reg_min;
		
		no_min=reg_min;
		
		amount_due=calculateRegular(reg_min);
	}
	else if(srvc_typ=='P' || srvc_typ=='p')
	{
		cout<<endl<<"Enter number of minutes the service was used during the day: ";
		cin>>prem_am_pm;
		
		cout<<endl<<"Enter number of minutes the service was used during the night: ";
		cin>>prem_pm_am;
		
		no_min=prem_am_pm+prem_pm_am;
		
		amount_due = calculatePremium(prem_am_pm,prem_pm_am);
	}
	
	cout<<endl<<"----------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<"Account number: "<<acc_no<<endl;
	
	cout<<endl<<"Type of service: ";
	if(srvc_typ=='R' || srvc_typ=='r')
	cout<<"Regular"<<endl;
	else
	cout<<"Premium"<<endl;
	
	cout<<endl<<"Number of minutes the telephone service was used: "<<no_min<<endl;
	
	cout<<endl<<"Amount due: "<<amount_due<<endl;
	
	
	return 1;
}

float calculateRegular(int minutes)
{
	float total=0;
	
	total = 10;
	
	if(minutes>50)
	{
		total += 0.2 * (minutes - 50);
	}
	
	return total;
}

float calculatePremium(int minutes_1, int minutes_2)
{
	float total=0;
	
	total += 25;
	
	if(minutes_1>75)
	{
		total += 0.1 * (minutes_1 - 75);
	}
	
	if(minutes_2>100)
	{
		total += 0.05 * (minutes_2 - 100);
	}
	
	return total;
}
