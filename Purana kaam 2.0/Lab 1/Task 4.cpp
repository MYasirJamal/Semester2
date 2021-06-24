#include<iostream>
#include <iomanip>
using namespace std;
struct menuItemType{
	string menuItem;
	double menuPrice;
};
int main()
{
	struct menuItemType menuList[8];
	double amount=0,tax,bill;
	char another='Y';
	int i,item,sel[8],j=0,k=0;
	menuList[0].menuItem="Plain Egg";
	menuList[0].menuPrice=1.45;
	menuList[1].menuItem="Bacon and Egg";
	menuList[1].menuPrice=2.45;
	menuList[2].menuItem="Muffin";
	menuList[2].menuPrice=0.99;
	menuList[3].menuItem="French Toast";
	menuList[3].menuPrice=1.99;
	menuList[4].menuItem="Fruit Basket";
	menuList[4].menuPrice=2.49;
	menuList[5].menuItem="Cereal";
	menuList[5].menuPrice=0.69;
	menuList[6].menuItem="Coffee";
	menuList[6].menuPrice=0.50;
	menuList[7].menuItem="Tea";
	menuList[7].menuPrice=0.75;
	for(i=0;i<8;i++)
	{
		cout<<i+1<<". "<<menuList[i].menuItem<<"\t$"<<menuList[i].menuPrice<<endl;
	}
	while(another=='Y'||another=='y')
	{
		cout<<"\n\nSelect item number from menu: ";
		cin>>item;
		sel[j]=item;
		j++;
		amount+=menuList[item-1].menuPrice;
		cout<<"Do you want another item(Y/N): ";
		cin>>another;
	}
	tax=amount*0.05;
	bill=amount+tax;
	cout<<endl<<endl<<endl<<"Welcome to Johnny's Restaurant"<<endl;
	for(i=0;i<8;i++)
	{
		for(k=0;k<8;k++)
		{
			if(sel[i]==k+1)
			{
				cout<<menuList[k].menuItem<<" $"<<fixed<<setprecision(2)<<menuList[k].menuPrice<<endl;
			}
		}
	}
	cout<<"Tax $"<<fixed<<setprecision(2)<<tax<<endl;
	cout<<"Amount due $"<<fixed<<setprecision(2)<<bill<<endl;
	return 0;
}
