#include <iostream>
#include <fstream>
using namespace std;

class Person{
	public:
		int age;
		string name;
		Person()
		{
		}
		Person(int a, string n)
		{
			age=a;
			name=n;
		}
};

int main()
{
	Person person1(18,"Yasir"),person2;
	ofstream Write("person.bin");
	Write.write((char*)(&person1),sizeof(person1));
	Write.close();
	
	ifstream Read("person.bin",ios::binary);
	Read.read((char*)(&person2),sizeof(person2));
	cout<<person2.age<<endl<<person2.name;
	Read.close();
	return 0;
}
