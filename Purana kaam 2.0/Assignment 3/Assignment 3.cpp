#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

using namespace std;

class Data{
	string data;
	public:
		void inputData()
		{
			cout<<endl<<"Enter data to encode: ";
			getline(cin,data);
			
			ofstream Write("input.txt");
			Write<<data;
			Write.close();
		}
		
		void encodeData()
		{
			ifstream Read("input.txt");
			ofstream Write("K20-0158.txt");
			
			if(Read.is_open())
			{
				int i,j,num=0;
				char c;
				bool end=0;
				vector<int> Encrypted;
				vector<int> number;
				while(!Read.eof())
				{
					if(c>=48&&c<=57)		//check whether character read is a number or not
					{
						num=0;
						end=0;
						while(1)		//loop used to ensure complete number is read
						{
							if(c>=48&&c<=57&&!Read.eof())
							{
								cout<<".";
								number.push_back(c-48);		//storing units, tens, hundredths of number separately in a single array
							}
							else
							{
								end=1;
								break;
							}
							Read.get(c);
						}
						if(end)
						{
							j=number.size();
							for(i=0;i<number.size();i++)
							{
								j--;
								num += number[i]*pow(10,j);		//converting units, tens etc back to original number
							}
							number.clear();
						}
						
						Encrypted.push_back(num);		//store number in an array to encode later
					}
					Read.get(c);
				}
				
				for(i=0;i<Encrypted.size();i++)
				{
					if(Encrypted[i]>=1&&Encrypted[i]<=26)
					{
						c=64+Encrypted[i];		//converting integer to capital letter
					}
					else
					{
						c='Z';		//if number is greater than 26 or less than 1
					}
					Write<<c;
				}
				
				Read.close();
				Write.close();
				
				cout<<endl<<endl<<"Data successfully encoded";
			}
			else
			{
				//if no input detected
				cout<<endl<<endl<<"input.txt file not found";
			}
		}
};


int main()
{
	Data object;
	
	object.inputData();
	
	object.encodeData();
}
