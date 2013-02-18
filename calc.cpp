#include<stdio.h>
#include<iostream>
#include<math.h>

//int error_check(double);

using namespace std;

void get_inputs(double&,double&);

int main()
{
	double a,b,c;
	char operation;
	
	cout << "What operation do you wish to perform?\n\
	'+' '-' '*' or '/'\n(Syntax is a.op.b=c)\n";
	cin >> operation;
	
	// Check what operator has been entered
	if(operation == '+'){
		get_inputs(a,b);
		c=a+b;
	} else if(operation == '*') {
		get_inputs(a,b);
		c=a*b;
	} else if(operation == '/') {
		get_inputs(a,b);
		c=a/b;
	} else if(operation == '-') {
		get_inputs(a,b);
		c=a-b;
	}
	
	cout << "c = " << c << endl;
		
	return 0;
}

void get_inputs(double&a,double&b)
{
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	
	return;
}
/*
int error_check(double)
{
	if(!
}
*/
