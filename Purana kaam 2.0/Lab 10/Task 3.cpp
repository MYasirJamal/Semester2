# include <iostream>
using namespace std;
class person
{
        int ID;
        string name;

public:
        virtual void getdata()
        {
		    cout <<endl<< "Enter name of the employee: "<< endl;
		    cin >> name;
		    cout <<endl<< "Enter ID of the employee: "<< endl;
		    cin >> ID;
		}
        virtual void displayData()
		{
		    cout <<endl<<"Name  = " << name << endl << "Number =  "<<ID;
		}
		virtual void bonus()
		{
		    cout << endl <<" Bonus function of base class is called ";
		}
};


class admin : public virtual person
{
        int sale_admin;

public:
        void getdata()
		{
		    cout <<"\n Enter the Sale amount of the admin : "<< endl;
		    cin >> sale_admin;
		}
        void displayData()
		{
		    cout <<"\n Admin Employee sale amount  = "<< sale_admin;
		}
        void bonus()
		{
		    if (sale_admin >2000)
	        cout << "\n The bonus of the admin is : "<< (sale_admin*0.25);
		}

};

class account : public virtual person
{
        long int amt;

public :
        void getdata()
		{
	        cout <<"\n Enter the amount accumulated in the account : "<< endl;
	        cin >> amt;
		}
        void displayData()
		{
	        cout <<"\n Employee Account amount  = "<< amt;
		}
        void bonus()
		{
	        if (amt >10000)
	        cout << "\n The bonus of the admin is : "<< (amt*0.25);
		}

};

class master : public admin, public account

{
public:
        void getdata()
		{
	        cout <<endl<<"getdata of master class called:";
	        person::getdata();
	        admin:: getdata();
	        account::getdata();
		}
	    void displayData()
		{
	        cout <<endl<<"displayData of master class called:";
	        person::displayData();
	        admin:: displayData();
	        account::displayData();
		}
        void bonus()
		{
	        cout <<endl<<"Bonus of master class called:";
	        person::bonus();
	        admin:: bonus();
	        account::bonus();
		}

};

int main()
{
    person p, *per_ptr;
    admin a;
    account ac;
    master  ms;
    per_ptr=&p;
    per_ptr->getdata();
    per_ptr->displayData();
    per_ptr->bonus();
    per_ptr=&a;
    per_ptr->getdata();
    per_ptr->displayData();
    per_ptr->bonus();
    per_ptr=&ac;
    per_ptr->getdata();
    per_ptr->displayData();
    per_ptr->bonus();
    per_ptr=&ms;
    per_ptr->getdata();
    per_ptr->displayData();
    per_ptr->bonus();
    return 0;
}
