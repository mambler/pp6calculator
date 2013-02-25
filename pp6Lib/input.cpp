#include <iostream>
#include <stdio.h>
#include <climits>

#include "input.hpp"

//Only using a selection of the entire "namespace std"
using std::cout;
using std::endl;
using std::string;
using std::cin;

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
