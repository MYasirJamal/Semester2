#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream Read("File1.txt");
	ofstream Write("Copy.txt");
	char c;
	while(!Read.eof())
	{
		if(c!='\0')
		Write<<c;
		Read>>c;
	}
	Read.close();
	Write.close();
}
