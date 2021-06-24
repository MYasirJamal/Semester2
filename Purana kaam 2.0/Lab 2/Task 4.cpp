#include<iostream>
#include<cmath>
using namespace std;

float distance(int x1,int y1,int x2,int y2);

float radius(int x1,int y1,int x2,int y2);

float circumference(float r);

float area(float r);

int main()
{
	float rad,cir,a;
	int point_x,point_y,center_x,center_y;
	
	cout<<endl<<"Enter x-coordinate of point: ";
	cin>>point_x;
	cout<<endl<<"Enter y-coordinate of point: ";
	cin>>point_y;
	
	cout<<endl<<"Enter x-coordinate of center: ";
	cin>>center_x;
	cout<<endl<<"Enter y-coordinate of center: ";
	cin>>center_y;
	
	rad=radius(point_x,point_y,center_x,center_y);
	
	cir=circumference(rad);
	
	a=area(rad);
	
	cout<<endl<<"Radius: "<<rad<<endl;
	
	cout<<endl<<"Circumference: "<<cir<<endl;
	
	cout<<endl<<"Area: "<<a<<endl;
	
	return 1;
}

float distance(int x1,int y1,int x2,int y2)
{
	float dist;
	dist = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return dist;
}

float radius(int x1,int y1,int x2,int y2)
{
	float rad;
	rad = distance(x1,y1,x2,y2);
	return rad;
}

float circumference(float r)
{
	return 2*r;
}

float area(float r)
{
	return 3.1416*pow(r,2);
}

