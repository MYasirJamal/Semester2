#include<iostream>
using namespace std;
struct baseballplayer{
	string name;
	int n_hruns;
	int n_hits;
};
int main()
{
	int index,i;
	struct baseballplayer players[10];
	for(i=0;i<10;i++)
	{
		cout<<endl<<"Player name: ";
		cin>>players[i].name;
		cout<<endl<<"Number of home runs: ";
		cin>>players[i].n_hruns;
		cout<<endl<<"Number of hits: ";
		cin>>players[i].n_hits;
	}
	cout<<"\n\nEnter index you want to update: ";
	cin>>index;
	for(i=0;i<10;i++)
	{
		if(i==index)
		{
			cout<<endl<<"Update information\n\nPlayer name: ";
			cin>>players[i].name;
			cout<<endl<<"Number of home runs: ";
			cin>>players[i].n_hruns;
			cout<<endl<<"Number of hits: ";
			cin>>players[i].n_hits;
		}
	}
}
