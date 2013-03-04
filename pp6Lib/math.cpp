#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>

#include "math.hpp"
#include "input.hpp"

//Only using a selection of the entire "namespace std"
using std::cout;
using std::endl;
using std::stringstream;

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
	
	cout << "Enter some values into the array. " << endl << endl;	
	
	//Input values into array
	for(int i=0;i<size;++i){
		stringstream convert; // stringstream data type called "convert"
		convert << i;		  // throw i into the string stream "convert"
		element_value = get_input(convert.str());  //now call object "str()" from string stream on "convert" to convert
												   // the string stream to a string
		ptr_array[i]=int(element_value);		   // value of pointer "ptr_array" at address [i]; being assigned here
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
