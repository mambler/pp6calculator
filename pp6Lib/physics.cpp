#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>

#include "physics.hpp"
#include "four_vector.hpp"
#include "input.hpp"

//Only using a selection of the entire "namespace std"
using std::cout;
using std::endl;

//-------------------------------------------------------------------------

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

//-------------------------------------------------------------------------

void lorentz()
{
	// Implement struct vector here.
	four_vector vector;
	// Set values
	vector.setVectorComponents();	
	
	double v;
	
	do{
		v = get_input("v");
	}while(v>=1 || v<0);
	
	cout << endl << "Original vector: " << "[" << vector.get_ct() << "," << vector.get_x() << "," << vector.get_y() << "," << vector.get_z() << "]" << endl;
	
	//Calculate the Lorentz boost
	vector.boost_z(v);
	
	cout << "Boosted vector: " << "[" << vector.get_ct() << "," << vector.get_x() << "," << vector.get_y() << "," << vector.get_z() << "]" << endl;
	cout << "Spacetime interval: " << vector.interval() << endl;
	
	return;
}
