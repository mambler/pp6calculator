#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>

#include "physics.hpp"
#include "input.hpp"
#include "four_vector.hpp"

//Constructor intialliser(s).
four_vector::four_vector(){
	ct=0;
	x=0;
	y=0;
	z=0;
}

//Constructor using a line initialliser. This constructor is used when setting variables immediately.
four_vector::four_vector(double ct_, double x_, double y_, double z_) : ct(ct_), x(x_), y(y_), z(z_) {}

//Arbitary Destructor (Nothing to destruct at the moment)
four_vector::~four_vector(){
	std::cout << "Four vector has been deconstructed." << std::endl << std::endl;
}

//Set vector components
void four_vector::setVectorComponents(){	
	ct=get_input("ct");
	x=get_input("x");
	y=get_input("y");
	z=get_input("z");
	
	//Precompute the inteval (BECAUSE IT WON'T CHANGE ANYWAY!)
	ds=ct*ct-x*x-y*y-z*z;
	
	return;
}

//Retrive the vector components
double four_vector::get_ct() { return ct; }
double four_vector::get_x() { return x; }
double four_vector::get_y() { return y; }
double four_vector::get_z() { return z; }

// Boost function for four_vector class
void four_vector::boost_z(double &v){
	
	double gamma,temp;
	
	gamma = 1/sqrt(1-v*v);
	temp = z;	
	
	z = gamma*(z-v*ct);
	ct = gamma*(ct-v*temp);	
	
	return;
}

// Calculate spacetime interval and return this value
double four_vector::interval(){
	
	return ds;
}
