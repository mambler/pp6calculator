// Pay attention, these "#" statements are pre-compiler macros.
// What this means is that these logic statements are used to build things
// into the compiler or control the way the compiler compiles the code.
// In this case below, "#ifndef" is a NOT if statement handled by the
// compiler. Similarly, "#endif" is the closing bracket of the if statement.
// The below macros check if compiler variable "MATHS_HEADER" exists. If
// it doesn't exist, then create it. Inside the if statement, do some stuff.
// Then close the if statement. This stops code inside the header file being
// defined multiple times.

#ifndef MATHS_HEADER
#define MATHS_HEADER

void sort_function(int&,int&,int&);
void quadratic_solver(double&,double&,double&,double&,double&,int&);
void three_vector(double&,double&,double&);
void line_intercept(double&,double&);
void multiplication(double&,double&);
void addition(double&,double&);
void subtraction(double&,double&);
void division(double&,double&);
void bubble();

#endif
