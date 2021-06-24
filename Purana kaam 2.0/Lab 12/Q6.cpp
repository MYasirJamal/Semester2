#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream Read("Story.txt");
	
	char c;
	int no=0;
	Read.get(c);
	if(c!='A')
	{
		no++;
	}
	while(!Read.eof())
	{
		if(c=='\n')
		{
			Read.get(c);
			if(c!='A')
			{
				no++;
			}
		}
		Read.get(c);
	}
	
	cout<<endl<<"Number of lines not starting with 'A' are: "<<no;
	
	return 0;
}
