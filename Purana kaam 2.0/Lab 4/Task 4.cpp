#include<iostream>

using namespace std;

class Books{
	public:
		string author,title,publisher;
		float price;
		int pos;
		Books(string a, string t, string p, float prc, int po)
		{
			author=a;
			title=t;
			publisher=p;
			price=prc;
			pos=po;
		}
		int searchBook(string bn, string an)
		{
			if(title==bn)
			{
				if(author==an)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		float amount(int s)
		{
			if(s<=pos)
			{
				pos-=s;
				return price*s;
			}
			else
			{
				cout<<endl<<"Required copies not in stock"<<endl;
			}
		}
		
};

int main()
{
	Books b[5]={Books("auth1","book1","publish1",10.5,3), Books("auth2","book2","publish2",10.5,3), Books("auth3","book3","publish3",10.5,3), Books("auth4","book4","publish4",10.5,0), Books("auth5","book5","publish5",10.5,3)};
	string aname,bname;
	int i,n;
	
	cout<<endl<<"Enter book name to find: ";
	cin>>bname;
	cout<<endl<<"Enter author name to find: ";
	cin>>aname;
	
	for(i=0;i<5;i++)
	{
		if(b[i].searchBook(bname,aname))
		{
			cout<<endl<<"Book found"<<endl;
			cout<<endl<<"Enter number of copies needed: ";
			cin>>n;
			cout<<endl<<"Total amount: "<<b[i].amount(n);
			break;
		}
		else
		{
			cout<<endl<<"Book not found"<<endl;
		}
	}
	
	return 1;
}
