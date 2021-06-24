#include<iostream>

using namespace std;

class MenuItem{
	public:
		string name,type;
		float price;
		void setRecords(string n, string t, float p)
		{
			name=n;
			type=t;
			price=p;
		}
};

class CoffeeShop{
	public:
		string name;
		MenuItem items[4];
		string orders[4];
		string food[4],drinks[4];
	
		CoffeeShop()
		{
			
		}
		CoffeeShop(string sn, string in1, string t1, float p1, string in2, string t2, float p2, string in3, string t3, float p3, string in4, string t4, float p4)
		{
			name=sn;
			items[0].setRecords(in1, t1, p1);
			items[1].setRecords(in2, t2, p2);
			items[2].setRecords(in3, t3, p3);
			items[3].setRecords(in4, t4, p4);
		}	
	
		int i,j;
		void addOrder(string o)
		{
			int found=0;
			for(i=0;i<4;i++)
			{
				if(items[i].name==o)
				{
					found=1;
					break;
				}
			}
			if(found)
			{
				for(i=0;i<4;i++)
				{
					if(orders[i]=="")
					{
						orders[i]=o;
						break;
					}
				}
			}
			else
			{
				cout<<endl<<"This item is currently unavailable!"<<endl;
			}
		}
		void fulfillOrder()
		{
			for(i=0;i<4;i++)
			{
				if(orders[i]!="")
				{
					cout<<endl<<"The "<<orders[i]<<" is ready"<<endl;
				}
			}
			if(i==4)
			{
				cout<<endl<<"All orders have been fulfilled!"<<endl;
			}
		}
		string* listOrders()
		{
			return &orders[0];
		}
		float dueAmount()
		{
			float amount=0;
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(orders[i]==items[j].name)
					{
						amount+=items[j].price;
						break;
					}
				}
			}
			return amount;
		}
		string cheapestItem()
		{
			float cheap=items[0].price;
			for(i=0;i<4;i++)
			{
				if(items[i].price<cheap)
				{
					cheap=items[i].price;
				}
			}
			for(i=0;i<4;i++)
			{
				if(items[i].price==cheap)
				{
					return items[i].name;
				}
			}
		}
		string* drinksOnly()
		{
			for(i=0;i<4;i++)
			{
				if(items[i].type=="Drink")
				{
					for(j=0;j<4;j++)
					{
						if(drinks[j]=="")
						{
							drinks[j]=items[i].name;
							break;
						}
					}
				}
			}
			return drinks;
		}
		string* foodOnly()
		{
			for(i=0;i<4;i++)
			{
				if(items[i].type=="Food")
				{
					for(j=0;j<4;j++)
					{
						if(food[j]=="")
						{
							food[j]=items[i].name;
							break;
						}
					}
				}
			}
			return food;
		}
		
		
};

int main()
{
	CoffeeShop obj("Coffe Shp","Food Item1","Food",50,"Drink Item1","Drink",10,"Food Item2","Food",500,"Drink Item2","Drink",100);
	
	string *ptr,*fptr,*dptr;
	int i;
	
	obj.addOrder("Food Item1");
	obj.addOrder("Drink Item2");
	
	obj.fulfillOrder();
	
	ptr=obj.listOrders();
	
	cout<<endl<<"Orders list: "<<endl;
	
	for(i=0;i<4;i++)
	{
		if(ptr[i]!="")
		cout<<endl<<ptr[i]<<endl;
	}
	
	cout<<endl<<"Amount due: "<<obj.dueAmount()<<endl;
	
	cout<<endl<<"Cheapest item: "<<obj.cheapestItem()<<endl;
	
	fptr=obj.foodOnly();
	dptr=obj.drinksOnly();
	
	cout<<endl<<"Food Only:"<<endl;
	for(i=0;i<4;i++)
	{
		if(fptr[i]!="")
		cout<<endl<<fptr[i]<<endl;
	}
	
	cout<<endl<<"Drinks Only:"<<endl;
	for(i=0;i<4;i++)
	{
		if(dptr[i]!="")
		cout<<endl<<dptr[i]<<endl;
	}
	
	return 1;
}
