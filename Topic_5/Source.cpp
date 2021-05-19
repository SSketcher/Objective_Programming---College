#include "CsvFile.h"
#include "BinaryFile.h"
#include "Ifile.h"
#include "Point.h"
#include "FileFactory.h"

using namespace std;

int main() 
{
	IFile  *plik = FileFactory::OpenFile("test123.csv", "rw");
	vector<Point> points;
	bool b = true;

	if (b == false) 
	{
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
		plik->write(points);
	}

	if (b == true) 
	{
		plik->read(points);
		for (int i = 0; i < (int)points.size(); i++)
		{
			cout << points[i].x << " " << points[i].y << " " << points[i].z << endl;
		}
	}
	

	system("pause");
	return 0;
}