#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float w_kg,w_lb;
	cout <<"Enter weight in kg: ";
	cin>>w_kg;
	w_lb=w_kg*2.2;
	cout <<"Weight in pound is: "<<fixed<<setprecision(2)<<w_lb;
	return 0;
}
