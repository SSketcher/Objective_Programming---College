#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include "Lista.h"

using namespace std;

int main()
{
	Lista points;
	for (double i = 0; i < 5; i++)
	{
		Point p =
		{
			3 * i,
			3 * i + 1,
			3* i + 2,
		};
		points.insert(p);
	}
	cout << "-------------------------------------------" << endl;
	Lista points3(points.scale(2));
	cout << points3 << endl;
	cout << "-------------------------------------------" << endl;
	Lista points2 = points * points3;
	cout << points2 << endl;
	cout << "-------------------------------------------" << endl;
	vector<Point> vec;
	for (double i = 0; i < 5; i++)
	{
		Point p =
		{
			2 * i,
			2 * i + 1,
			2 * i + 2,
		};
		vec.push_back(p);
	}
	Lista point4(vec);
	cout << point4;
	cout << "-------------------------------------------" << endl;
	Node* temp = points[3];
	cout << temp->p.a << ',' << temp->p.b << ',' << temp->p.c << endl;

	system("pause");
	return 0;
}