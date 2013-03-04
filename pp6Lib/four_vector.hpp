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
	
	//Unary operators must be done in the header files as they require access to their own members
	//Operator overloading. Increment and assignment.
	four_vector& operator+=(const four_vector& rhs)
	{
		// The "rhs" is the right hand side instance of the class "four_vector"
		// in the equation lhs += rhs. In the example, "lhs" is the left hand side
		// of the equations below and it is "this" instance of the class "four_vector"
		// which is being incremented by the rhs instance's respective members.
		ct += rhs.ct;
		x += rhs.x;
		y += rhs.y;
		z += rhs.z; 
		return *this;
	}
	
	//assignment
	four_vector& operator=(const four_vector& rhs)
	{
		ct = rhs.ct;
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}	
	
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
