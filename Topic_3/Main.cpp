#include<iostream>
#include"CsvFIle.h"
#include"BinaryFile.h"
#include <math.h>
#include"Point.h"

using namespace std;

int main()
{
	vector<Point> points;
	for (double i = 0; i < 10; i++)
	{
		Point p =
		{
			i,
			i,
			sin(pow(i,2.0) + pow(i,2.0)),
		};

		points.push_back(p);
	}

	CsvFIle file("test.csv", "rw");
	Point vec;
	file.write(points);		//Writing points to file 
	//file.read(vec, 18);		//Reading points from file
	cout << vec.x << ";" << vec.y << ";" << vec.z << ";" << endl;
	vector<Point> read;
	file.read(read);
	for (int i = 0; i < read.size(); i++)
	{
		cout << read[i].x << " " << read[i].y << " " << read[i].z << endl;
	}

	getchar();

	BinaryFile bin("test.bin", "rw");
	vector<Point> read_bin;
	bin.write(points);		//Writing points to file 
	//bin.read(read_bin);		//Reading points from file
	cout << read_bin.size() << endl;
	for (int i = 0; i < read_bin.size(); i++)
	{
		cout << read_bin[i].x << " " << read_bin[i].y << " " << read_bin[i].z << endl;
	}
	bin.read(vec, 17);
	cout << vec.x << ";" << vec.y << ";" << vec.z << ";" << endl;
	cout << "Succes" << endl;
	getchar();
	return 0;
}