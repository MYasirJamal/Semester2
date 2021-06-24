#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string String="string";
	
	ifstream Read("File1.txt");
	ofstream Write("File1.txt");
	
	Write<<String;
	Write.close();
	
	char c;
	
	while(!Read.eof())
	{
		cout<<c;
		Read.get(c);
	}
	Read.close();
	
	return 0;
}
