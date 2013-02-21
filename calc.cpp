#include<stdio.h>
#include<climits>
#include<iostream>
#include<sstream>
#include<string.h>
#include<math.h>

using namespace std;

double get_input(string);
void quadratic_solver(double&,double&,double&,double&,double&,int&);
void three_vector(double&,double&,double&);
void line_intercept(double&,double&);
void multiplication(double&,double&);
void addition(double&,double&);
void subtraction(double&,double&);
void division(double&,double&);

int main()
{
	double a,b,c,d;
	double real_part,imag_part;
	int discrim; 				//discriminant value
	int quit=0;
	char operation;
	
	// Check what operator has been entered
	while(quit==0){
		cout << "Calculate: '+' '-' '*' '/'\n1: Quadratic Solver\n\
2: Length of Three Vector\n3: Straight Line x-axis intercept" << endl << endl;
		cin >> operation;
		if(operation == '+'){
			addition(a,b);
		} else if(operation == '*') {
			multiplication(a,b);
		} else if(operation == '/') {
			division(a,b);
		} else if(operation == '-') {
			subtraction(a,b);
		} else if(operation == '2'){
			three_vector(a,b,c);
		} else if(operation == '3'){
			line_intercept(a,b);
		} else if(operation == 'q') {
			quit=1;
		} else if(operation == '1') {
			quadratic_solver(a,b,c,real_part,imag_part,discrim);
			if(discrim==1){
				cout << "Positive root = " << real_part << endl;
				cout << "Negative root = " << imag_part << endl;
			} else if(discrim==0){
				cout << "Repeated root = " << real_part << endl;
			} else if(discrim==-1){
				cout << "Complex root = " << real_part << "+" << imag_part << "i" << endl;
				cout << "Complex root = " << real_part << "-" << imag_part << "i" << endl;
			}
		} else {
			// Error check on operator command
			cout << "Error 1\n";
			cin.clear();
			cin.ignore();
		}
	}
		
	return 0;
}

//Perform simple multiplication
void multiplication(double &a,double &b)
{
	cout << "Compute: a*b" << endl << endl;
		
	//Take inputs
	a = get_input("a");
	b = get_input("b");
	
	//Compute multiplication and output to screen
	cout << "a*b = " << a*b << endl << endl;
	
	return;
}

//Perform simple addition
void addition(double &a,double &b)
{
	cout << "Compute: a+b" << endl << endl;
	
	//Take inputs
	a = get_input("a");
	b = get_input("b");
	
	//Compute addition and output to screen
	cout << "a+b = " << a+b << endl << endl;
	
	return;
}

// Perform simple subtraction
void subtraction(double &a,double &b)
{
	cout << "Compute: a-b" << endl << endl;
	
	//Take inputs
	a = get_input("a");
	b = get_input("b");
	
	//Compute subtraction and output to screen
	cout << "a-b = " << a-b << endl << endl;
	
	return;
}

// Perform simple division
void division(double &a,double &b)
{
	cout << "Compute: a/b" << endl << endl;
	
	//Take inputs and ensure the denominator is not zero
	a =	get_input("a");
	do{
		b = get_input("b");
	}while(b==0);
	
	//Compute the division and output to screen
	cout << "a/b = " << a/b << endl << endl;
	
	return;	
}

// Calculate the length of a 3-Dimensional vector
void three_vector(double &a,double &b,double &c)
{
	cout << "Compute: l = sqrt(a^2 + b^2 + c^2)" << endl << endl;

	//Take inputs
	a = get_input("a");
	b = get_input("b");
	c = get_input("c");
	
	//Calculate length and output to screen
	cout << "l = " << sqrt(a*a+b*b+c*c) << endl << endl;
	
	return;
}	

// Calculate the intercept of a straight line in 2D across the x-axis
void line_intercept(double &a, double &b)
{
	cout << "Compute: x(y) = (y-c)/m at y=0" << endl << endl;
	
	//Take inputs and do not allow a=0 otherwise will divide by zero
	do{
		a = get_input("m");
	}while(a==0);
	b = get_input("c");
	
	//Calculate the intercept across x axis and output to screen
	cout << "x(0) = " << -b/a << endl << endl;
	
	return;
}

//Function to solve quadratic equations and pass the solutions back to main.
//Since there can be more than once solution, the part from the constant and
//the root are sent back to main seperately as "real_part" and "imag_part"
//respectively, in reference to complex conjugate solutions. Also pass back
//the value discrim to distinguish between the "real_part" and the "imag_part"
//being parts of real roots or complex roots.
void quadratic_solver(double&a,double&b,double&c,double&real_part,double&imag_part,int&discrim)
{
	double discriminant;
		
	//do not allow a=0 otherwise will divide by zero
	do{
		a = get_input("a");
	}while(a==0);
	b = get_input("b");
	c = get_input("c");
	
	//calculate discriminant to determine what roots will be passed back
	discriminant = b*b-4*a*c;
	
	//check discriminant
	// 2 real roots
	if(discriminant>0){
		discrim = 1;
		real_part=(-b+sqrt(discriminant))/(2*a);
		imag_part=(-b-sqrt(discriminant))/(2*a);
	// 1 repeated root
	} else if(discriminant==0){
		discrim = 0;
		real_part = -b/(2*a);
		imag_part = 0;
	// 2 complex conjugate roots
	} else if(discriminant<0){
		discrim = -1;
		real_part=-b/(2*a);
		imag_part=sqrt(-1*discriminant)/(2*a);
	}
		
	return ;
}

//Function to take in user inputs and perform error checks
double get_input(string id)
{
	bool error;
	double input;
	string name=id;  //Assign the name the passed string
	
	//do input and error check while error value is true
	do{
		cout << name << " = ";
		//If the input is not of type double...
		if(!(cin >> input)){
			//...then clear and empty the input buffer to the last new line
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			error=true;
		} else {
			//...else the input is correct and the error tag is negative
			error=false;
		}		
	}while(error==true);
	
	return input;
}
