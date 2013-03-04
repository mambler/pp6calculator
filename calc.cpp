//Libraries in system directory
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

//Custom built header files in local directory
#include "math.hpp"
#include "physics.hpp"

//Only using a selection of the entire "namespace std"
using std::cout;
using std::endl;
using std::cin;

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
\n5: Invariant mass calculation\n6: Input user defined array and bubble sort\n\
7: Lorentz Boost\nq: Quit Calculator" << endl << endl;
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
		} else if(operation == '7') {
			lorentz();
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
