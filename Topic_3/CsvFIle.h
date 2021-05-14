#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include <sstream>
#include "Point.h"
#include"Errors.h"


class CsvFIle
{
public:
	CsvFIle(std::string path, std::string openMode);					//The constructor opens the file from the given path
																		//Takes a path(string) and file opening type(string):
																		//"read" - reading only, "write" - writing only (writes from the end of the file)
																		//"rw" - reading and writing shifting from the end of the file
																		//If an incorrect opening type is given, the program will terminate its operation

	~CsvFIle();															//Destktor closes the file

	int write(std::vector<Point>& points);								//Method that saves a vector of points to a CSV file, on success the method returns "Success" with the value 0
																		//In case of an attempt to write to a closed file, the method will return an error "FileClosed" with the value 2
																		//In case of an error, the method will return the error "Error" with a value of 3

	int read(std::vector<Point>& points);								//Method reads a vector of points from a CSV file, on success the method returns "Success" with value 0
																		//In case of an attempt to read from a closed file, the method will return an error "FileClosed" with the value 2
																		//In case of an error, the method will return the error "Error" with a value of 3

	int read(Point& point , int i);										//Method reads the given point from the CSV file, on success the method returns "Success" with the value 0
																		//In case of giving a counter that exceeds the number of points in the file, the method will return the error "OperationNotPermitted" with a value of 1
																		//In case of an attempt to read from a closed file, the method will return an error "FileClosed" with the value 2
																		//In case of an error, the method will return the error "Error" with a value of 3


private:
	std::fstream file;													//File variable

	int size = NULL;													//Variable that gives the number of saved points in the file

	int getsize();														//Method checking the number of saved points in the file, in case of success the method returns "Success" with the value 0
																		//In case of checking with no open file, method will return error "FileClosed" with value 2
																		//In case of an error, the method returns "Error" with a value of 3

	int open_mode(std::string openMode);								//Method passes the file opening type
};

