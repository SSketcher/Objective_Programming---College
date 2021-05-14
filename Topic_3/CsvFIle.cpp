#include "CsvFIle.h"



CsvFIle::CsvFIle(std::string path, std::string openMode)		//Constructor opens the file
{
	if (open_mode(openMode) == 1)file.open(path, std::ios::in);
	if (open_mode(openMode) == 2)file.open(path, std::ios::out | std::ios::app);
	if (open_mode(openMode) == 3)file.open(path, std::ios::out | std::ios::in | std::ios::app);
	if (open_mode(openMode) == OperationNotPermitted)exit(1);
}


CsvFIle::~CsvFIle()			//Destructor closes the file
{
	file.close();
}

int CsvFIle::write(std::vector<Point>& points)			//Method that writes a vector to a file
{
	if (!file.is_open())return FileClosed;
	file.clear();
	if (file.good())
	{
		for (int i = 0; i < points.size(); i++)
		{

			file << points[i].x << "," << points[i].y << "," << points[i].z << std::endl;
		}
		getsize();
		return Success;
	}
	else return Error;
}

int CsvFIle::read(std::vector<Point> &points)			//Method that gets a vector from a file
{
	if (!file.is_open())return FileClosed;
	file.clear();
	if (file.good())
	{
		getsize();
		file.clear();
		file.seekg(0, std::ios_base::beg);
		for (int i = 0; i < size; i++)
		{
			Point p;
			char c;
			file >> p.x >> c >> p.y >> c >> p.z;
			points.push_back(p);

		}
		
		return Success;
	}
	else return Error;
}

int CsvFIle::read(Point& point, int x)				//Method that gets point from file
{
	if (!file.is_open())return FileClosed;
	file.clear();
	if (file.good())
	{
		getsize();
		file.clear();
		file.seekg(0, std::ios_base::beg);
		if (x > size)return OperationNotPermitted;
		char c;
		std::string temp;
		for (int i = 0; i < x-1; i++)getline(file,temp);
		file >> point.x >> c >> point.y >> c >> point.z;
		return Success;
	}
	else return Error;
}

int CsvFIle::getsize()				//Method checking the length of a vector of points in the file
{
	if (!file.is_open())return FileClosed;
	file.clear();
	if (file.good())
	{
		file.clear();
		file.seekg(0, std::ios_base::beg);
		std::string line;
		size = 0;
		while (!file.eof())
		{
			getline(file, line);
			if (line != "")
			{
				size++;
			}
		}
		return Success;
	}
	else return Error;
}

int CsvFIle::open_mode(std::string openMode)			//Method that passes the file opening type
{
	if (openMode == "read")return 1;
	if (openMode == "write")return 2;
	if (openMode == "rw")return 3;
	else return OperationNotPermitted;
}
