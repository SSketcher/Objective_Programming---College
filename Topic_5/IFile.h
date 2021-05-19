#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include <sstream>
#include "Point.h"
#include"Errors.h"

class IFile			//Virtual class
{
public:				//Purely virtual methods
	virtual int write(std::vector<Point>& points) = 0;

	virtual int read(std::vector<Point>& points) = 0;

	virtual int read(Point& point, int i) = 0;

	
private:
	std::fstream file;

	int size = NULL;

	virtual int getsize() = 0;

	virtual int open_mode(std::string openMode) = 0;
};

