#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<iostream>
#include<sstream>
#include<string.h>
#include<math.h>
#include<omp.h>

//Use namespace std for convenience rather than scoping everything
using namespace std;

//Function Prototypes
double get_input(string);
void sort_function(int&,int&,int&);
void quadratic_solver(double&,double&,double&,double&,double&,int&);
void three_vector(double&,double&,double&);
void spacetime_vector(double&,double&,double&,double&);
void invariant_mass(double&,double&,double&,double&);
void line_intercept(double&,double&);
void multiplication(double&,double&);
void addition(double&,double&);
void subtraction(double&,double&);
void division(double&,double&);
void bubble();
//void test_function();

//Main routine
int main()
{
	double a,b,c,d;             //Commonly used variables passed to various different functions by reference for speed
	double real_part,imag_part; //Returned real part and imaginary part for complex roots and positive/negative roots in quadrativc solver
	int discrim; 				 //discriminant type in quadratic solver
	int quit=0;					 //Quit logic
	char operation;				 //Main menu input character
	
	// Check what operator has been entered while not quitting the program
	while(quit==0){
		cout << "Calculate: '+' '-' '*' '/'\n1: Quadratic Solver\n\
2: Length of Three Vector\n3: Straight Line x-axis intercept\n4: Spacetime length calcuation\
\n5: Invariant mass calculation\n6: Input user defined array and bubble sort\nq: Quit Calculator" << endl << endl;
		cin >> operation;
		if(operation == '+'){
			addition(a,b);
		} else if(operation == '*') {
			multiplication(a,b);
		} else if(operation == '/') {
			division(a,b);
		} else if(operation == '-') {
			subtraction(a,b);
		} else if(operation == '1') {
			quadratic_solver(a,b,c,real_part,imag_part,discrim);
			if(discrim==1){
				cout << "Positive root = " << real_part << endl;
				cout << "Negative root = " << imag_part << endl << endl;
			} else if(discrim==0){
				cout << "Repeated root = " << real_part << endl << endl;
			} else if(discrim==-1){
				cout << "Complex root = " << real_part << "+" << imag_part << "i" << endl;
				cout << "Complex root = " << real_part << "-" << imag_part << "i" << endl << endl;
			}
		} else if(operation == '2'){
			three_vector(a,b,c);
		} else if(operation == '3'){
			line_intercept(a,b);
		} else if(operation == '4'){
			spacetime_vector(a,b,c,d);
		} else if(operation == '5'){
			invariant_mass(a,b,c,d);
	/*	} else if(operation == '6'){
			//Take inputs before the function call to demonstrate
			a = get_input("a");
			b = get_input("b");
			sort_function(a,b);
			cout << "a = " << a << " and b = " << b << endl << endl;*/
		//} else if(operation == 'T'){
		//	test_function();
		} else if(operation == '6') {
			bubble();
		} else if(operation == 'q') {
			quit=1;
		} else {
			// Error check on operator command
			cout << "Error: Invalid input\n" << endl;
			cin.clear();
			cin.ignore();
		}
	}
		
	exit(EXIT_SUCCESS);
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
		if(b==0){
			cout << "Error: Cannot divide by zero!" << endl;
		}
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

// Calculate the length of the spacetime vector given the Minkowski signature (+,-,-,-)
void spacetime_vector(double&a,double&b,double&c,double&d)
{
	double dt,dr;
	
	cout << "Compute: ds^2 = (c*dt)^2 - dr^2" << endl;
	cout << "N.B: c=1" << endl << endl;
	
	//Take inputs
	a = get_input("dt");
	b = get_input("dx");
	c = get_input("dy");
	d = get_input("dz");
	
	dt = a*a;
	dr = b*b+c*c+d*d;
	
	//Calculate the length of the spacetime vector and output to screen
	cout << "ds^2 = " << dt-dr << endl;
	//Causality statement
	if(dt>dr){
		cout << "Time-like events" << endl << endl; 
	} else if(dt==dr){
		cout << "Light-like events" << endl << endl;
	} else if(dt<dr){
		cout << "Space-like events" << endl << endl;
	}
	
	return;
}

// Calculate the invariant mass
void invariant_mass(double&a,double&b,double&c,double&d)
{
	double m0;
	
	cout << "Compute: m0 = sqrt(E^2-(pc)^2)/c\nN.B: c=1" << endl << endl;
	
	//Do not allow the mass to be negative
	do{
		//Take inputs
		a = get_input("E");
		b = get_input("px");
		c = get_input("py");
		d = get_input("pz");
	
		//Coupute invariant mass squared
		m0 = a*a-b*b-c*c-d*d;
		
		if(m0<0){
			cout << "Error: Mass cannot be negative!" << endl << endl;
		}		
	//perform negative mass check
	}while(m0<0);
	
	//Compute invariant mass and output to screen
	cout << "m0 = " << sqrt(m0) << endl << endl;	
	
	return;
}

// Calculate the intercept of a straight line in 2D across the x-axis
void line_intercept(double &a, double &b)
{
	cout << "Compute: x(y) = (y-c)/m at y=0" << endl << endl;
	
	//Take inputs and do not allow a=0 otherwise will divide by zero
	do{
		a = get_input("m");
		if(a==0){
			cout << "Error: m cannot be zero!" << endl;
		}
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
	
	cout << "Compute: x = (-b (+/-) sqrt(b^2 - 4ac)) / 2a" << endl << endl;
		
	//do not allow a=0 otherwise will divide by zero
	do{
		a = get_input("a");
		if(a==0){
			cout << "Error: Cannot divide by zero!" << endl;
		}
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

//Function to bubble sort a user defined array
void bubble()
{
	int size,element_value,num_swaps,index,scans;
	cout << "How many integers do you wish to enter? ";
	size = int(get_input("size"));   // Cast returned input as int from double; user defined size of array
	cout << endl << endl;
	int *ptr_array = new int[size]; // Dynamically allocate the size of the array
	//check if memory allocation has failed
	if(ptr_array==NULL){ // OR using simple boolean logic "if(!prt_array)" means execute ptr_array==0
		cout << "Memory allocation has failed in bubble(). Terminating program." << endl << endl;
		exit(EXIT_FAILURE);  //Terminate program with fail code if memory cannot be allocated
	}
	
	cout << "Enter some values into the array. " << endl;	
	
	//Input values into array
	for(int i=0;i<size;++i){
		stringstream convert; // stringstream data type called "convert"
		convert << i;		  // throw i into the string stream "convert"
		element_value = get_input(convert.str());  //now call object "str()" from string stream on "convert" to convert
												   // the string stream to a string
		ptr_array[i]=element_value;				   // value of pointer "ptr_array" at address [i]; being assigned here
	}
	
	cout << "Original array arrangement: " << endl;
	for(int i=0;i<size;++i){
		cout << "ptr_array["<<i<<"] = " << ptr_array[i] << endl;
	}
	
	// Now sort the array using a bubble sort algorithm:
	// 1. Compare two elements of the array
	// 2. Flip the elements so the largest value is in the lower array index
	// 3. Move to next elements and repeat until end of array
	// 4. Keep going through the array until NO flips are made
	
	//perform the bubble sort
	scans=0;
	do{
		num_swaps=0;
		index=0;
		
		for(index=0;index<(size-1);++index){
			sort_function(ptr_array[index],ptr_array[index+1],num_swaps);
		}	
		++scans;
	}while(num_swaps!=0);
	
	cout << endl << "Sorted array arrangement: " << endl;
	for(int i=0;i<size;++i){
		cout << "ptr_array["<<i<<"] = " << ptr_array[i] << endl;
	}
	
	cout << "Scans = " << scans << endl << endl;
	
	//Always always ALWAYS, delete declared memory!!!
	delete [] ptr_array;
	
	return;
}

// Function to swap two integers only if they are out of order
void sort_function(int&a,int&b,int&num)
{
	//Temp variable
	double temp;
	
	//Check to see if "a" or "b" is bigger and decide whether to swap or not
	if(b>a){
		temp = a;
		a = b;
		b = temp;
		++num;
	}
	
	return;
}

/*void test_function()
{
	double a=2,b=8,i;
	
	double end_time;	
	double start_time=omp_get_wtime();
	
	for(i=0;i<1000000;i++){
		double temp;
		temp=a;
		a=b;
		b=temp;				
	}

	end_time=omp_get_wtime();
	cout << "For memory allocation: time = " << end_time-start_time << endl;
	
	start_time=omp_get_wtime();
	for(i=0;i<1000000;i++){
		a=a+b;
		b=a-b;
		a=a-b;
	}
	
	end_time=omp_get_wtime();
	cout << "For algebra solution: time = " << end_time-start_time << endl << endl;
	
	return;
}*/

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
			cout << "Error: NAN" << endl;
			error=true;
		} else {
			//...else the input is correct and the error tag is false
			error=false;
		}		
	}while(true==error); // Safe guard. Write logic statements backwards to avoid typoing "error=true" which
						  // would otherwise NOT cause the compiler to throw an error
	
	return input;
}
