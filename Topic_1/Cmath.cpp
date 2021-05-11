#include "Cmath.h"
#include <math.h>


Cmath::Cmath()		//constructor
{
}


Cmath::~Cmath()		//destructor
{
}


void Cmath::add(double a, double b)			//method for addition
{
	result = a + b;
}


void Cmath::sub(double a, double b)			//method for subtraction
{
	result = a - b;
}


void Cmath::mul(double a, double b)			//method for multiplication
{
	result = a * b;
}


bool Cmath::dev(double a, double b)			//method for division
{
	if (b == 0.0){
		return 0;
	}
	else{
		result = a / b;
	}
	return 1;
}

double Cmath::getResult()			//method returning the result
{
	return result;
}


int Cmath::func(double a, double b, double c, double*x1, double*x2)			//Method of calculating the roots of the quadratic equation
{
	if (a == 0.0) return -1;		//If a is 0, it is not quadratic function

	if (a != 0 && b == 0 && c == 0) {		//Quadratic function is moved along X-axis, the solution is 0
		*x1 = *x2 = 0;
		return 1;
	}
	double delta;
	delta = (b*b) - (4.0 * a*c);

	if (delta > 0.0) {			//The discriminant of a square trinomial is greater than 0. 2 solutions
		*x1 = (-b - sqrt(delta)) / (2.0 * a);
		*x2 = (-b + sqrt(delta)) / (2.0 * a);
		if (*x1 == 0) *x1 = 0;
		if (*x2 == 0) *x2 = 0;
		return 2;
	}else if(delta < 0.0) {			//The discriminant of a square trinomial is less than 0. Solutions are complex
		return 0;

	}else if (delta == 0.0) {			//The discriminant of a square trinomial is equal to 0. 1 solutions
		*x1 = *x2 = (-b) / (2.0 * a);
		if (*x1 == *x2 == 0.0) *x1 = *x2 = 0;
		return 1;
	}
	return -1;
}