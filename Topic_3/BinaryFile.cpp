#include "BinaryFile.h"



BinaryFile::BinaryFile(string path, string openMode)			//Constructor opens the file
{
	if (open_mode(openMode) == 1)file.open(path, std::ios::in | std::ios::binary);
	if (open_mode(openMode) == 2)file.open(path, std::ios::out | std::ios::app | std::ios::binary);
	if (open_mode(openMode) == 3)file.open(path, std::ios::out | std::ios::in | std::ios::app | std::ios::binary);
	if (open_mode(openMode) == OperationNotPermitted)exit(1);
}


BinaryFile::~BinaryFile()			//Destructor closes the file
{
	file.close();
}

int BinaryFile::write(vector<Point>& points)			//Method that writes a vector to a file
{
	if (!file.is_open())return FileClosed;
	file.clear();
	if (file.good())
	{
		for (int i = 0; i < points.size(); i++)
		{
			uint32_t buf = sizeof(Point);
			file.write((const char*)& points[i], buf);
		}
		getsize();
		return Success;
	}
	else return Error;
}

int BinaryFile::read(vector<Point>& points)				//Method that gets a vector from a file
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
			char* temp = new char[sizeof(Point)];
			file.read(temp, sizeof(Point));
			Point* p = (Point*)(temp);
			points.push_back(*p);
			delete p;

		}
		return Success;
	}
	else return Error;
}

int BinaryFile::read(Point & point, int i)				//Method that gets point from file
{
	if (!file.is_open())return FileClosed;
	file.clear();
	if (file.good())
	{
		getsize();
		if (i > size)return OperationNotPermitted;
		file.clear();
		file.seekg((i-1)*sizeof(Point));
		file.read((char*)&point, sizeof(Point));
		return Success;
	}
	else return Error;
}

int BinaryFile::getsize()				//Method checking the length of a vector of points in the file
{
	if (!file.is_open())return FileClosed;
	file.clear();
	if (file.good())
	{
		file.clear();
		file.seekg(0, std::ios_base::end);
		ifstream::pos_type sizef = file.tellg();
		file.seekg(0, std::ios_base::beg);
		size = int(sizef) / sizeof(Point);
		return Success;
	}
	else return Error;
}

int BinaryFile::open_mode(std::string openMode)					//Method that passes the file opening type
{
	if (openMode == "read")return 1;
	if (openMode == "write")return 2;
	if (openMode == "rw")return 3;
	else return OperationNotPermitted;
}
