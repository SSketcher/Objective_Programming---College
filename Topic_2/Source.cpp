#include <iostream>
#include <cstdint>
#include <windows.h>
#include <string>
#include "List.h"

using namespace std;

double GetPerformanceCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);
	double freq = double(li.QuadPart) / 1000.0;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart) / freq;
}

int main()
{
	double startTime = GetPerformanceCounter();

	Lista points;
	for (double i = 0;i<1000; i++)
	{
		Point p =
		{
			3 * i,
			3 * i + 1,
			3 * i + 2,
		};
		points.insert(p);
	}
	Point sum{ 0,0,0 };
	for (int i = 0; i < points.size(); i++) 
	{
		Node* temp = points.find(i + 1);
		sum.a += temp->p.a;
		sum.b += temp->p.b;
		sum.c += temp->p.c;
	}
	Node* temp = points.find(100);
	cout<<"100'th record: "<< "x=" << temp->p.a << "y=" << temp->p.b << "z=" << temp->p.c << endl;
	double endTime = GetPerformanceCounter();
	cout << "The operation lasted: " << endTime - startTime << " ms" << endl;
	system("pause");
	return 0;
}