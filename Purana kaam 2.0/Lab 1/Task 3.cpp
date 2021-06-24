#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	string name;
	int i;
	float n_array[5],sum=0,avg;
	cout<<"Enter Name:";
	cin>>name;
	cout<<"\nMarks:";
	for(i=0;i<5;i++)
	{
		cin>>n_array[i];
		sum+=n_array[i];
	}
	avg=sum/5;
	cout<<endl<<endl<<endl;
	cout<<"\n\nStudent name: "<<name<<endl;
	cout<<"Test scores: ";
	for(i=0;i<5;i++)
	{
		cout<<fixed<<setprecision(2)<<n_array[i]<<" ";
	}
	cout<<endl;
	cout<<"Average test score: "<<fixed<<setprecision(2)<<avg<<endl;
}
