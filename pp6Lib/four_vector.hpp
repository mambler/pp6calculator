#ifndef FOUR_VECTOR
#define FOUR_VECTOR

// Declare a four-vector class
class four_vector{
public:
	void boost_z(double&);
	void setVectorComponents();
	double interval();
	double get_ct();
	double get_x();
	double get_y();
	double get_z();
	
private:
	double ct;
	double x;
	double y;
	double z;
	double ds;
	
public:
	//Constructor(s)
	four_vector();
	four_vector(double, double, double, double);
	//Destructor
	~four_vector();
	
};

#endif
