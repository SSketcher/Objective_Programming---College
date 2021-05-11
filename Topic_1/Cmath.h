#pragma once
class Cmath
{
public:
	Cmath();
	~Cmath();

	void add(double a, double b);		//Method performing an addition that passes the result to the variable result

	void sub(double a, double b);		//Method performing a subtraction that passes the result to the variable result

	void mul(double a, double b);		//Method performing a multiplication that passes the result to the variable result

	bool dev(double a, double b);		//Method performing a division that passes the result to the variable result
										//Method returns bool in case of division by 0 False, in case of correct division, True

	int func(double a, double b, double c, double*x1, double*x2);		///Method of calculating the roots of the quadratic equation
																		///Method returns number of solutions
																		//Return of -1 means Error

	double getResult();					//Returning the result of the last operation performed, of the type double 
	
private:
	double result = 0;
};
 
