#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include <sstream>
#include "Point.h"
#include "Errors.h"
#include "IFile.h"
#include "BinaryFile.h"
#include "CsvFIle.h"


class FileFactory
{
private:
	FileFactory();																//Constructor

	~FileFactory();																//Destktor

	

public:
	static IFile* OpenFile(std::string path, std::string openMode);				//Method recognizing the type of file to open
};

