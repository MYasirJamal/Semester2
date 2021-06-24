#include <iostream>
#include <fstream>
using namespace std;

class Participant{
	public:
		string name;
		int ID,score;
		void Input()
		{
			ofstream Write("participant.dat");
			cout<<"Enter name: ";
			cin>>name;
			cout<<"Enter ID: ";
			cin>>ID;
			cout<<"Enter score: ";
			cin>>score;
			Write.write((char*)(this),sizeof(Participant));
			Write.close();
		}
		
		void Output()
		{
			ifstream Read("participant.dat");
			Participant obj;
			int id;
			bool found = 0;
			cout<<endl<<"Enter ID of participant to find: ";
			cin>>id;
			while(!found)
			{
				Read.read((char*)(&obj),sizeof(Participant));
				if(obj.ID==id)
				{
					found=1;
					cout<<"Information:\n-----------------------------------\n"<<obj.ID<<"\t"<<obj.name<<"\t"<<obj.score;
				}
			}
			Read.close();
		}
		
		void Max()
		{
			int max=0;
			ifstream Read("participant.dat");
			Participant obj;
			bool found = 0;
			while(!Read.eof())
			{
				Read.read((char*)(&obj),sizeof(Participant));
				if(obj.score>max)
				{
					max=obj.score;
				}
			}
			cout<<endl<<"Maximum score: "<<max;
			Read.close();
		}
};

int main()
{
	Participant obj;
	obj.Input();
	obj.Input();
	obj.Output();
	obj.Max();
	
	return 0;
}
