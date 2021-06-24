#include<iostream>
using namespace std;
class Batsman{
	int ID;
	string name;
	int age;
	int runs;
	float avg;
	int innings;
	public:
		void set_batsman(int m, string a, int b)
		{
			ID = m;
			name = a;
			age = b;
			runs=0;
			avg=0;
			innings=0;
		}
		void set_records(int run, int inn)
		{
			runs=run;
			innings=inn;
			avg=(runs*1.0)/innings;
		}
		string get_name(){return name;
		}
		float get_avg(){return avg;
		}
		int get_runs(){return runs;
		}
		int get_matc(){return innings;
		}
};

int main()
{
	Batsman b[2];
	float av[2],high_av=0;
	int i,run[2],mat[2],high_run=0,high_mat=0;
	b[0].set_batsman(1,"name1",17);
	b[0].set_records(198,10);
	b[1].set_batsman(2,"name2",18);
	b[1].set_records(1,100);
	for(i=0;i<2;i++)
	{
		av[i]=b[i].get_avg();
		if(av[i]>high_av)
		{
			high_av=av[i];
		}
		run[i]=b[i].get_runs();
		if(run[i]>high_run)
		{
			high_run=run[i];
		}
		mat[i]=b[i].get_matc();
		if(mat[i]>high_mat)
		{
			high_mat=mat[i];
		}
	}
	for(i=0;i<2;i++)
	{
		if(run[i]==high_run)
		{
			cout<<endl<<"Player with highest runs: "<<b[i].get_name()<<endl;
		}
		if(av[i]==high_av)
		{
			cout<<endl<<"Player with highest average runs: "<<b[i].get_name()<<endl;
		}
		if(mat[i]==high_mat)
		{
			cout<<endl<<"Player who played most matches: "<<b[i].get_name()<<endl;
		}
	}
	return 1;
}
