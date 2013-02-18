#include<stdio.h>
#include<climits>
#include<iostream>
#include<sstream>
#include<string.h>
#include<math.h>

using namespace std;

void get_inputs(double&,double&,int&);
double get_input(string);
double quadratic_solver(double&,double&,double&);
double three_vector(double&,double&,double&);

int main()
{
	double a,b,c,d;
	int error=1,quit=0;
	char operation;
	
	cout << "What operation do you wish to perform?\n\
'+' '-' '*' or '/'\n(Syntax is a.op.b=c)\nEnter 'q' to quit\n";
	
	// Check what operator has been entered
	while((error==1 && quit==0)||(error==0 && quit==0)){
		cin >> operation;
		if(operation == '+'){
			get_inputs(a,b,error);
			c=a+b;
			cout << "c = " << c << endl;
		} else if(operation == '*') {
			get_inputs(a,b,error);
			c=a*b;
			cout << "c = " << c << endl;
		} else if(operation == '/') {
			do{
				get_inputs(a,b,error);
			} while(b==0);
			c=a/b;
			cout << "c = " << c << endl;
		} else if(operation == '-') {
			get_inputs(a,b,error);
			c=a-b;
			cout << "c = " << c << endl;
		} else if(operation == '2'){
			d = three_vector(a,b,c);
			cout << "d = " << d << endl;
			error=0;
		} else if(operation == 'q') {
			quit=1;
		} else if(operation == '1') {
			d = quadratic_solver(a,b,c);
			cout << "d = " << d << endl;
			error=0;
		} else {
			// Error check on operator command
			cout << "Error 1\n";
			cin.clear();
			cin.ignore();
			error=1;
		}
	}
		
	return 0;
}

double three_vector(double &a,double &b,double &c)
{
	double ans;
	
	a = get_input("a");
	b = get_input("b");
	c = get_input("c");
	
	ans = sqrt(a*a+b*b+c*c);
	
	return ans;
}	

double quadratic_solver(double&a,double&b,double&c)
{
	double ans;
	
	a = get_input("a");
	b = get_input("b");
	c = get_input("c");
	
	ans = (-b+sqrt(b*b-4*a*c))/(2*a);
	
	return ans;
}

double get_input(string id)
{
	int error;
	double input;
	string name=id;
	
	do{
		cout << name << " = ";
		if(!(cin >> input)){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			error=1;
		} else {
			error=0;
		}		
	}while(error==1);
	
	return input;
}

void get_inputs(double&a,double&b,int&error)
{
	error=1;
	//Perform error check on variable inputs
	// clear will clear the memory while ignore clears the buffer?
	while(error==1){
		cout << "a = ";
		if(!(cin >> a)){
			cin.clear();
			cin.ignore();
			error=1;
		} else {
			error=0;
			cout << "b = ";
		}
		if(error==1 || !(cin >> b)){
			cin.clear();
			cin.ignore();
			error=1;
		} else {
			error=0;
		}
	}
	error=0;
	
	return;
}
