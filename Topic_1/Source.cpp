#include <iostream>
#include "Cmath.h"

using namespace  std;

int main()
{
	double x1, x2;
	int a;
	Cmath cal;
	cal.add(5, 4);
	cout << cal.getResult() << endl;
	cal.sub(5, 4);
	cout << cal.getResult() << endl;
	cal.mul(5, 4);
	cout << cal.getResult() << endl;
	if (cal.dev(5, 2)) {
		cout << cal.getResult() << endl;
	}
	else {
		cout << "Division by 0" << endl;
	}
	a = cal.func(-2, 0, 0, &x1, &x2);
	if (a == 2) {
		cout << "x1 =";
		cout <<  x1 << endl;
		cout << "x2 =";
		cout << x2 << endl;
	}
	if (a == 1) {
		cout << "x1 =";
		cout << x1 << endl;
	}
	if (a == 0) {
		cout << "No real roots" << endl;
	}
	if (a == -1) {
		cout << "Error" << endl;
	}
	system("pause");
	return 0;
}

